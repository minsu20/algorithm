// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 8���� ����
// 1��- rabinKarp.cpp
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void RKsearch(char T[], char P[], int d, int q, int N, int M)
{
	/*�Է� T: ũ�Ⱑ N�� ���ڿ� 
	 P: ũ�Ⱑ M�� ����
	 d: ���ĺ��� ũ��
	 q: �ؽ� �Լ��� ���� ����*/
	int i, j, s;
	int p = 0; // ������ hash ��  
	int t = 0; // �ؽ�Ʈ�� hash ��  
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q; //d^(m-1)modq �� ���� ���


	for (i = 0; i <= M-1; i++)
	{
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
	}//ȣ�� ����� ����  p, t ���

	for (s = 0; s < N - M+1; s++) //�ؽ�Ʈ �� ��ġ ���� ���� ��Ī
	{
		if (p == t)//�ؽ� ���� ������ ��쿡 ���� ���� ���� ��Ī ����
		{

			for (i = 0; i < M; i++)
			{
				if (T[i + s] != P[i])
					break;
			}//���ڸ� �ϳ��� �񱳸� ���ݴϴ�.

			if (i== M)
				cout << "������ �ؽ�Ʈ�� " << s << "��°���� ��Ÿ��" << endl;
		}

		if (s < N - M)
		{
			t = (d * (t - T[s] * h) + T[s + M]) % q; //t_s�� t_s+1���� ���踦 �̿��� ��ȭ���� ���� ���� t�� ���

			if (t < 0)
				t = (t + q);
		}// ���� �ؽ�Ʈ�� hash ���� �����ݴϴ�.
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
	/*36�� ���� ���� ���ĺ��� 0~9���� ���� ���� 36�� ���ĺ��� ũ��� ����
	�׸��� q�� 101���� �� ���� �ִ� �Ҽ��� ����*/

}