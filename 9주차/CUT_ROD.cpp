// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 9주차 과제
// 2번- CUR_ROD(brute-force).cpp
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int CUT_ROD(int p[], int n) { //하향식 재귀
	if (n == 0) //n==0이면 수익이 없으므로 0 리턴
		return 0;
	int q = -INF; //최대 수익을 -inf로 초기화
	for (int i = 0; i < n; i++) { //재귀함수 호출
		q = max(q, p[i] + CUT_ROD(p, n - 1-i));
	}
	return q; //r_n반환
}

int main() {
	int p[10] = { 1,5,8,9,10,17,17,20,24,30 };  //길이에 따른 가격 배열
	for (int i = 1; i <= 10; i++) { //길이에 따른 최대 수익 출력
		cout << "길이가 " << i << "일 때 최대 수익은 " << CUT_ROD(p, i)<<endl;
	}
}