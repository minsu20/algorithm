// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 3���� ����
// 2��- ��ȯ�� �պ� ����
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
using namespace std;

// leftptr: ���ĵ� ���� ����Ʈ�� ���� �ε���
// rightptr: ���ĵ� ������ ����Ʈ�� ���� �ε���
// bufptr: ���ĵ� ����Ʈ�� ���� �ε���
/* 2���� ������ �迭 list[left...mid]�� list[mid+1...right]�� �պ� ���� */
/* (������ ���ڵ��� ���ĵǴ� ����) */
void merge(int A[], int left, int mid, int right) { 
	for (int i = left; i <= mid; i++)
		cout << A[i] << " ";
	cout << "�� ";
	for (int i = mid + 1; i <= right; i++)
		cout << A[i] << " ";

	int B[10]; //����
	int leftptr, rightptr, bufptr, i;
	leftptr = left; rightptr = mid + 1; bufptr = left;
	while (leftptr <= mid && rightptr <= right) { //�������ĵ� ����Ʈ�� �պ�
		if (A[leftptr] <= A[rightptr]) //���� ���� ���� ���ۿ� ����
			B[bufptr++] = A[leftptr++];
		else
			B[bufptr++] = A[rightptr++];
	}
	//���� �ִ� ������ �ϰ� ����
	if (leftptr > mid) {
		for (i = rightptr; i <= right; i++)
			B[bufptr++] = A[i];
	}
	else {
		for (i = leftptr; i <= mid; i++)
			B[bufptr++] = A[i];
	}
	//�迭 B[](�ӽ� �迭)�� ����Ʈ�� �迭 A[]�� �纹��
	for (i = left; i <= right; i++)
		A[i] = B[i];

	cout << "�պ� ���: "; //merge ��� ���
		for (int i = left; i <= right; i++)
			cout<<A[i]<<" ";
		cout << endl;
}

void mergesort(int A[], int left, int right) {
	int mid;
	if (left < right) { //���Ұ� �� �� �̻��̸�
		mid = (left + right) / 2; //�迭�� �߰��� ã��
		for (int i = left; i <= mid; i++)
			cout << A[i] << " ";
		cout << "�� ";
		for (int i = mid + 1; i <= right; i++)
			cout << A[i] << " ";
		cout << "�� �պ����� �ϸ� ..." << endl;
		mergesort(A, left, mid); //�߰����� ���� �κ� ����Ʈ ����
		mergesort(A, mid + 1, right); //�߰����� ���� �κ� ����Ʈ ����
		merge(A, left, mid, right); //���ĵ� 2���� �κ� �迭 �պ�
	}
}

int main() {
	int A[10] = { 30, 20, 40, 35, 5, 50, 45, 10, 25, 15 };
	cout << "[�ʱ� �迭]" << endl;
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";
	cout << endl<<endl;
	mergesort(A, 0, 9);
	cout << endl<<"[��ȯ�� �պ� ������ �̿��� ���� �迭]" << endl;
	for (int i = 0; i < 10; i++)
		cout << A[i]<<" ";
}