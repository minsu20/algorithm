// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 4���� ����
// 1�� ȸ��- ��ȯ ���
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <fstream> //���� ����� ��� ���̺귯��
#include <string>
using namespace std;


bool isPalindrome(const string& s, size_t st, size_t en)
{
    if (s.length()==1) //���ڿ� ���̰� 1�̸� ȸ�� �ƴ�
        return false;

    if(en <= st) //���� �ε����� �� Ŀ���� true
        return true;

    if (s[st] != s[en]) //���� �ʴٸ� false
        return false;

    if (en-st>0) //en>st�̸� ��� �Լ� ȣ��
        return isPalindrome(s, st + 1, en - 1);

}


int main() {
    string str;
    ifstream readFile;  //���� ������ ���� ����
    int i = 0;
    char name[10] = "input.txt";
    readFile.open("input.txt");  //���� ����
    cout << "[��ȯ ������� ȸ�� Ȯ��]" << endl;
    if (readFile.is_open())  //������ ���������� ������ ture�� ��ȯ
    {
        while (!readFile.eof())  //���� �ٴٸ� �� ���� �ݺ�
        {
            i++;
            getline(readFile, str); //���� ���� �� �б�
            if (str.length() >= 1) { //���̰� 1 �̻��� ��
                cout << i << "��° ����: " << str << endl;    //���� ���� ���ڿ� �ٷ� ���.
                if (isalnum(str[str.length()-1]) == 0) { //�����ڰ� Ư�������̸�
                    if (isPalindrome(str, 0, str.length()-2)) { //ȸ�� ���� �Լ� ȣ��->ȸ���̸� (�� �ε��� -1)
                        cout << "ȸ���Դϴ�." << endl;
                    }
                    else //ȸ���� �ƴϸ�
                        cout << "ȸ���� �ƴմϴ�." << endl; 
                    cout << endl;
                }
                else { //�����ڰ� Ư�����ڰ� �ƴϸ�
                    if (isPalindrome(str, 0, str.length()-1)) { //ȸ�� ���� �Լ� ȣ��->ȸ���̸�
                        cout << "ȸ���Դϴ�." << endl;
                    }
                    else //ȸ���� �ƴϸ�
                        cout << "ȸ���� �ƴմϴ�." << endl;
                    cout << endl;
                }
            }
        }
        readFile.close();    //���� �ݱ�
    }
}
