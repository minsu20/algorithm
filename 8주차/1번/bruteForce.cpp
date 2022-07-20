// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 8���� ����
// 1��- bruteForce.cpp
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void bruteForce(char T[], char P[], int n, int m) {
	/*�Է�: T �ؽ�Ʈ ũ�Ⱑ n�� ������ �迭. 
	             P: ���� ũ�Ⱑ m�� ������ �迭*/
	int i, j;
	for (i = 0; i <= n - m; i++) { //n-m�� ������ �κ� ��Ʈ���� ���ϰ� ��ġ�ϴ��� ã�� ����
		for (j = 0; j < m; j++) {//���Ͻ�Ʈ���� �ؽ�Ʈ��Ʈ���� �ϳ��� ���Ѵ�
			if (P[j] != T[i + j]) //�ϳ��� Ʋ����
				break; //�����
		}
		if (j == m) { //�ؽ�Ʈ�� �κ� ��Ʈ���� ���Ͻ�Ʈ���� ��ġ
			cout << "������ �ؽ�Ʈ�� " << i << "��°���� ��Ÿ���ϴ�." << endl;
		}
	}
}

int main() {
	string textString, patternString;
	char tS[200];
	char pS[10];

	cout << "Text String: ";
	getline(cin, textString); //�ؽ�Ʈ�� �Է¹޴´�

	cout << "Pattern String: ";
	getline(cin, patternString); //������ �Է¹޴´�

	int tSlength = textString.length(); //tSlength�� textString�� ũ��
	strcpy_s(tS, textString.c_str()); //string->char
	int pSlength = patternString.length(); //pSlength�� patternString�� ũ��
	strcpy_s(pS, patternString.c_str()); //string->char

	clock_t t1 = clock(); // ���� �ý��� �ð��� t1�� ����
	bruteForce(tS, pS, tSlength, pSlength);
	clock_t t2 = clock(); // �˰��� ������ �ð��� t1�� ����
	double duration = (double)(t2 - t1); //�ð��� ���� �ð�
	cout << "�˰��� ���� �ð�: " << duration / CLOCKS_PER_SEC << "��";
}