// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 9���� ����
// 2��- MEMORIZED_CUR_ROD(����� ���� ���α׷���).cpp
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#define INF 987654321 
using namespace std;

int MEMORIZED_CUT_ROD_AUX(int p[], int n, int r[]) {  //CUT-ROD�� �޸��ϱⰡ ������
	int q = -INF;  //�� �ʱ�ȭ
	if (r[n] >= 0) //���ϴ� ���� �̹� ���Ǿ����� Ȯ��
		return r[n]; //�̹� ���Ǿ����� �ش簪�� ����
	
	if (n == 0) 
		return 0;

	else { //���Ǿ� ���� ���� ���
		for (int i = 1; i <= n; i++) { //��� �Լ� ȣ��
			q = max(q, p[i-1] + MEMORIZED_CUT_ROD_AUX(p, n - i, r));
		}
	}
	r[n] = q; //����� ���� r[n]�� ����
	return q; //�� ���� ��ȯ
}

int MEMORIZED_CUT_ROD(int p[], int n) { //����� ���� ���α׷���
	int* r = new int[n + 1]; //���ο� �迭�� ���� 
	for (int i = 0; i < n; i++) {
		r[i] = -INF; //���� �𸣴� ���� -INF�� �ʱ�ȭ
	}
	return MEMORIZED_CUT_ROD_AUX(p, n, r); //�Լ� ȣ��
}

int main() {
	int p[10] = { 1,5,8,9,10,17,17,20,24,30 }; //���̿� ���� ���� �迭
	for (int i = 1; i <= 10; i++) { //���̿� ���� �ִ� ���� ���
		cout << "���̰� " << i << "�� �� �ִ� ������ " << MEMORIZED_CUT_ROD(p, i) << endl;
	}
}