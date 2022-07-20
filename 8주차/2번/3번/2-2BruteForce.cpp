#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;
int* methodA;
int outputAsize; 

void bruteForce(char T[], char P[], int n, int m) {
	/*�Է�: T �ؽ�Ʈ ũ�Ⱑ n�� ������ �迭.
				 P: ���� ũ�Ⱑ m�� ������ �迭*/
	int i, j;
	outputAsize = 0;
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
	int nSIZE = 1000000000; //�ؽ�Ʈ ��Ʈ�� ũ��
	int mSIZE = 5; //���� ��Ʈ�� ũ��

	char* textString = new char[nSIZE]; //�ؽ�Ʈ ��Ʈ�� ���� �Ҵ�
	ofstream fout; //binput �� ������ ���� ����
	srand((unsigned int)time(NULL)); //seed �� �Ź� �ٲٱ�
	char dna[4] = { 'A', 'C', 'G','T' }; 
	fout.open("binput.txt"); //binput���� ����

	for (int i = 0; i < nSIZE; i++) { //ũ�Ⱑ nSIZE�� �ؽ�Ʈ ��Ʈ�� ����
		int index = rand() % 4;
		fout << dna[index]; //binput���Ͽ� ����
		textString[i] = dna[index]; //��Ʈ�� ����
	}
	fout.close();

	char* patternString = new char[mSIZE]; //���� ��Ʈ�� ���� �Ҵ�
	cout << "������ ";
	for (int i = 0; i < mSIZE; i++) { //ũ�Ⱑ mSIZE�� ���� ��Ʈ�� ����
		int index = rand() % 4;
		patternString[i] = dna[index];
		cout << dna[index]; //���� ���
	}

	cout << patternString[0];
	cout << endl;
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