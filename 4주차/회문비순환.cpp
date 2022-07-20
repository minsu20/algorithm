// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 4���� ����
// 1�� ȸ��- ���ȯ ���
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <fstream> //���� ����� ��� ���̺귯��
#include <string>
#include <cctype>
using namespace std;


bool isPalindrome( string & s, size_t st, size_t en)
{
    if (isalnum(s[s.length()-1]) == 0) { //�����̳� �ܾ� ���� Ư�� ���ڰ� ���Ե� ��� 
        en = en - 1;
    }

    if (s.length() == 1) //�ѱ��ڴ� ȸ�� �ƴ�
        return  false;

    if(en - st == 0) //h?���� ���->�ѱ���+Ư������ ����
        return true; 

    int i = st, j = en; //i: ù��° ����, j:������ ����
    while (i <= j) { //���� �߰��� ���������� ��
        if (s[i] == s[j]) {
            i++;
            j--;
        }
        else //�ѹ��̶� �ٸ��ٸ�
            return false;
    }

    //���������� ���ٸ�
    return true;
}

int main() {
    string str;
    ifstream readFile;  //���� ������ ���� ����
    int i = 0;
    char name[10] = "input.txt";
    readFile.open("input.txt"); //���� ����
    cout << "[���ȯ ������� ȸ�� Ȯ��]" << endl;
    if (readFile.is_open()) //������ ���������� ������ ture�� ��ȯ
    {
        while (!readFile.eof()) //���� �ٴٸ� �� ���� �ݺ�
        {
            i++;
            getline(readFile, str);  //���پ� �о����
            if (str.length() >= 1) { //���̰� 1 �̻��� ��
                cout << i << "��° ����: " << str << endl;    //���� ���� ���ڿ� �ٷ� ���.
                if (isPalindrome(str, 0, str.length()-1)) { //ȸ�� ���� �Լ� ȣ��->ȸ���̸�
                    cout << "ȸ���Դϴ�." << endl;
                }
                else //ȸ���� �ƴϸ�
                    cout << "ȸ���� �ƴմϴ�." << endl;
                cout << endl;
            }
        }
        readFile.close();    //���� �ݱ�
    }
}