// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 프로젝트
// 2번 알고리즘
// 2018112008 김균호
// -----------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <time.h>
#include <chrono>
#include<sstream>
using namespace std;
//x,y좌표 구조체
struct Point2 {
	double x;
	double y;
};

Point2 arr[100001];
//수업시간 응용
int dir(Point2 A, Point2 B, Point2 C) {
	double dxAB, dxAC, dyAB, dyAC, Dir;
	dxAB = B.x - A.x;
	dyAB = B.y - A.y;
	dxAC = C.x - A.x;
	dyAC = C.y - A.x;

	//시계 방향인경우
	if (dxAB * dyAC < dyAB * dxAC) {
		Dir = 1;
	}
	//반시계 방향인경우
	if (dxAB * dyAC > dyAB * dxAC) {
		Dir = -1;
	}
	//일직선인 경우 
	if (dxAB * dyAC == dyAB * dxAC) {
		//AB가 같은 점인 경우
		Dir = 0;
	}

	return Dir;

}
//기울기 반환
double tmp(Point2 A, Point2 B) {
	return ((A.y - B.y) / (A.x - B.x));
}
//거리 반환
double dist(Point2 a, Point2 b)
{
	//유클리드 거리를 반환한다.
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
//x좌표 기준 순서대로 정렬, x좌표가 같을일은 없지만 같다면 y좌표 기준 오름차순 정렬
bool comp(Point2 A, Point2 B) {
	return A.x == B.x ? A.y < B.y : A.x < B.x;
}
//첫 시작 좌표를 기준으로, 기울기가 가장 작은 것부터 오름차순 정렬
bool cmp(Point2 A, Point2 B) {
	return tmp(arr[0], A) < tmp(arr[0],B);
}
//string: 지하철 역 이름, subway_info->second.first: 위도 subway_info->second.second: 경도
map < string,pair<double, double>> subway_info;

int main() {
	//파일 처리, 한 줄씩 공백을 기준으로 받는다.
	clock_t start_time, finish_time;
	double total_time;
	ifstream rf;
	int t = 0;
	rf.open("subway_location1.txt");
	if (rf.is_open()) {
		string subway_station;
		string subway_latitude;
		string subway_longitude;
		for (int i = 0; i < 636; i++) {
		//ifstream 형식으로 입력받기
			rf >> subway_station;
			rf >> subway_latitude;
			rf >> subway_longitude;
			//cout << subway_station << " " << subway_latitude << " " << subway_longitude << endl;
			subway_info.insert(pair<string, pair<double, double>>(subway_station+"역", make_pair(stod(subway_latitude), stod(subway_longitude))));
		}
		rf.close();
	}
	//입력 파일로부터 받은 사람들의 지하철 역 목록
	//k=0~12는 input file 50~600일때의 결과를 모두 출력하기 위한 반복문이다.
	for (int k = 0; k < 12; k++) {
		string abc = to_string((k + 1) * 50);
		int stk[100001];
		int top = 0;
		//N_person:input 파일로부터 불러들어온 역 이름과 위도 경도 정보
		map<string, pair<double, double>> N_person;
		string a = "input";
		string zz = a + abc + ".txt";
		rf.open(a+abc+".txt");
		if (rf.is_open()) {
			while (!rf.eof()) {
				string str;
				getline(rf, str);
				auto k = subway_info.find(str);
				if (k != subway_info.end()) {
					N_person.insert(pair<string, pair<double, double>>(k->first, make_pair(k->second.first, k->second.second)));
					t++;
				}
			}
			rf.close();
		}
		auto s1 = chrono::steady_clock::now();
		start_time = clock();
		int j = 0;
		//map->Point 구조체 배열로 자료 변환하여 arr배열에 저장
		for (auto i = N_person.begin(); i != N_person.end(); i++) {
			Point2 p;
			p.x = i->second.first;
			p.y = i->second.second;
			arr[j] = p;
			j++;
		}
		//첫번째 정렬: x좌표 기준 정렬, 같다면 y좌표 기준 정렬
	
		sort(arr, arr + j, comp);
		//두번째 정렬, 첫 좌표를 기준으로 기울기 오름차순 정렬
		sort(arr + 1, arr + j, cmp);

		//중심 좌표
		double x = 0;
		double y = 0;

		//첫 좌표, 두번째 좌표 push
		stk[top++] = 0;
		stk[top++] = 1;
		int n = 2;

		for (int i = 2; i < j; i++) {
			//top>=2: 해당 알고리즘은 최소 스택에 2개이상의 원소가 있어야 한다.
			//dir(arr[stk[top - 2]], arr[stk[top - 1]], arr[i]) >= 0: 현재 스택 내 있는 선분과 다음 선분이 시계 방향이거나 일직선일시 pop.
			while (top >= 2 && dir(arr[stk[top - 2]], arr[stk[top - 1]], arr[i]) >= 0) {
				top--;

			}
			//반 시계 방향인 경우 스택에 push한다.
			stk[top++] = i;
		}
		double tp_dist = 0;
		Point2 tp;
		Point2 az;
		//스택에 있는 좌표가 볼록껍질 좌표다.
		for (int i = 0; i < top; i++) {

			x += arr[stk[i]].x;
			y += arr[stk[i]].y;
		}
		//중심 좌표를 구한다.
		az.x = x / top;
		az.y = y / top;
		//비교를 위해 첫번째 지하철 역과의 거리를 구한다.
		tp.x = subway_info.begin()->second.first;
		tp.y = subway_info.begin()->second.second;
		tp_dist = dist(az, tp);
		//중심 좌표와 모든 지하철 역의 거리를 구한다.
		string result;
		for (auto i = subway_info.begin(); i != subway_info.end(); i++) {
			tp.x = i->second.first;
			tp.y = i->second.second;
			if (tp_dist > dist(az, tp)) {
				tp_dist = dist(az, tp);
				result = i->first;

			}
		}
		//결과를 출력한다.
		cout << "[input " << abc << " ]" << endl;
		cout << "두 번째 알고리즘을 이용해 구한 중간 지점 역은 " << result <<" 입니다." << endl;
		//cout << subway_info.find(result)->second.first << " " << subway_info.find(result)->second.second << endl;
		finish_time = clock();
		auto end = chrono::steady_clock::now();
	}

	return 0;
}