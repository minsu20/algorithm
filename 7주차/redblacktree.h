// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 7주차 과제
// redblacktree.h-클래스 선언부
// 2020112377 김민수
// -----------------------------------------------------------

enum Color //색깔(레드-0/블랙-1)
{
	RED,
	BLACK
};

class node { //노드 
private:
	//생성자
	node(int nodekey, Color nodecolor, node* leftptr, node* rightptr, node* parentptr);

	//멤버변수
	int key; //값
	Color color; //색깔
	node* left, //왼쪽 자식 포인터
		*right, //오른쪽 자식 포인터
		*parent; //부모가리키는 포인터
	friend class RBTree;
};

class RBTree {
private:
	//멤버변수
		node* root; //루트
		node* nil; //리프

public:
	//생성자
	RBTree();

	//멤버함수
	void leftRotate(node* x); //left rotate 하는 함수
	void rightRotate(node* x); //right rotae 하는 함수
	void insertNode(int key); //node 삽입하는 함수
	void insertfixedup(node* x); //레드블랙 트리의 특성에 맞게 재배치
	void showStructure(); //레드블랙트리 보여주는 함수(구조까지)

	void showSub(node* p, int level);//showStrucutre Recursive partners
};