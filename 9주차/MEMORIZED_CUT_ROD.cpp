// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 9주차 과제
// 2번- MEMORIZED_CUR_ROD(하향식 동적 프로그래밍).cpp
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#define INF 987654321 
using namespace std;

int MEMORIZED_CUT_ROD_AUX(int p[], int n, int r[]) {  //CUT-ROD에 메모하기가 더해짐
	int q = -INF;  //값 초기화
	if (r[n] >= 0) //원하는 값이 이미 계산되었는지 확인
		return r[n]; //이미 계산되었으면 해당값을 리턴
	
	if (n == 0) 
		return 0;

	else { //계산되어 있지 않은 경우
		for (int i = 1; i <= n; i++) { //재귀 함수 호출
			q = max(q, p[i-1] + MEMORIZED_CUT_ROD_AUX(p, n - i, r));
		}
	}
	r[n] = q; //계산한 값을 r[n]에 저장
	return q; //그 값을 반환
}

int MEMORIZED_CUT_ROD(int p[], int n) { //하향식 동적 프로그래밍
	int* r = new int[n + 1]; //새로운 배열로 선언 
	for (int i = 0; i < n; i++) {
		r[i] = -INF; //아직 모르는 값이 -INF로 초기화
	}
	return MEMORIZED_CUT_ROD_AUX(p, n, r); //함수 호출
}

int main() {
	int p[10] = { 1,5,8,9,10,17,17,20,24,30 }; //길이에 따른 가격 배열
	for (int i = 1; i <= 10; i++) { //길이에 따른 최대 수익 출력
		cout << "길이가 " << i << "일 때 최대 수익은 " << MEMORIZED_CUT_ROD(p, i) << endl;
	}
}