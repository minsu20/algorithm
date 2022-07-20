#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
int* methodB;
int outputBsize;

using namespace std;

vector <int> makeTable(char* pat, int M)//�ִ������ table�� ����� ���� �Լ�
{
	vector<int> table(M, 0); //���� �ʱ�ȭ
	int j = 0;
	for (int i = 1; i < M; i++) {
		while (j > 0 && pat[i] != pat[j]) { //i��° ���ڿ� j��° ���ڰ� ��ġ���� ������
			j = table[j - 1]; //j-1 �� ���� ����Ű�� �ε����� �̵�
		}
		if (pat[i] == pat[j]) //��ġ�ϸ�
			table[i] = ++j; //j�� 1 ������ �� ����
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
		while (j > 0 && txt[i] != pat[j]) {//��ġ���� ���� ���� 
			j = table[j - 1]; //�ٷ� ���� �ܰ迡 �ִ� ������ �̵�
		}
		if (txt[i] == pat[j]) {//���ڰ� ��ġ�� ��
			if (j == M - 1) {//��� ��ġ�ϴ� ���
				methodB[outputBsize++] = i - M + 1;
				j = table[j];//���̺��� j�� ����Ű�� ��ġ��ŭ ����(j�� ����)
			}
			else { //��� ��ġ�� �ƴ�
				j++; //j�� 1 ����
			}
		}
	}
}

int main() {
	int nSIZE = 100000000; //�ؽ�Ʈ ��Ʈ�� ũ��
	int mSIZE = 20; //���� ��Ʈ�� ũ��
	char* textString = new char[nSIZE]; //�ؽ�Ʈ ��Ʈ�� ���� ����
	ofstream fout;  //�� ������ ���� ����
	srand((unsigned int)time(NULL)); //seed���� �Ź� �ٲ۴�
	char dna[4] = { 'A', 'C', 'G','T' };
	fout.open("kinput.txt"); //input ���� ����
	for (int i = 0; i < nSIZE; i++) {  //nSIZE���� ���� ���ڿ� ����
		int index = rand() % 4; //0~3������ ���� ��
		fout << dna[index]; //A, C, G, T�� �����ϰ� �����ؼ� �ؽ�Ʈ ���Ͽ� ����
		textString[i] = dna[index]; //�ؽ�Ʈ ��Ʈ���� ����
	}
	fout.close(); //���� �ݱ�

	char* patternString = new char[mSIZE]; //���� ��Ʈ�� ���� �Ҵ�
	cout << "������ ";
	for (int i = 0; i < mSIZE; i++) { //ũ�Ⱑ mSIZE�� ���� ��Ʈ�� ����
		int index = rand() % 4;
		patternString[i] = dna[index];
		cout << dna[index]; //���� ���
	}

	clock_t start = clock(); // ���� �ý��� �ð��� t1�� ����
	KMPSearch(patternString, textString, mSIZE, nSIZE); //KMP �˰��� �Լ� ȣ�� 
	clock_t end = clock();  // �˰��� ������ �ð��� t1�� ����
	double duration = (double)(end - start); //�ð��� ���� �ð�
	cout << "KMP �˰��� ���� �ð�: " << duration / CLOCKS_PER_SEC << "��";

	ofstream output; //output���� ����
	output.open("koutput.txt"); //output. ���� ����
	output << "KMP" << endl;
	for (int j = 0; j < outputBsize; j++) {
		output << methodB[j] << ".  "; //���� ���� �ε��� ����
	}
	output.close(); //���� �ݱ�
}