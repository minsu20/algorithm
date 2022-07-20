// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 5���� ����
// 1��- �ִ� �ּڰ� ���ÿ� ã��
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

int FindMinMax(int A[], int n, int* minimum, int* maximum) { //�ּڰ� �ִ� ���ÿ� ã�� �Լ�
    int small, large;
    *minimum = A[0]; *maximum = A[0];
    for (int i = 1; i < n - 1; i += 2) { //2���� ���� 
        if (A[i] < A[i + 1]) { //2���� ���� ���� ��
            small = A[i]; //������ small
            large = A[i + 1]; //ū�� large
        }
        else {
            small = A[i + 1];
            large = A[i];
        }
        if (small < *minimum) //���� ���� minimum���� ������
            *minimum = small; //minimum�� small ����
        if (large > *maximum) //ū ���� maximum���� ũ��
            *maximum = large; //maximum�� large ����
    }
    return 0;
}

int main() {
    int arr[1000] = { 0, }; //��ü �迭

    srand((unsigned int)time(NULL)); //�ð��� �õ尪���� �ؼ� �õ尪�� �׻� ���ϰ� ��

    cout << "[1000���� ���� ����] " << endl;
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand() % 100000 + 1; //1~100000���� ���� ����

        for (int j = 0; j < i; j++) { //�ߺ� ���Ÿ� ���� for ��
            if (arr[i] == arr[j]) { //�ߺ��� �߰ߵ� ���
                i--; //i��° ���ڸ� �ٽ� �̴´�
                break;
            }

        }
        cout << arr[i] << "  ";
    }
    int min, max = 0;
    cout << endl;
    FindMinMax(arr, 1000, &min, &max); //FindMinMax()�Լ� ȣ��
    cout << "�ִ��� " << max << " �ּڰ��� " << min;
}