// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 3���� ����
// 1��- ���ȯ�� �� ����
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <random>
#include <stack> //stack STL ���
using namespace std;

void quickSort(int* a, int Left, int Right) {
    stack<int> stack;
    int i, j;
    stack.push(Right);
    stack.push(Left);

    while (!stack.empty()) {
        Left = stack.top(); //���� Ŀ��(���� ��)
        stack.pop();

        Right = stack.top(); //������ Ŀ��(������ ��)
        stack.pop();

        if (Right-Left + 1 > 1) {//�κ� ����Ʈ�� ������ ������ 1�� ������ ������
            cout << "[���� Ŀ���� " << Left << "   "<<"������ Ŀ���� " << Right << "]" << endl;;
            int pivot = Left; //���ذ�
            i = pivot + 1;
            j= Right;
            while (i <= j) {
                //������������ �ݺ�
                while (a[i] > a[pivot]) // ���� ������ ���� ���� ���� ������ ���������� �̵� (���������̹Ƿ�)
                    i++;
                while (a[j] <a[pivot] && j>Left) // ���� ������ ū ���� ���� ������ �������� �̵�
                    j--;

                if (i > j) { //������
                    swap(a[j], a[pivot]);
                }
                else { //�������� ����-i��°�� j��° swap
                    swap(a[i], a[j]);
                }
            }
            //���� Ŀ���� ������ Ŀ�� ���̸� ����ϰ� �Ѵ�. �̶�, �����ϱ� ���� ������ �ξ ��ġ ����
            for (int k = 0; k < Left; k++) {
                cout << "        "; 
            }
            for (int w = Left; w <= Right; w++)
                cout << a[w] << "  ";
            cout << endl;
                stack.push(Right); //���� �κ� ����Ʈ�� ���� Ŀ��
                stack.push(j +1); //���� �κ� ����Ʈ�� ������ Ŀ��
                stack.push(j-1); //������ �κ� ����Ʈ�� ���� Ŀ��
                stack.push(Left); //������ �κ� ����Ʈ�� ������ Ŀ��
        }
    }
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
        cout << arr[i] << "  ";
    }
    cout << endl;

    quickSort(arr, 0, 9);
    cout << "[���ȯ�� �� ������ �̿��� ���� �迭]" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}