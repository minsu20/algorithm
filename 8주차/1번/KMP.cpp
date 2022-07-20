// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 8주차 과제
// 1번- KMP.cpp
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

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
	vector <int> table = makeTable(pat, M);
	int j = 0;
	for (int i = 0; i < N; i++) {
		while(j > 0 && txt[i] != pat[j]) {//일치하지 않을 때는 
			j = table[j - 1]; //바로 이전 단계에 있던 값으로 이동
		}
		if (txt[i] == pat[j]) {//문자가 일치할 때
			if (j == M - 1) {//모두 일치하는 경우
				cout <<"패턴이 텍스트의 "<< i - M + 1<< "번째 부터 나타남" << endl;
				j = table[j];//테이블에서 j가 가리키는 위치만큼 점프(j값 갱신)
			}
			else { //모두 일치는 아님
				j++; //j를 1 증가
			}
		}
	}
}

int main() {
	string textString, patternString;
	char tS[200];
	char pS[10];

	cout << "Text String: ";
	getline(cin, textString);

	cout << "Pattern String: ";
	getline(cin, patternString);

	int tSlength = textString.length();
	strcpy_s(tS, textString.c_str());
	int pSlength = patternString.length();
	strcpy_s(pS, patternString.c_str());

	clock_t t1 = clock(); // 현재 시스템 시각을 t1에 대입
	KMPSearch(pS, tS, pSlength, tSlength);
	clock_t t2 = clock(); // 알고리즘 끝나는 시각을 t1에 대입
	double duration = (double)(t2 - t1); //시각의 차는 시간
	cout << "알고리즘 수행 시간: " << duration / CLOCKS_PER_SEC << "초";
}