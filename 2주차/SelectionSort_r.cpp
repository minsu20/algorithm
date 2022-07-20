//2020112377 김민수
// 1번-순환

#include <iostream>
using namespace std;

int FindMinIndex(int A[], int start, int& result, int finish) {  //최솟값 찾는 함수
	if (start == finish)
		return result;
	else {
		if (A[result] > A[start])
			result = start;
		FindMinIndex(A, start + 1, result, finish); //재귀
	}
}


int SelectionSort(int A[], int n, int startIndex) { //순환적 선택정렬 함수
	int i, j, tmp, k;
	if (startIndex==n)
		return 0;

	else {
		for (int i = 0; i < n; i++)
			cout << A[i] << "   "; //각 단계 출력
		cout << endl;

		tmp = startIndex;
		int MinIndex = FindMinIndex(A, startIndex, tmp, n); //[startIndex, n]에서 최솟값 찾기

		if (MinIndex != startIndex) { // A[startIndex]와 A[MinIndex] swap
			j = A[startIndex];
			A[startIndex] = A[MinIndex];
			A[MinIndex] = j;
		}

		SelectionSort(A, n, startIndex + 1); //재귀
	}
}



int main() {

	int* array = new int[8]{ 30, 20, 40, 10, 5, 10, 30, 15 }; //배열 선언
	SelectionSort(array, 8,0); //함수 호출
}