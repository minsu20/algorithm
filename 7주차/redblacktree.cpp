// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 7주차 과제
// redblacktree.cpp-클래스 구현부
// 2020112377 김민수
// -----------------------------------------------------------

#include <iostream>
#include "redblacktree.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
//생성자
node::node(int nodekey, Color nodecolor, node* leftptr, node* rightptr, node* parentptr)
	:key(nodekey), color(nodecolor), left(leftptr), right(rightptr), parent(parentptr)
{

}

RBTree::RBTree()
	: root(nullptr)
{
	nil = new node(-1, BLACK, nullptr, nullptr, nullptr);
}
//----------------------------------------------------------------------------------------------------------------------
// 회전
//left-rotate 함수
void RBTree::leftRotate(node* x) 
{
	node* y = x->right; //x의 오른쪽 자식 노드를 y로 설정
	x->right = y->left; //y의 왼쪽 서브트리를 x의 오른쪽 서브 트리로 옮김

	if (y->left != nil) //y의 왼쪽 자식이 있으면
		y->left->parent = x; //y의 왼쪽 자식의 부모를 x로 설정
	y->parent = x->parent; //y의 부모를 x의 부모로 설정 

	if (x->parent == nil) //x가 루트일 경우 
		root = y; //y를 루트로 설정
	else if (x == x->parent->left) //x가 왼쪽 자식인 경우
		x->parent->left = y; //x의 부모의 왼쪽 자식 노드를 y로 설정
	else //x가 오른쪽 자식인 경우
		x->parent->right = y; //x의 부모의 오른쪽 자식 노드를 y로 설정

	y->left = x; //y의 왼쪽 자식 노드를 x로 설정
	x->parent = y; //x의 부모를 y로 설정
}

//right-rotate 함수 : left-rotate 함수와 대칭
void RBTree::rightRotate(node* x)
{
	node* y = x->left; //x의 왼쪽 자식 노드를 y로 설정
	x->left = y-> right; //y의 오른쪽 서브트리를 x의 왼쪽 서브 트리로 옮김

	if (y->right != nil)  //y의 오른쪽 자식이 있으면
		y->right->parent = x;  //y의 오른쪽 자식의 부모를 x로 설정
	y->parent = x->parent; //x의 부모를 y의 부모로 연결

	if (x->parent == nil) //x가 루트일 경우
		root = y; //y를 루트로 설정
	else if (x == x->parent->left) //x가 왼쪽 자식인 경우
		x->parent->left = y;  //x의 부모의 왼쪽 자식 노드를 y로 설정
	else //x가 오른쪽 자식인 경우
		x->parent-> right = y;  //x의 부모의 오른쪽 자식 노드를 y로 설정

	y->right = x; //y의 오른쪽 자식노드를 x로 설정
	x->parent = y; //x의 부모를 y로 설정
}
//----------------------------------------------------------------------------------------------------------------------
//insert function
//삽입 함수
void RBTree::insertNode(int key) 
{
	node* newnode = new node(key, RED, nullptr, nullptr, nullptr); //삽입하는 노드
	node* y = nil; //리프를 가리키는 y
	node* x = root; //루트를 가리키는 x
	while (x!=nullptr&&x != nil) //x를 넣을 pointer 위치 y 찾기
	{
		y = x;
		if ((newnode->key) < (x->key)) //newnode 값이 x보다 작으면
			x = x->left; //왼쪽 자식노드로
		else //크면
			x = x->right; //오른쪽 자식노드로
	}
		newnode->parent = y; //삽입한 노드의 부모 설정
		if (y == nil) //비어있는 트리인 경우
			root = newnode; //루트 생성
		else if (newnode->key < y->key) //부모보다 key 값이 작으면 
			y->left = newnode; //왼쪽 자식 노드에 삽입
		else  //부모보다 key 값이 크면
			y -> right = newnode; //오른쪽 자식 노드에 삽입

		newnode->left = nil; //newnode 왼쪽 자식 노드 nil로
		newnode->right = nil; //오른쪽 자식 노드도 nil로
		newnode->color = RED; //newnode의 색깔은 red (디폴트)
		insertfixedup(newnode); //레드블랙트리 특성에 맞게 재배치
}

//레드블랙트리 특성에 맞게 구조 재배치하는 함수
void RBTree::insertfixedup(node* x) {
	if (x->parent != nullptr)
	while (x->parent->color == RED) {
		/*삽입한 노드의 부모노드가 적색인 경우
		(노드가 적색이면 그 노드의 자식은 모두 흑색이다 위반)*/
			if (x->parent == x->parent->parent->left) { //x의 부모가 왼쪽 자식노드인 경우
				node* y = x->parent->parent->right; //y는 x의 부모의 형제(삼촌)
				if (y!=nullptr&&y->color == RED) { //경우1- x의 삼촌이  y가 적색인 경우
					x->parent->color = BLACK; //x의 부모를 흑색으로 칠함
					y->color = BLACK; //x의 삼촌을 흑색으로 칠함
					x->parent->parent->color = RED; //x의 조부모를 적색으로 칠하고
					x = x->parent->parent; //조부모를 새로운 x로 놓는다
				}
				else
				{
					if (x == x->parent->right) {//경우2- x의 삼촌 y가 흑색이며 x가 오른쪽 자식인 경우
						x = x->parent; //x의 부모를 x로 하고
						leftRotate(x); //좌회전
					} //경우 2에서 좌회전을 적용하면 경우 3으로 바꿀 수 있다. 
					//경우 3- x의 삼촌 y가 흑색이며 x가 왼쪽 자식인 경우
					x->parent->color = BLACK; //x의 부모를 흑색으로 칠함
					x->parent->parent->color = RED; //x의 조부모를 적색으로 칠함
					rightRotate(x->parent->parent);//우회전
				}
			}
			else {//x의 부모가 오른쪽 자식노드인 경우 -왼쪽 자식 노드인 경우에서 right<->left 서로 바꿈
				node* y = x->parent->parent->left;  //y는 x의 부모의 형제(삼촌)
				if (y!=nullptr&&y->color == RED) { //경우1- x의 삼촌이  y가 적색인 경우
					x->parent->color = BLACK; //x의 부모를 흑색으로 칠함
					y->color = BLACK;  //x의 삼촌을 흑색으로 칠함
					x->parent->parent->color = RED;  //x의 조부모를 적색으로 칠하고
					x = x->parent->parent;  //조부모를 새로운 x로 놓는다
				}
				else
				{ 
					if (x == x->parent->left) { //경우2- x의 삼촌 y가 흑색이며 x가 왼쪽 자식인 경우
						x = x->parent; //x의 부모를 x로 하고
						rightRotate(x); //우회전
					}
					//경우 2에서 좌회전을 적용하면 경우 3으로 바꿀 수 있다. 
				   //경우 3- x의 삼촌 y가 흑색이며 x가 오른쪽 자식인 경우
					x->parent->color = BLACK;  //x의 부모를 흑색으로 칠함
					x->parent->parent->color = RED; //x의 조부모를 적색으로 칠함
					leftRotate(x->parent->parent); //좌회전
				}
			}
		}
	root->color = BLACK; //루트는 마지막에 흑색으로 바꿈
}
//----------------------------------------------------------------------------------------------------------------------
//show function
void RBTree::showStructure() {
	if (root == 0) //empty tree 인 경우
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1); //재귀 호출
		cout << endl;
	}
}

void RBTree::showSub(node* p, int level) {
	int j;   // Loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++)    // Tab over to level
			cout << "\t";

		if (p != nil) { //리프는 출력하지 않는다
			cout << " " << p->key;
			if (p->color == 0)
				cout << "[RED]";
			else
				cout << "[BLACK]";// Output key
		}
		if ((p->left != 0) &&           // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);          // Output left subtree
	}
}
//----------------------------------------------------------------------------------------------------------------------