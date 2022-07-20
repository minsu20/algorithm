// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 5주차 과제
// 1번- 최댓값 최솟값 동시에 찾기
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

int FindMinMax(int A[], int n, int* minimum, int* maximum) { //최솟값 최댓값 동시에 찾는 함수
    int small, large;
    *minimum = A[0]; *maximum = A[0];
    for (int i = 1; i < n - 1; i += 2) { //2개씩 조사 
        if (A[i] < A[i + 1]) { //2개의 원소 서로 비교
            small = A[i]; //작은게 small
            large = A[i + 1]; //큰게 large
        }
        else {
            small = A[i + 1];
            large = A[i];
        }
        if (small < *minimum) //작은 값이 minimum보다 작으면
            *minimum = small; //minimum에 small 대입
        if (large > *maximum) //큰 값이 maximum보다 크면
            *maximum = large; //maximum에 large 대입
    }
    return 0;
}

int main() {
    int arr[1000] = { 0, }; //전체 배열

    srand((unsigned int)time(NULL)); //시간을 시드값으로 해서 시드값이 항상 변하게 함

    cout << "[1000개의 난수 생성] " << endl;
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand() % 100000 + 1; //1~100000까지 숫자 범위

        for (int j = 0; j < i; j++) { //중복 제거를 위한 for 문
            if (arr[i] == arr[j]) { //중복이 발견된 경우
                i--; //i번째 숫자를 다시 뽑는다
                break;
            }

        }
        cout << arr[i] << "  ";
    }
    int min, max = 0;
    cout << endl;
    FindMinMax(arr, 1000, &min, &max); //FindMinMax()함수 호출
    cout << "최댓값은 " << max << " 최솟값은 " << min;
}