// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// 10���� ����
// 1��- Intersection.cpp
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
using namespace std;

struct point { //�� ����ü
	float x; //x��ǥ
	float y; //y��ǥ
};

struct line { //���� ����ü
	struct point first; //ù ��° ��
	struct point second; //�� ��° ��
};

int Direction(struct point A, struct point B, struct point C) {
	//�� �� A,B,C�� �־����� �� ���� �� ABC�� ������ �����ϴ� �Լ�
	int dxAB = 0, dxAC = 0 , dyAB = 0, dyAC = 0 , Dir = 0;
	dxAB = B.x - A.x;
	dyAB = B.y - A.y;
	dxAC = C.x - A.x;
	dyAC = C.y - A.y;

	if (dxAB * dyAC == dyAB * dxAC) //������ �� ���� ��
	{
		if (dxAB == 0 && dyAB == 0) //A==B�� ���
			Dir = 0;
		if ((dxAB * dxAC < 0) || (dyAB * dyAC < 0)) //A�� ����� �ִ°��
			Dir = -1;
		else if ((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC)) //C�� ����� �ִ� ��� 
			Dir = 0;
		else //B�� ����� �ִ� ���
			Dir = 1;
	}
	else { //������ �� ���� ���� �� ������ ABC�� ������
		if (dxAB * dyAC < dyAB * dxAC) //�ð������ ��� AB���� > AC ����
			Dir = 1;
		if (dxAB * dyAC > dyAB * dxAC) //�ݽð������ ��� AB���� < AC����
			Dir = -1;
	}
	return Dir;
}

int Intersection(struct line AB, struct line CD) { 
	/*�Է�: AB, CD: ���� ���¸� �˻��� �� ����
	   ���: AB�� CD�� ���� �����ϸ� 1, �ƴϸ� 0*/
	int LineCrossing;
	if ((Direction(AB.first, AB.second, CD.first) * Direction(AB.first, AB.second, CD.second) <= 0) &&
		(Direction(CD.first, CD.second, AB.first) * Direction(CD.first, CD.second, AB.second) <= 0)) //�� �� ������ ������ �� ������ ����
		LineCrossing = 1; //��
	else
		LineCrossing = 0; //����
	return LineCrossing;
}

int main() {
	struct line AB, CD;
	cout << "���� AB�� ���� CD�� �����ϴ��� �˷��ݴϴ�." << endl;
	cout << "�� ���� x��ǥ�� y��ǥ�� �Է����ּ���. " << endl;
	//�� ���� ��ǥ �Է¹ޱ�
	cout << "A�� x��ǥ: ";
	cin >> AB.first.x;
	cout << "A�� y��ǥ: ";
	cin >> AB.first.y;
	cout << "B�� x��ǥ: ";
	cin >> AB.second.x;
	cout << "B�� yǥ: ";
	cin >> AB.second.y;

	cout << "C�� x��ǥ: ";
	cin >> CD.first.x;
	cout << "C�� y��ǥ: ";
	cin >> CD.first.y;
	cout << "D�� x��ǥ: ";
	cin >> CD.second.x;
	cout << "D�� yǥ: ";
	cin >> CD.second.y;
	cout << "���� AB�� CD�� ";

	if (Intersection(AB, CD) == 1)
		cout << "�����մϴ�."; //������� 1�̸� �����մϴ� ���

	else
		cout << "�������� �ʽ��ϴ�. "; //������� 0�̸� �������� �ʽ��ϴ� ���
}