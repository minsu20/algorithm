//2020112377 김민수
//버블정렬 이용해서 100개의 숫자 정렬

#include <iostream>
#include<cstdlib>  // 난수를생성해주는 헤더파일
#include<ctime>  //시간을 시드값으로 배정해줄수있는 헤더파일
#include<iomanip> //setw 함수 
using namespace std;

int BubbleSort(int A[], int n) { //버블 정렬 함수
	if (n == 1)
		return 0;
	else {
		int i, tmp;
		bool Sorted= false;
		while (!Sorted) { //정렬이 되어있으면 멈춘다.
			Sorted = true; //하나도 안바뀌면 Sorted=true
			for (i = 1; i < n; i++) {
				if (A[i - 1] > A[i]) { //이웃한 원소끼리 비교->앞의 원소가 크면 swap
					tmp = A[i - 1];
					A[i - 1] = A[i];
					A[i] = tmp;
					Sorted = false;
				}
			}
		}
		BubbleSort(A, n - 1); //재귀
	}
}


int main() {

	srand((unsigned int)time(NULL)); //난수 발생 초기화

	int* array = new int[100]{}; 
	for (int i = 0; i < 100; i++)
		array[i] = rand(); //난수 100개 생성하고 배열에 입력
	cout << "[생성한 100개 숫자]" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << setw(7)<<array[10*i+j] << "   ";
		cout << endl;
	} //생성한 100개  난수 10*10 으로 출력
	cout << endl;

	BubbleSort(array, 100); //함수 호출

	cout << "[정렬된 100개 숫자]" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << setw(7) << array[10 * i + j] << "   ";
		cout << endl;
	}//정렬된 100개 숫자 10*10 으로 출력
}