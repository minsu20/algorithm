//2020112377 ��μ�
//1��- ���ȯ

#include <iostream>
using namespace std;

void SelectionSort(int A[], int n) { //���ȯ�� �������� �Լ�
	int i, j, MinIndex, tmp;
	for (i = 0; i < n ; i++) { 
		MinIndex = i;
		for (int k = 0; k < n; k++)
			cout << A[k] << "  "; //�� �ܰ� ���
		cout << endl;
		for (j = MinIndex + 1; j < n; j++) { //[i, n]���� i��°�� �� �ּڰ� ã��
			if (A[MinIndex] > A[j])
				MinIndex = j;
		}
		if (MinIndex!=i) { //A[MinIndex]�� A[i] Swap
			int temp = A[i];
			A[i] = A[MinIndex];
			A[MinIndex] = temp;
		}
	}
}


int main(){

	int *array=new int[8]{ 30, 20, 40, 10, 5, 10, 30, 15 }; //�迭 ����
	SelectionSort(array, 8); //�Լ� ȣ��
}
