// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 7���� ����
// redblacktree.cpp-Ŭ���� ������
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include "redblacktree.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
//������
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
// ȸ��
//left-rotate �Լ�
void RBTree::leftRotate(node* x) 
{
	node* y = x->right; //x�� ������ �ڽ� ��带 y�� ����
	x->right = y->left; //y�� ���� ����Ʈ���� x�� ������ ���� Ʈ���� �ű�

	if (y->left != nil) //y�� ���� �ڽ��� ������
		y->left->parent = x; //y�� ���� �ڽ��� �θ� x�� ����
	y->parent = x->parent; //y�� �θ� x�� �θ�� ���� 

	if (x->parent == nil) //x�� ��Ʈ�� ��� 
		root = y; //y�� ��Ʈ�� ����
	else if (x == x->parent->left) //x�� ���� �ڽ��� ���
		x->parent->left = y; //x�� �θ��� ���� �ڽ� ��带 y�� ����
	else //x�� ������ �ڽ��� ���
		x->parent->right = y; //x�� �θ��� ������ �ڽ� ��带 y�� ����

	y->left = x; //y�� ���� �ڽ� ��带 x�� ����
	x->parent = y; //x�� �θ� y�� ����
}

//right-rotate �Լ� : left-rotate �Լ��� ��Ī
void RBTree::rightRotate(node* x)
{
	node* y = x->left; //x�� ���� �ڽ� ��带 y�� ����
	x->left = y-> right; //y�� ������ ����Ʈ���� x�� ���� ���� Ʈ���� �ű�

	if (y->right != nil)  //y�� ������ �ڽ��� ������
		y->right->parent = x;  //y�� ������ �ڽ��� �θ� x�� ����
	y->parent = x->parent; //x�� �θ� y�� �θ�� ����

	if (x->parent == nil) //x�� ��Ʈ�� ���
		root = y; //y�� ��Ʈ�� ����
	else if (x == x->parent->left) //x�� ���� �ڽ��� ���
		x->parent->left = y;  //x�� �θ��� ���� �ڽ� ��带 y�� ����
	else //x�� ������ �ڽ��� ���
		x->parent-> right = y;  //x�� �θ��� ������ �ڽ� ��带 y�� ����

	y->right = x; //y�� ������ �ڽĳ�带 x�� ����
	x->parent = y; //x�� �θ� y�� ����
}
//----------------------------------------------------------------------------------------------------------------------
//insert function
//���� �Լ�
void RBTree::insertNode(int key) 
{
	node* newnode = new node(key, RED, nullptr, nullptr, nullptr); //�����ϴ� ���
	node* y = nil; //������ ����Ű�� y
	node* x = root; //��Ʈ�� ����Ű�� x
	while (x!=nullptr&&x != nil) //x�� ���� pointer ��ġ y ã��
	{
		y = x;
		if ((newnode->key) < (x->key)) //newnode ���� x���� ������
			x = x->left; //���� �ڽĳ���
		else //ũ��
			x = x->right; //������ �ڽĳ���
	}
		newnode->parent = y; //������ ����� �θ� ����
		if (y == nil) //����ִ� Ʈ���� ���
			root = newnode; //��Ʈ ����
		else if (newnode->key < y->key) //�θ𺸴� key ���� ������ 
			y->left = newnode; //���� �ڽ� ��忡 ����
		else  //�θ𺸴� key ���� ũ��
			y -> right = newnode; //������ �ڽ� ��忡 ����

		newnode->left = nil; //newnode ���� �ڽ� ��� nil��
		newnode->right = nil; //������ �ڽ� ��嵵 nil��
		newnode->color = RED; //newnode�� ������ red (����Ʈ)
		insertfixedup(newnode); //�����Ʈ�� Ư���� �°� ���ġ
}

//�����Ʈ�� Ư���� �°� ���� ���ġ�ϴ� �Լ�
void RBTree::insertfixedup(node* x) {
	if (x->parent != nullptr)
	while (x->parent->color == RED) {
		/*������ ����� �θ��尡 ������ ���
		(��尡 �����̸� �� ����� �ڽ��� ��� ����̴� ����)*/
			if (x->parent == x->parent->parent->left) { //x�� �θ� ���� �ڽĳ���� ���
				node* y = x->parent->parent->right; //y�� x�� �θ��� ����(����)
				if (y!=nullptr&&y->color == RED) { //���1- x�� ������  y�� ������ ���
					x->parent->color = BLACK; //x�� �θ� ������� ĥ��
					y->color = BLACK; //x�� ������ ������� ĥ��
					x->parent->parent->color = RED; //x�� ���θ� �������� ĥ�ϰ�
					x = x->parent->parent; //���θ� ���ο� x�� ���´�
				}
				else
				{
					if (x == x->parent->right) {//���2- x�� ���� y�� ����̸� x�� ������ �ڽ��� ���
						x = x->parent; //x�� �θ� x�� �ϰ�
						leftRotate(x); //��ȸ��
					} //��� 2���� ��ȸ���� �����ϸ� ��� 3���� �ٲ� �� �ִ�. 
					//��� 3- x�� ���� y�� ����̸� x�� ���� �ڽ��� ���
					x->parent->color = BLACK; //x�� �θ� ������� ĥ��
					x->parent->parent->color = RED; //x�� ���θ� �������� ĥ��
					rightRotate(x->parent->parent);//��ȸ��
				}
			}
			else {//x�� �θ� ������ �ڽĳ���� ��� -���� �ڽ� ����� ��쿡�� right<->left ���� �ٲ�
				node* y = x->parent->parent->left;  //y�� x�� �θ��� ����(����)
				if (y!=nullptr&&y->color == RED) { //���1- x�� ������  y�� ������ ���
					x->parent->color = BLACK; //x�� �θ� ������� ĥ��
					y->color = BLACK;  //x�� ������ ������� ĥ��
					x->parent->parent->color = RED;  //x�� ���θ� �������� ĥ�ϰ�
					x = x->parent->parent;  //���θ� ���ο� x�� ���´�
				}
				else
				{ 
					if (x == x->parent->left) { //���2- x�� ���� y�� ����̸� x�� ���� �ڽ��� ���
						x = x->parent; //x�� �θ� x�� �ϰ�
						rightRotate(x); //��ȸ��
					}
					//��� 2���� ��ȸ���� �����ϸ� ��� 3���� �ٲ� �� �ִ�. 
				   //��� 3- x�� ���� y�� ����̸� x�� ������ �ڽ��� ���
					x->parent->color = BLACK;  //x�� �θ� ������� ĥ��
					x->parent->parent->color = RED; //x�� ���θ� �������� ĥ��
					leftRotate(x->parent->parent); //��ȸ��
				}
			}
		}
	root->color = BLACK; //��Ʈ�� �������� ������� �ٲ�
}
//----------------------------------------------------------------------------------------------------------------------
//show function
void RBTree::showStructure() {
	if (root == 0) //empty tree �� ���
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1); //��� ȣ��
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

		if (p != nil) { //������ ������� �ʴ´�
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