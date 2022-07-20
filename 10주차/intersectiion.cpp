// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 10주차 과제
// 1번- Intersection.cpp
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
using namespace std;

struct point { //점 구조체
	float x; //x좌표
	float y; //y좌표
};

struct line { //선분 구조체
	struct point first; //첫 번째 점
	struct point second; //두 번째 점
};

int Direction(struct point A, struct point B, struct point C) {
	//세 점 A,B,C가 주어졌을 때 꺾은 선 ABC의 방향을 결정하는 함수
	int dxAB = 0, dxAC = 0 , dyAB = 0, dyAC = 0 , Dir = 0;
	dxAB = B.x - A.x;
	dyAB = B.y - A.y;
	dxAC = C.x - A.x;
	dyAC = C.y - A.y;

	if (dxAB * dyAC == dyAB * dxAC) //일직선 상에 있을 때
	{
		if (dxAB == 0 && dyAB == 0) //A==B인 경우
			Dir = 0;
		if ((dxAB * dxAC < 0) || (dyAB * dyAC < 0)) //A가 가운데에 있는경우
			Dir = -1;
		else if ((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC)) //C가 가운데에 있는 경우 
			Dir = 0;
		else //B가 가운데에 있는 경우
			Dir = 1;
	}
	else { //일직선 상에 있지 않을 때 꺾은선 ABC의 방향이
		if (dxAB * dyAC < dyAB * dxAC) //시계방항인 경우 AB기울기 > AC 기울기
			Dir = 1;
		if (dxAB * dyAC > dyAB * dxAC) //반시계방향인 경우 AB기울기 < AC기울기
			Dir = -1;
	}
	return Dir;
}

int Intersection(struct line AB, struct line CD) { 
	/*입력: AB, CD: 교차 상태를 검사할 두 선분
	   출력: AB와 CD가 서로 교차하면 1, 아니면 0*/
	int LineCrossing;
	if ((Direction(AB.first, AB.second, CD.first) * Direction(AB.first, AB.second, CD.second) <= 0) &&
		(Direction(CD.first, CD.second, AB.first) * Direction(CD.first, CD.second, AB.second) <= 0)) //이 두 조건이 만족할 때 선분이 교차
		LineCrossing = 1; //참
	else
		LineCrossing = 0; //거짓
	return LineCrossing;
}

int main() {
	struct line AB, CD;
	cout << "선분 AB와 선분 CD가 교차하는지 알려줍니다." << endl;
	cout << "각 점의 x좌표와 y좌표를 입력해주세요. " << endl;
	//각 점의 좌표 입력받기
	cout << "A의 x좌표: ";
	cin >> AB.first.x;
	cout << "A의 y좌표: ";
	cin >> AB.first.y;
	cout << "B의 x좌표: ";
	cin >> AB.second.x;
	cout << "B의 y표: ";
	cin >> AB.second.y;

	cout << "C의 x좌표: ";
	cin >> CD.first.x;
	cout << "C의 y좌표: ";
	cin >> CD.first.y;
	cout << "D의 x좌표: ";
	cin >> CD.second.x;
	cout << "D의 y표: ";
	cin >> CD.second.y;
	cout << "선분 AB와 CD는 ";

	if (Intersection(AB, CD) == 1)
		cout << "교차합니다."; //결과값이 1이면 교차합니다 출력

	else
		cout << "교차하지 않습니다. "; //결과값이 0이면 교차하지 않습니다 출력
}