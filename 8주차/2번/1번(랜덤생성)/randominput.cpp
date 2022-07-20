// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 8주차 과제
// 2번- randominput.cpp
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int main() {
	ofstream fout;//쓸 목적의 파일 선언
	srand((unsigned int)time(NULL)); //seed값을 매번 바꾼다
	char dna[4] = { 'A', 'C', 'G','T' };
	fout.open("input.txt"); //파일 열기, 만약에 없으면 생성 후 열기
	for (int i = 0; i < 10000000; i++) { //10000,000개의 문자 생성
		int index = rand() % 4; //0~3까지의 랜덤 수
		fout << dna[index]; //A, C, G, T를 랜덤하게 생성해서 텍스트 파일에 쓰기
	}
	fout.close(); //파일 닫기
}