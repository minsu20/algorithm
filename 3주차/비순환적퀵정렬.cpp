// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 3주차 과제
// 1번- 비순환적 퀵 정렬
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <random>
#include <stack> //stack STL 사용
using namespace std;

void quickSort(int* a, int Left, int Right) {
    stack<int> stack;
    int i, j;
    stack.push(Right);
    stack.push(Left);

    while (!stack.empty()) {
        Left = stack.top(); //왼쪽 커서(왼쪽 끝)
        stack.pop();

        Right = stack.top(); //오른쪽 커서(오른쪽 끝)
        stack.pop();

        if (Right-Left + 1 > 1) {//부분 리스트의 원소의 개수가 1개 이하일 때까지
            cout << "[왼쪽 커서는 " << Left << "   "<<"오른쪽 커서는 " << Right << "]" << endl;;
            int pivot = Left; //기준값
            i = pivot + 1;
            j= Right;
            while (i <= j) {
                //엇갈릴때까지 반복
                while (a[i] > a[pivot]) // 기준 값보다 작은 값을 만날 때까지 오른쪽으로 이동 (내림차순이므로)
                    i++;
                while (a[j] <a[pivot] && j>Left) // 기준 값보다 큰 값을 만날 때까지 왼쪽으로 이동
                    j--;

                if (i > j) { //엇갈림
                    swap(a[j], a[pivot]);
                }
                else { //엇갈리지 않음-i번째와 j번째 swap
                    swap(a[i], a[j]);
                }
            }
            //왼쪽 커서와 오른쪽 커서 사이만 출력하게 한다. 이때, 이해하기 쉽게 공백을 두어서 위치 조정
            for (int k = 0; k < Left; k++) {
                cout << "        "; 
            }
            for (int w = Left; w <= Right; w++)
                cout << a[w] << "  ";
            cout << endl;
                stack.push(Right); //왼쪽 부분 리스트의 왼쪽 커서
                stack.push(j +1); //왼쪽 부분 리스트의 오른쪽 커서
                stack.push(j-1); //오른쪽 부분 리스트의 왼쪽 커서
                stack.push(Left); //오른쪽 부분 리스트의 오른쪽 커서
        }
    }
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
        cout << arr[i] << "  ";
    }
    cout << endl;

    quickSort(arr, 0, 9);
    cout << "[비순환적 퀵 정렬을 이용한 최종 배열]" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}