//2020112377 ��μ�
// 1��-��ȯ

#include <iostream>
using namespace std;

int FindMinIndex(int A[], int start, int& result, int finish) {  //�ּڰ� ã�� �Լ�
	if (start == finish)
		return result;
	else {
		if (A[result] > A[start])
			result = start;
		FindMinIndex(A, start + 1, result, finish); //���
	}
}


int SelectionSort(int A[], int n, int startIndex) { //��ȯ�� �������� �Լ�
	int i, j, tmp, k;
	if (startIndex==n)
		return 0;

	else {
		for (int i = 0; i < n; i++)
			cout << A[i] << "   "; //�� �ܰ� ���
		cout << endl;

		tmp = startIndex;
		int MinIndex = FindMinIndex(A, startIndex, tmp, n); //[startIndex, n]���� �ּڰ� ã��

		if (MinIndex != startIndex) { // A[startIndex]�� A[MinIndex] swap
			j = A[startIndex];
			A[startIndex] = A[MinIndex];
			A[MinIndex] = j;
		}

		SelectionSort(A, n, startIndex + 1); //���
	}
}



int main() {

	int* array = new int[8]{ 30, 20, 40, 10, 5, 10, 30, 15 }; //�迭 ����
	SelectionSort(array, 8,0); //�Լ� ȣ��
}