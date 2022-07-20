//2020112377 ��μ�
//�������� �̿��ؼ� 100���� ���� ����

#include <iostream>
#include<cstdlib>  // �������������ִ� �������
#include<ctime>  //�ð��� �õ尪���� �������ټ��ִ� �������
#include<iomanip> //setw �Լ� 
using namespace std;

int BubbleSort(int A[], int n) { //���� ���� �Լ�
	if (n == 1)
		return 0;
	else {
		int i, tmp;
		bool Sorted= false;
		while (!Sorted) { //������ �Ǿ������� �����.
			Sorted = true; //�ϳ��� �ȹٲ�� Sorted=true
			for (i = 1; i < n; i++) {
				if (A[i - 1] > A[i]) { //�̿��� ���ҳ��� ��->���� ���Ұ� ũ�� swap
					tmp = A[i - 1];
					A[i - 1] = A[i];
					A[i] = tmp;
					Sorted = false;
				}
			}
		}
		BubbleSort(A, n - 1); //���
	}
}


int main() {

	srand((unsigned int)time(NULL)); //���� �߻� �ʱ�ȭ

	int* array = new int[100]{}; 
	for (int i = 0; i < 100; i++)
		array[i] = rand(); //���� 100�� �����ϰ� �迭�� �Է�
	cout << "[������ 100�� ����]" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << setw(7)<<array[10*i+j] << "   ";
		cout << endl;
	} //������ 100��  ���� 10*10 ���� ���
	cout << endl;

	BubbleSort(array, 100); //�Լ� ȣ��

	cout << "[���ĵ� 100�� ����]" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << setw(7) << array[10 * i + j] << "   ";
		cout << endl;
	}//���ĵ� 100�� ���� 10*10 ���� ���
}