// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 5���� ����
// 1��- �ִ� ã��
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

int Maximum(int A[], int size) { //�ִ� ã�� �Լ�
    int max = A[0]; //�ִ� �ִ� ����
    for (int i = 1; i < size; i++) { //�迭�� ó������ ������ �����ؼ�
        if (A[i] > max) //max���� ū ���Ұ� ������
            max = A[i]; //�� ���� max�� �����Ѵ�
    }
    return max;
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

        cout << endl;
        cout << "�ִ��� " << Maximum(arr, 1000);
}
