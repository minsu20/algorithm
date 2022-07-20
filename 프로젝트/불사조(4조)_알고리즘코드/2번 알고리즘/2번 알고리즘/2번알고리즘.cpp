// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// ������Ʈ
// 2�� �˰���
// 2018112008 ���ȣ
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
//x,y��ǥ ����ü
struct Point2 {
	double x;
	double y;
};

Point2 arr[100001];
//�����ð� ����
int dir(Point2 A, Point2 B, Point2 C) {
	double dxAB, dxAC, dyAB, dyAC, Dir;
	dxAB = B.x - A.x;
	dyAB = B.y - A.y;
	dxAC = C.x - A.x;
	dyAC = C.y - A.x;

	//�ð� �����ΰ��
	if (dxAB * dyAC < dyAB * dxAC) {
		Dir = 1;
	}
	//�ݽð� �����ΰ��
	if (dxAB * dyAC > dyAB * dxAC) {
		Dir = -1;
	}
	//�������� ��� 
	if (dxAB * dyAC == dyAB * dxAC) {
		//AB�� ���� ���� ���
		Dir = 0;
	}

	return Dir;

}
//���� ��ȯ
double tmp(Point2 A, Point2 B) {
	return ((A.y - B.y) / (A.x - B.x));
}
//�Ÿ� ��ȯ
double dist(Point2 a, Point2 b)
{
	//��Ŭ���� �Ÿ��� ��ȯ�Ѵ�.
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
//x��ǥ ���� ������� ����, x��ǥ�� �������� ������ ���ٸ� y��ǥ ���� �������� ����
bool comp(Point2 A, Point2 B) {
	return A.x == B.x ? A.y < B.y : A.x < B.x;
}
//ù ���� ��ǥ�� ��������, ���Ⱑ ���� ���� �ͺ��� �������� ����
bool cmp(Point2 A, Point2 B) {
	return tmp(arr[0], A) < tmp(arr[0],B);
}
//string: ����ö �� �̸�, subway_info->second.first: ���� subway_info->second.second: �浵
map < string,pair<double, double>> subway_info;

int main() {
	//���� ó��, �� �پ� ������ �������� �޴´�.
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
		//ifstream �������� �Է¹ޱ�
			rf >> subway_station;
			rf >> subway_latitude;
			rf >> subway_longitude;
			//cout << subway_station << " " << subway_latitude << " " << subway_longitude << endl;
			subway_info.insert(pair<string, pair<double, double>>(subway_station+"��", make_pair(stod(subway_latitude), stod(subway_longitude))));
		}
		rf.close();
	}
	//�Է� ���Ϸκ��� ���� ������� ����ö �� ���
	//k=0~12�� input file 50~600�϶��� ����� ��� ����ϱ� ���� �ݺ����̴�.
	for (int k = 0; k < 12; k++) {
		string abc = to_string((k + 1) * 50);
		int stk[100001];
		int top = 0;
		//N_person:input ���Ϸκ��� �ҷ����� �� �̸��� ���� �浵 ����
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
		//map->Point ����ü �迭�� �ڷ� ��ȯ�Ͽ� arr�迭�� ����
		for (auto i = N_person.begin(); i != N_person.end(); i++) {
			Point2 p;
			p.x = i->second.first;
			p.y = i->second.second;
			arr[j] = p;
			j++;
		}
		//ù��° ����: x��ǥ ���� ����, ���ٸ� y��ǥ ���� ����
	
		sort(arr, arr + j, comp);
		//�ι�° ����, ù ��ǥ�� �������� ���� �������� ����
		sort(arr + 1, arr + j, cmp);

		//�߽� ��ǥ
		double x = 0;
		double y = 0;

		//ù ��ǥ, �ι�° ��ǥ push
		stk[top++] = 0;
		stk[top++] = 1;
		int n = 2;

		for (int i = 2; i < j; i++) {
			//top>=2: �ش� �˰����� �ּ� ���ÿ� 2���̻��� ���Ұ� �־�� �Ѵ�.
			//dir(arr[stk[top - 2]], arr[stk[top - 1]], arr[i]) >= 0: ���� ���� �� �ִ� ���а� ���� ������ �ð� �����̰ų� �������Ͻ� pop.
			while (top >= 2 && dir(arr[stk[top - 2]], arr[stk[top - 1]], arr[i]) >= 0) {
				top--;

			}
			//�� �ð� ������ ��� ���ÿ� push�Ѵ�.
			stk[top++] = i;
		}
		double tp_dist = 0;
		Point2 tp;
		Point2 az;
		//���ÿ� �ִ� ��ǥ�� ���ϲ��� ��ǥ��.
		for (int i = 0; i < top; i++) {

			x += arr[stk[i]].x;
			y += arr[stk[i]].y;
		}
		//�߽� ��ǥ�� ���Ѵ�.
		az.x = x / top;
		az.y = y / top;
		//�񱳸� ���� ù��° ����ö ������ �Ÿ��� ���Ѵ�.
		tp.x = subway_info.begin()->second.first;
		tp.y = subway_info.begin()->second.second;
		tp_dist = dist(az, tp);
		//�߽� ��ǥ�� ��� ����ö ���� �Ÿ��� ���Ѵ�.
		string result;
		for (auto i = subway_info.begin(); i != subway_info.end(); i++) {
			tp.x = i->second.first;
			tp.y = i->second.second;
			if (tp_dist > dist(az, tp)) {
				tp_dist = dist(az, tp);
				result = i->first;

			}
		}
		//����� ����Ѵ�.
		cout << "[input " << abc << " ]" << endl;
		cout << "�� ��° �˰����� �̿��� ���� �߰� ���� ���� " << result <<" �Դϴ�." << endl;
		//cout << subway_info.find(result)->second.first << " " << subway_info.find(result)->second.second << endl;
		finish_time = clock();
		auto end = chrono::steady_clock::now();
	}

	return 0;
}