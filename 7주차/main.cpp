// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 7���� ����
// main.cpp-main �Լ�
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include "redblacktree.h"
using namespace std;

int main() {

	RBTree T1;	//Ʈ�� ����
	char command;
	int number;	
	do {
		cout << "���ڸ� �����Ͻðڽ��ϱ�? (Y/N) : ";

		cin >> command;
		if (command == 'Y') {	//���� ����
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
			cout << "�߸� �Է��ϼ̽��ϴ�. Y�Ǵ� N���θ� �Է����ּ���." << endl;
		}
			   break;
		}
		T1.showStructure();	// print tree
	} while (command != 'N');	// quit program

}