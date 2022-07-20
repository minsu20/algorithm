// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 4주차 과제
// 1번 회문- 순환 방식
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <fstream> //파일 입출력 헤더 라이브러리
#include <string>
using namespace std;


bool isPalindrome(const string& s, size_t st, size_t en)
{
    if (s.length()==1) //문자열 길이가 1이면 회문 아님
        return false;

    if(en <= st) //시작 인덱스가 더 커지면 true
        return true;

    if (s[st] != s[en]) //같지 않다면 false
        return false;

    if (en-st>0) //en>st이면 재귀 함수 호출
        return isPalindrome(s, st + 1, en - 1);

}


int main() {
    string str;
    ifstream readFile;  //읽을 목적의 파일 선언
    int i = 0;
    char name[10] = "input.txt";
    readFile.open("input.txt");  //파일 열기
    cout << "[순환 방식으로 회문 확인]" << endl;
    if (readFile.is_open())  //파일이 성공적으로 읽히면 ture를 반환
    {
        while (!readFile.eof())  //끝에 다다를 때 까지 반복
        {
            i++;
            getline(readFile, str); //파일 한줄 씩 읽기
            if (str.length() >= 1) { //길이가 1 이상일 때
                cout << i << "번째 문장: " << str << endl;    //지금 읽은 문자열 바로 출력.
                if (isalnum(str[str.length()-1]) == 0) { //끝글자가 특수문자이면
                    if (isPalindrome(str, 0, str.length()-2)) { //회문 판정 함수 호출->회문이면 (끝 인덱스 -1)
                        cout << "회문입니다." << endl;
                    }
                    else //회문이 아니면
                        cout << "회문이 아닙니다." << endl; 
                    cout << endl;
                }
                else { //끝글자가 특수문자가 아니면
                    if (isPalindrome(str, 0, str.length()-1)) { //회문 판정 함수 호출->회문이면
                        cout << "회문입니다." << endl;
                    }
                    else //회문이 아니면
                        cout << "회문이 아닙니다." << endl;
                    cout << endl;
                }
            }
        }
        readFile.close();    //파일 닫기
    }
}
