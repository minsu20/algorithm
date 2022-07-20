// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 7주차 과제
// main.cpp-main 함수
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include "redblacktree.h"
using namespace std;

int main() {

	RBTree T1;	//트리 생성
	char command;
	int number;	
	do {
		cout << "숫자를 삽입하시겠습니까? (Y/N) : ";

		cin >> command;
		if (command == 'Y') {	//숫자 삽입
			cout << "key= ";
			cin >> number;
		}

		switch (command)
		{
		case 'Y': {	// insert command
			T1.insertNode(number);
			break;
		}
		case 'N': {	// quit program
			break;
		}
		default: {	// error command
			cout << "잘못 입력하셨습니다. Y또는 N으로만 입력해주세요." << endl;
		}
			   break;
		}
		T1.showStructure();	// print tree
	} while (command != 'N');	// quit program

}