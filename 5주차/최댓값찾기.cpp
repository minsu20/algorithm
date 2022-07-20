// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 5주차 과제
// 1번- 최댓값 찾기
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

int Maximum(int A[], int size) { //최댓값 찾기 함수
    int max = A[0]; //최댓값 넣는 변수
    for (int i = 1; i < size; i++) { //배열의 처음부터 끝까지 조사해서
        if (A[i] > max) //max보다 큰 원소가 나오면
            max = A[i]; //그 값을 max에 대입한다
    }
    return max;
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

        cout << endl;
        cout << "최댓값은 " << Maximum(arr, 1000);
}
