// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 7���� ����
// redblacktree.h-Ŭ���� �����
// 2020112377 ��μ�
// -----------------------------------------------------------

enum Color //����(����-0/��-1)
{
	RED,
	BLACK
};

class node { //��� 
private:
	//������
	node(int nodekey, Color nodecolor, node* leftptr, node* rightptr, node* parentptr);

	//�������
	int key; //��
	Color color; //����
	node* left, //���� �ڽ� ������
		*right, //������ �ڽ� ������
		*parent; //�θ𰡸�Ű�� ������
	friend class RBTree;
};

class RBTree {
private:
	//�������
		node* root; //��Ʈ
		node* nil; //����

public:
	//������
	RBTree();

	//����Լ�
	void leftRotate(node* x); //left rotate �ϴ� �Լ�
	void rightRotate(node* x); //right rotae �ϴ� �Լ�
	void insertNode(int key); //node �����ϴ� �Լ�
	void insertfixedup(node* x); //����� Ʈ���� Ư���� �°� ���ġ
	void showStructure(); //�����Ʈ�� �����ִ� �Լ�(��������)

	void showSub(node* p, int level);//showStrucutre Recursive partners
};