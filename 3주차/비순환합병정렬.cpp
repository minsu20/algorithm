// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 3���� ����
// 2��- ���ȯ�� �պ� ����
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
	cout << "�� �պ�: ";

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

	//�պ� ��� ���
	for (int i = left; i <= right; i++)
		cout << A[i] << " ";
	cout << endl;
}

void mergesort(int A[], int n) {
	int curr_size; //�պ������� ���� �迭�� ������ 
	int left_start; // ���� �迭 ���� ����

	//���� �迭 ������� 1->2->4....������ ����
	for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
	{
		//���� �迭 ���� ���� ����
		for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
		{
			//���� �迭 ������ ���� ã��
			//������ �迭 ���� ������ mid+1
			int mid = min(left_start + curr_size - 1, n - 1);

			int right_end = min(left_start + 2 * curr_size - 1, n - 1);

			// A[left_start...mid] �� A[mid+1...right_end]�� merge
			if(mid<right_end)
				merge(A, left_start, mid, right_end);
		}
	}
}

int main() {
	int A[10] = { 30, 20, 40, 35, 5, 50, 45, 10, 25, 15 };
	cout << "[�ʱ� �迭]" << endl;
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";
	cout << endl<<endl;
	mergesort(A, 10);
	cout << endl << "[���ȯ�� �պ� ������ �̿��� ���� �迭]" << endl;
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";
}