#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;
int* methodA;
int outputAsize; 

void bruteForce(char T[], char P[], int n, int m) {
	/*입력: T 텍스트 크기가 n인 문자의 배열.
				 P: 패턴 크기가 m인 문자의 배열*/
	int i, j;
	outputAsize = 0;
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
	int nSIZE = 1000000000; //텍스트 스트링 크기
	int mSIZE = 5; //패턴 스트링 크기

	char* textString = new char[nSIZE]; //텍스트 스트링 동적 할당
	ofstream fout; //binput 쓸 목적의 파일 선언
	srand((unsigned int)time(NULL)); //seed 값 매번 바꾸기
	char dna[4] = { 'A', 'C', 'G','T' }; 
	fout.open("binput.txt"); //binput파일 열기

	for (int i = 0; i < nSIZE; i++) { //크기가 nSIZE인 텍스트 스트링 생성
		int index = rand() % 4;
		fout << dna[index]; //binput파일에 쓰기
		textString[i] = dna[index]; //스트링 저장
	}
	fout.close();

	char* patternString = new char[mSIZE]; //패턴 스트링 동적 할당
	cout << "패턴은 ";
	for (int i = 0; i < mSIZE; i++) { //크기가 mSIZE인 패턴 스트링 생성
		int index = rand() % 4;
		patternString[i] = dna[index];
		cout << dna[index]; //패턴 출력
	}

	cout << patternString[0];
	cout << endl;
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