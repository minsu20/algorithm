// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 8���� ����
// 2��- randominput.cpp
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int main() {
	ofstream fout;//�� ������ ���� ����
	srand((unsigned int)time(NULL)); //seed���� �Ź� �ٲ۴�
	char dna[4] = { 'A', 'C', 'G','T' };
	fout.open("input.txt"); //���� ����, ���࿡ ������ ���� �� ����
	for (int i = 0; i < 10000000; i++) { //10000,000���� ���� ����
		int index = rand() % 4; //0~3������ ���� ��
		fout << dna[index]; //A, C, G, T�� �����ϰ� �����ؼ� �ؽ�Ʈ ���Ͽ� ����
	}
	fout.close(); //���� �ݱ�
}