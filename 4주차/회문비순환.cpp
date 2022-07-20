// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 4주차 과제
// 1번 회문- 비순환 방식
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include <fstream> //파일 입출력 헤더 라이브러리
#include <string>
#include <cctype>
using namespace std;


bool isPalindrome( string & s, size_t st, size_t en)
{
    if (isalnum(s[s.length()-1]) == 0) { //문장이나 단어 끝에 특수 문자가 포함된 경우 
        en = en - 1;
    }

    if (s.length() == 1) //한글자는 회문 아님
        return  false;

    if(en - st == 0) //h?같은 경우->한글자+특수문자 조합
        return true; 

    int i = st, j = en; //i: 첫번째 문자, j:마지막 문자
    while (i <= j) { //서로 중간에 만날때까지 비교
        if (s[i] == s[j]) {
            i++;
            j--;
        }
        else //한번이라도 다르다면
            return false;
    }

    //만날때까지 같다면
    return true;
}

int main() {
    string str;
    ifstream readFile;  //읽을 목적의 파일 선언
    int i = 0;
    char name[10] = "input.txt";
    readFile.open("input.txt"); //파일 열기
    cout << "[비순환 방식으로 회문 확인]" << endl;
    if (readFile.is_open()) //파일이 성공적으로 읽히면 ture를 반환
    {
        while (!readFile.eof()) //끝에 다다를 때 까지 반복
        {
            i++;
            getline(readFile, str);  //한줄씩 읽어오기
            if (str.length() >= 1) { //길이가 1 이상일 때
                cout << i << "번째 문장: " << str << endl;    //지금 읽은 문자열 바로 출력.
                if (isPalindrome(str, 0, str.length()-1)) { //회문 판정 함수 호출->회문이면
                    cout << "회문입니다." << endl;
                }
                else //회문이 아니면
                    cout << "회문이 아닙니다." << endl;
                cout << endl;
            }
        }
        readFile.close();    //파일 닫기
    }
}