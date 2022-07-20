// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 8주차 과제
// 1번- bruteForce.cpp
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void bruteForce(char T[], char P[], int n, int m) {
	/*입력: T 텍스트 크기가 n인 문자의 배열. 
	             P: 패턴 크기가 m인 문자의 배열*/
	int i, j;
	for (i = 0; i <= n - m; i++) { //n-m인 이유는 부분 스트링이 패턴과 일치하는지 찾기 때문
		for (j = 0; j < m; j++) {//패턴스트링과 텍스트스트링을 하나씩 비교한다
			if (P[j] != T[i + j]) //하나라도 틀리면
				break; //멈춘다
		}
		if (j == m) { //텍스트의 부분 스트링이 패턴스트링과 일치
			cout << "패턴이 텍스트의 " << i << "번째부터 나타납니다." << endl;
		}
	}
}

int main() {
	string textString, patternString;
	char tS[200];
	char pS[10];

	cout << "Text String: ";
	getline(cin, textString); //텍스트를 입력받는다

	cout << "Pattern String: ";
	getline(cin, patternString); //패턴을 입력받는다

	int tSlength = textString.length(); //tSlength는 textString의 크기
	strcpy_s(tS, textString.c_str()); //string->char
	int pSlength = patternString.length(); //pSlength는 patternString의 크기
	strcpy_s(pS, patternString.c_str()); //string->char

	clock_t t1 = clock(); // 현재 시스템 시각을 t1에 대입
	bruteForce(tS, pS, tSlength, pSlength);
	clock_t t2 = clock(); // 알고리즘 끝나는 시각을 t1에 대입
	double duration = (double)(t2 - t1); //시각의 차는 시간
	cout << "알고리즘 수행 시간: " << duration / CLOCKS_PER_SEC << "초";
}