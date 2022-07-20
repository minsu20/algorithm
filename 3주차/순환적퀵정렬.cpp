// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 3주차 과제
// 1번- 순환적 퀵 정렬
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <random>
using namespace std;

void quicksort(int A[], int Left, int Right) {
    if (Left >= Right)
        return; // 원소가 1개인 경우

    cout << "[왼쪽 커서는 " << Left << "   " << "오른쪽 커서는 " << Right << "]" << endl;;
    int pivot = Left; //첫 번째 원소
    int i = pivot + 1; //왼쪽 출발 지점
    int j = Right; //오른쪽 출발 지점
    int temp;

    while(i <= j){
        //엇갈릴때까지 반복
        while (A[i] > A[pivot]) // 기준 값보다 작은 값을 만날 때까지 오른쪽으로 이동 (내림차순이므로)
            i++;
        while (A[j] <A[pivot]&&j>Left) // 기준 값보다 큰 값을 만날 때까지 왼쪽으로 이동
            j--;
        
        if (i > j) { //엇갈림
            swap(A[j], A[pivot]);
        }
        else { //엇갈리지 않음-i번째와 j번째 swap
            swap(A[i], A[j]);
        }
    } 
    for (int k = 0; k < Left; k++) {
        cout << "        ";
    }
    for (int w = Left; w <= Right; w++)
        cout << A[w] << "  ";
    cout << endl;

    quicksort(A, Left, j - 1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬
    quicksort(A, j + 1, Right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬
}


int main() {
    // 시드값을 얻기 위한 random_device 생성.
    random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    mt19937 gen(rd());

    // 1 부터 1000000 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    uniform_int_distribution<int> dis(1, 1000000);

    int arr[10] = { 0, };
    cout << "[10개의 난수 생성] " << endl;
    for (int i = 0; i < 10; i++) {
        arr[i] = dis(gen);
        cout << arr[i]<<"  ";
    }
    cout << endl;

    quicksort(arr, 0, 9);
    cout << "[순환적 퀵 정렬을 이용한 최종 배열]" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}