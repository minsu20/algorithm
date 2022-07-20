// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 3주차 과제
// 2번- 순환적 합병 정렬
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
using namespace std;

// leftptr: 정렬된 왼쪽 리스트에 대한 인덱스
// rightptr: 정렬된 오른쪽 리스트에 대한 인덱스
// bufptr: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(int A[], int left, int mid, int right) { 
	for (int i = left; i <= mid; i++)
		cout << A[i] << " ";
	cout << "와 ";
	for (int i = mid + 1; i <= right; i++)
		cout << A[i] << " ";

	int B[10]; //버퍼
	int leftptr, rightptr, bufptr, i;
	leftptr = left; rightptr = mid + 1; bufptr = left;
	while (leftptr <= mid && rightptr <= right) { //분할정렬된 리스트의 합병
		if (A[leftptr] <= A[rightptr]) //비교후 작은 값을 버퍼에 저장
			B[bufptr++] = A[leftptr++];
		else
			B[bufptr++] = A[rightptr++];
	}
	//남아 있는 값들을 일괄 복사
	if (leftptr > mid) {
		for (i = rightptr; i <= right; i++)
			B[bufptr++] = A[i];
	}
	else {
		for (i = leftptr; i <= mid; i++)
			B[bufptr++] = A[i];
	}
	//배열 B[](임시 배열)의 리스트를 배열 A[]로 재복사
	for (i = left; i <= right; i++)
		A[i] = B[i];

	cout << "합병 결과: "; //merge 결과 출력
		for (int i = left; i <= right; i++)
			cout<<A[i]<<" ";
		cout << endl;
}

void mergesort(int A[], int left, int right) {
	int mid;
	if (left < right) { //원소가 두 개 이상이면
		mid = (left + right) / 2; //배열의 중간을 찾아
		for (int i = left; i <= mid; i++)
			cout << A[i] << " ";
		cout << "와 ";
		for (int i = mid + 1; i <= right; i++)
			cout << A[i] << " ";
		cout << "을 합병정렬 하면 ..." << endl;
		mergesort(A, left, mid); //중간보다 앞쪽 부분 리스트 정렬
		mergesort(A, mid + 1, right); //중간보다 뒤쪽 부분 리스트 정렬
		merge(A, left, mid, right); //정렬된 2개의 부분 배열 합병
	}
}

int main() {
	int A[10] = { 30, 20, 40, 35, 5, 50, 45, 10, 25, 15 };
	cout << "[초기 배열]" << endl;
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";
	cout << endl<<endl;
	mergesort(A, 0, 9);
	cout << endl<<"[순환적 합병 정렬을 이용한 최종 배열]" << endl;
	for (int i = 0; i < 10; i++)
		cout << A[i]<<" ";
}