// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 8주차 과제
// 1번- rabinKarp.cpp
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void RKsearch(char T[], char P[], int d, int q, int N, int M)
{
	/*입력 T: 크기가 N인 문자열 
	 P: 크기가 M인 패턴
	 d: 알파벳의 크기
	 q: 해시 함수에 의해 결정*/
	int i, j, s;
	int p = 0; // 패턴의 hash 값  
	int t = 0; // 텍스트의 hash 값  
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q; //d^(m-1)modq 값 사전 계산


	for (i = 0; i <= M-1; i++)
	{
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
	}//호너 방법을 통한  p, t 계산

	for (s = 0; s < N - M+1; s++) //텍스트 각 위치 별로 패턴 매칭
	{
		if (p == t)//해시 값이 동일한 경우에 한해 세부 패턴 매칭 진행
		{

			for (i = 0; i < M; i++)
			{
				if (T[i + s] != P[i])
					break;
			}//문자를 하나씩 비교를 해줍니다.

			if (i== M)
				cout << "패턴이 텍스트의 " << s << "번째부터 나타남" << endl;
		}

		if (s < N - M)
		{
			t = (d * (t - T[s] * h) + T[s + M]) % q; //t_s와 t_s+1사이 관계를 이용한 점화식을 통해 다음 t값 계산

			if (t < 0)
				t = (t + q);
		}// 다음 텍스트의 hash 값을 구해줍니다.
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

	RKsearch(tS, pS, 36, 101, tSlength, pSlength);
	/*36을 넣은 것은 알파벳과 0~9까지 수의 합인 36을 알파벳의 크기로 정함
	그리고 q를 101으로 한 것은 최대 소수를 위해*/

}