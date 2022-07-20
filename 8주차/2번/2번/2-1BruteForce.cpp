// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 8주차 과제
// 2번- 2-1bruteForce.cpp
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;
int* methodA;
int outputAsize = 0;

void bruteForce(char T[], char P[], int n, int m) {
	/*입력: T 텍스트 크기가 n인 문자의 배열.
				 P: 패턴 크기가 m인 문자의 배열*/
	int i, j;
	methodA = new int[n];
	for (i = 0; i <= n - m; i++) { //n-m인 이유는 부분 스트링이 패턴과 일치하는지 찾기 때문
		for (j = 0; j < m; j++) {//패턴스트링과 텍스트스트링을 하나씩 비교한다
			if (P[j] != T[i + j]) //하나라도 틀리면
				break; //멈춘다
		}
		if (j == m) {// 텍스트의 부분 스트링이 패턴스트링과 일치
			methodA[outputAsize++] = i;
		}
	}
}



int main() {
	int nSIZE = 100000; //랜덤생성 n 사이즈
	int mSIZE = 5; //패턴 사이즈
	char* textString = new char[nSIZE]; //텍스트 스트링 동적 생성
	ofstream fout;  //쓸 목적의 파일 선언
	srand((unsigned int)time(NULL)); //seed값을 매번 바꾼다
	char dna[4] = { 'A', 'C', 'G','T' };
	fout.open("binput.txt"); //input 파일 열기
	for (int i = 0; i < nSIZE; i++) {  //nSIZE개의 랜덤 문자열 생성
		int index = rand() % 4; //0~3까지의 랜덤 수
		fout << dna[index]; //A, C, G, T를 랜덤하게 생성해서 텍스트 파일에 쓰기
		textString[i] = dna[index]; //텍스트 스트링에 저장
	}
	fout.close(); //파일 닫기

	char patternString[8] = { 'A','C','C','G','T','A','T' }; //패턴 스트링
	clock_t start = clock(); // 현재 시스템 시각을 t1에 대입
	bruteForce(textString, patternString, nSIZE, mSIZE); //bruteForce 알고리즘 함수 호출
	clock_t end = clock(); // 끝나는 시각을 t2에 대입
	double duration = (double)(end - start); //시각의 차는 시간
	cout << "bruteForce 알고리즘 수행 시간: " << duration / CLOCKS_PER_SEC << "초" << endl;

	ofstream output; //output파일 선언
	output.open("boutput.txt");  //output. 파일 열기
	output << "bruteForce" << endl;
	for (int i = 0; i < outputAsize; i++) {
		output << methodA[i] << ".  "; //패턴 시작 인덱스 저장
	}
	output.close();  //파일 닫기
}