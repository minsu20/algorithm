// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 8���� ����
// 2��- 2-1bruteForce.cpp
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;
int* methodA;
int outputAsize = 0;

void bruteForce(char T[], char P[], int n, int m) {
	/*�Է�: T �ؽ�Ʈ ũ�Ⱑ n�� ������ �迭.
				 P: ���� ũ�Ⱑ m�� ������ �迭*/
	int i, j;
	methodA = new int[n];
	for (i = 0; i <= n - m; i++) { //n-m�� ������ �κ� ��Ʈ���� ���ϰ� ��ġ�ϴ��� ã�� ����
		for (j = 0; j < m; j++) {//���Ͻ�Ʈ���� �ؽ�Ʈ��Ʈ���� �ϳ��� ���Ѵ�
			if (P[j] != T[i + j]) //�ϳ��� Ʋ����
				break; //�����
		}
		if (j == m) {// �ؽ�Ʈ�� �κ� ��Ʈ���� ���Ͻ�Ʈ���� ��ġ
			methodA[outputAsize++] = i;
		}
	}
}



int main() {
	int nSIZE = 100000; //�������� n ������
	int mSIZE = 5; //���� ������
	char* textString = new char[nSIZE]; //�ؽ�Ʈ ��Ʈ�� ���� ����
	ofstream fout;  //�� ������ ���� ����
	srand((unsigned int)time(NULL)); //seed���� �Ź� �ٲ۴�
	char dna[4] = { 'A', 'C', 'G','T' };
	fout.open("binput.txt"); //input ���� ����
	for (int i = 0; i < nSIZE; i++) {  //nSIZE���� ���� ���ڿ� ����
		int index = rand() % 4; //0~3������ ���� ��
		fout << dna[index]; //A, C, G, T�� �����ϰ� �����ؼ� �ؽ�Ʈ ���Ͽ� ����
		textString[i] = dna[index]; //�ؽ�Ʈ ��Ʈ���� ����
	}
	fout.close(); //���� �ݱ�

	char patternString[8] = { 'A','C','C','G','T','A','T' }; //���� ��Ʈ��
	clock_t start = clock(); // ���� �ý��� �ð��� t1�� ����
	bruteForce(textString, patternString, nSIZE, mSIZE); //bruteForce �˰��� �Լ� ȣ��
	clock_t end = clock(); // ������ �ð��� t2�� ����
	double duration = (double)(end - start); //�ð��� ���� �ð�
	cout << "bruteForce �˰��� ���� �ð�: " << duration / CLOCKS_PER_SEC << "��" << endl;

	ofstream output; //output���� ����
	output.open("boutput.txt");  //output. ���� ����
	output << "bruteForce" << endl;
	for (int i = 0; i < outputAsize; i++) {
		output << methodA[i] << ".  "; //���� ���� �ε��� ����
	}
	output.close();  //���� �ݱ�
}