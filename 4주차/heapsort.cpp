// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 4���� ����
// 2�� �� ����
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
using namespace std;

void MaxHeap(int A[], int root, int lastnode)	// �ִ� ������ ������
{
	int parent, left, right, maxson, rootvalue;
	parent = root;
	rootvalue = A[root];
	left = 2 * parent + 1; //�ڽ� ��� �� ���ʿ� �ִ� ���
	right = 2 * parent + 2;
	while (left <= lastnode) { //������ �� ������
		if (right <= lastnode && A[left] < A[right])
			maxson = right;//child�߿��� ū ����� �ε����� maxson�� ����
		else
			maxson = left;
		if (rootvalue < A[maxson]) {
			//��Ʈ������ maxson���� ũ��
			swap(A[parent], A[maxson]); //���� �� ��ȯ
			parent = maxson; //maxson�� parent�� ��
			left = parent * 2 + 1;//�ٽ� child ����
			right = left + 1;
		}
		else break;
	}
	A[parent] = rootvalue;
}

void buildHeap(int A[], int n) {//����� �� ����
	int i;
	for (i = n / 2; i >= 0; i--) {
		MaxHeap(A, i, n - 1);  //�Ʒ����� �ִ� ������ ������
	}
}


void HeapSort(int A[], int n) { //�� ����
	int i;
	for (i = n - 1; i > 0; i--) {
		swap(A[0], A[i]);//���� �ִ��� ����(���� �ε����� ū �ڽ� ���� ��ȯ)
		MaxHeap(A, 0, i - 1); //�ִ� ������ ������
	}
}

int main() {
	int A[20]{ 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	cout << "�ʱ� �迭" << endl;
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "  ";
	}
	cout << endl << "�� ���� ��" << endl;
	buildHeap(A, 10);
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "  ";
	}
	cout << endl << "�� ���� ��" << endl;
	HeapSort(A, 10);
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "  ";
	}
}
