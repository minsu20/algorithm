// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 5���� ����
// 1��- �ּڰ� ã��
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

int Minimum(int A[], int size) { //�ּڰ� ã�� �Լ�
    int min = A[0]; //�ִ� �ִ� ����
    for (int i = 1; i < size; i++) { //�迭�� ó������ ������ �����ؼ�
        if (A[i] < min) //min���� ���� ���Ұ� ������
            min = A[i]; //�� ���� min�� �����Ѵ�
    }
    return min;
}

int main() {
    int arr[1000] = { 0, }; //��ü �迭

    srand((unsigned int)time(NULL)); //�ð��� �õ尪���� �ؼ� �õ尪�� �׻� ���ϰ� ��

    cout << "[1000���� ���� ����] " << endl;
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand()%100000+1; //1~100000���� ���� ����

        for (int j = 0; j < i; j++) { //�ߺ� ���Ÿ� ���� for ��
            if (arr[i] == arr[j]) { //�ߺ��� �߰ߵ� ���
                i--; //i��° ���ڸ� �ٽ� �̴´�
                break;
            }

        }
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout << "�ּڰ��� " << Minimum(arr, 1000); //Minimum()�Լ� ȣ��
}