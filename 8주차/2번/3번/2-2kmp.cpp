#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
int* methodB;
int outputBsize;

using namespace std;

vector <int> makeTable(char* pat, int M)//최대접대부 table을 만들기 위한 함수
{
	vector<int> table(M, 0); //벡터 초기화
	int j = 0;
	for (int i = 1; i < M; i++) {
		while (j > 0 && pat[i] != pat[j]) { //i번째 문자와 j번째 문자가 일치하지 않으면
			j = table[j - 1]; //j-1 뺀 값이 가리키는 인덱스로 이동
		}
		if (pat[i] == pat[j]) //일치하면
			table[i] = ++j; //j에 1 증가한 값 넣음
	}
	return table;
}

void KMPSearch(char* pat, char* txt, int M, int N)
{
	outputBsize = 0;
	vector <int> table = makeTable(pat, M);
	int j = 0;
	methodB = new int[N];
	for (int i = 0; i < N; i++) {
		while (j > 0 && txt[i] != pat[j]) {//일치하지 않을 때는 
			j = table[j - 1]; //바로 이전 단계에 있던 값으로 이동
		}
		if (txt[i] == pat[j]) {//문자가 일치할 때
			if (j == M - 1) {//모두 일치하는 경우
				methodB[outputBsize++] = i - M + 1;
				j = table[j];//테이블에서 j가 가리키는 위치만큼 점프(j값 갱신)
			}
			else { //모두 일치는 아님
				j++; //j를 1 증가
			}
		}
	}
}

int main() {
	int nSIZE = 100000000; //텍스트 스트링 크기
	int mSIZE = 20; //패턴 스트링 크기
	char* textString = new char[nSIZE]; //텍스트 스트링 동적 생성
	ofstream fout;  //쓸 목적의 파일 선언
	srand((unsigned int)time(NULL)); //seed값을 매번 바꾼다
	char dna[4] = { 'A', 'C', 'G','T' };
	fout.open("kinput.txt"); //input 파일 열기
	for (int i = 0; i < nSIZE; i++) {  //nSIZE개의 랜덤 문자열 생성
		int index = rand() % 4; //0~3까지의 랜덤 수
		fout << dna[index]; //A, C, G, T를 랜덤하게 생성해서 텍스트 파일에 쓰기
		textString[i] = dna[index]; //텍스트 스트링에 저장
	}
	fout.close(); //파일 닫기

	char* patternString = new char[mSIZE]; //패턴 스트링 동적 할당
	cout << "패턴은 ";
	for (int i = 0; i < mSIZE; i++) { //크기가 mSIZE인 패턴 스트링 생성
		int index = rand() % 4;
		patternString[i] = dna[index];
		cout << dna[index]; //패턴 출력
	}

	clock_t start = clock(); // 현재 시스템 시각을 t1에 대입
	KMPSearch(patternString, textString, mSIZE, nSIZE); //KMP 알고리즘 함수 호출 
	clock_t end = clock();  // 알고리즘 끝나는 시각을 t1에 대입
	double duration = (double)(end - start); //시각의 차는 시간
	cout << "KMP 알고리즘 수행 시간: " << duration / CLOCKS_PER_SEC << "초";

	ofstream output; //output파일 선언
	output.open("koutput.txt"); //output. 파일 열기
	output << "KMP" << endl;
	for (int j = 0; j < outputBsize; j++) {
		output << methodB[j] << ".  "; //패턴 시작 인덱스 저장
	}
	output.close(); //파일 닫기
}