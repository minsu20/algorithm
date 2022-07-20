// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 3���� ����
// 1��- ��ȯ�� �� ����
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <random>
using namespace std;

void quicksort(int A[], int Left, int Right) {
    if (Left >= Right)
        return; // ���Ұ� 1���� ���

    cout << "[���� Ŀ���� " << Left << "   " << "������ Ŀ���� " << Right << "]" << endl;;
    int pivot = Left; //ù ��° ����
    int i = pivot + 1; //���� ��� ����
    int j = Right; //������ ��� ����
    int temp;

    while(i <= j){
        //������������ �ݺ�
        while (A[i] > A[pivot]) // ���� ������ ���� ���� ���� ������ ���������� �̵� (���������̹Ƿ�)
            i++;
        while (A[j] <A[pivot]&&j>Left) // ���� ������ ū ���� ���� ������ �������� �̵�
            j--;
        
        if (i > j) { //������
            swap(A[j], A[pivot]);
        }
        else { //�������� ����-i��°�� j��° swap
            swap(A[i], A[j]);
        }
    } 
    for (int k = 0; k < Left; k++) {
        cout << "        ";
    }
    for (int w = Left; w <= Right; w++)
        cout << A[w] << "  ";
    cout << endl;

    quicksort(A, Left, j - 1); // (left ~ �ǹ� �ٷ� ��) ���� �κ� ����Ʈ ����
    quicksort(A, j + 1, Right); // (�ǹ� �ٷ� �� ~ right) ���� �κ� ����Ʈ ����
}


int main() {
    // �õ尪�� ��� ���� random_device ����.
    random_device rd;

    // random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
    mt19937 gen(rd());

    // 1 ���� 1000000 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
    uniform_int_distribution<int> dis(1, 1000000);

    int arr[10] = { 0, };
    cout << "[10���� ���� ����] " << endl;
    for (int i = 0; i < 10; i++) {
        arr[i] = dis(gen);
        cout << arr[i]<<"  ";
    }
    cout << endl;

    quicksort(arr, 0, 9);
    cout << "[��ȯ�� �� ������ �̿��� ���� �迭]" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}