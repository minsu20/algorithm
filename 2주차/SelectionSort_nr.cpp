//2020112377 김민수
//1번- 비순환

#include <iostream>
using namespace std;

void SelectionSort(int A[], int n) { //비순환적 선택정렬 함수
	int i, j, MinIndex, tmp;
	for (i = 0; i < n ; i++) { 
		MinIndex = i;
		for (int k = 0; k < n; k++)
			cout << A[k] << "  "; //각 단계 출력
		cout << endl;
		for (j = MinIndex + 1; j < n; j++) { //[i, n]에서 i번째에 올 최솟값 찾기
			if (A[MinIndex] > A[j])
				MinIndex = j;
		}
		if (MinIndex!=i) { //A[MinIndex]와 A[i] Swap
			int temp = A[i];
			A[i] = A[MinIndex];
			A[MinIndex] = temp;
		}
	}
}


int main(){

	int *array=new int[8]{ 30, 20, 40, 10, 5, 10, 30, 15 }; //배열 선언
	SelectionSort(array, 8); //함수 호출
}
