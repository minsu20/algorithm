// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 4주차 과제
// 2번 힙 정렬
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
using namespace std;

void MaxHeap(int A[], int root, int lastnode)	// 최대 힙으로 재정비
{
	int parent, left, right, maxson, rootvalue;
	parent = root;
	rootvalue = A[root];
	left = 2 * parent + 1; //자식 노드 중 왼쪽에 있는 노드
	right = 2 * parent + 2;
	while (left <= lastnode) { //끝까지 갈 때까지
		if (right <= lastnode && A[left] < A[right])
			maxson = right;//child중에서 큰 노드의 인덱스를 maxson에 넣음
		else
			maxson = left;
		if (rootvalue < A[maxson]) {
			//루트값보다 maxson값이 크면
			swap(A[parent], A[maxson]); //서로 값 교환
			parent = maxson; //maxson이 parent가 됨
			left = parent * 2 + 1;//다시 child 지정
			right = left + 1;
		}
		else break;
	}
	A[parent] = rootvalue;
}

void buildHeap(int A[], int n) {//상향식 힙 생성
	int i;
	for (i = n / 2; i >= 0; i--) {
		MaxHeap(A, i, n - 1);  //아래부터 최대 힙으로 재정비
	}
}


void HeapSort(int A[], int n) { //힙 정렬
	int i;
	for (i = n - 1; i > 0; i--) {
		swap(A[0], A[i]);//힙의 최댓값을 제거(가장 인덱스가 큰 자식 노드와 교환)
		MaxHeap(A, 0, i - 1); //최대 힙으로 재정비
	}
}

int main() {
	int A[20]{ 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	cout << "초기 배열" << endl;
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "  ";
	}
	cout << endl << "힙 생성 후" << endl;
	buildHeap(A, 10);
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "  ";
	}
	cout << endl << "힙 정렬 후" << endl;
	HeapSort(A, 10);
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "  ";
	}
}
