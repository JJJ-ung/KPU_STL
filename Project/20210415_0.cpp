#include <iostream>
#include <vector>
#include <deque>

#include "String.h"

using namespace std;

struct Test
{
	char c[1024];
	void show() const
	{
		cout << this << endl;
	}
};

int main()
{
	/*
	�����̳�
			sequence �����̳�
				array, vector
				deque - �� ��?	
	*/
	
	/*deque<String> d{ "����ó��", "������" };
	for (const String& s : d)
		cout << s << endl;*/

	//deque : �޸𸮰� ���ӵǾ� �ִ°�?
	// [i] : ���ӵ� �ֵ鸸 �� �� �ִ�




	/*
	vector<Test> v(10);
	for (const Test& t : v)
		t.show();
	// �޸𸮰� �پ������ϱ� 400 ����Ʈ�� ���̰� �� �ּҰ���

	cout << "�߰� �� �ٽ� ��� " << endl;
	v.push_back({});

	for (const Test& t : v)
		t.show();
	// ���� ����ߴ� �ּҿ��� �̻簬��
	*/

		
	deque<Test> v(10);
	for (const Test& t : v)
		t.show();
	// 8����Ʈ�� �� ����
	// �޸� ����

	cout << "�߰� �� �ٽ� ��� " << endl;
	v.push_back({});

	for (const Test& t : v)
		t.show();
	// �̻絵 �Ȱ�
	

	// deque�� ���ӵ� �� ���� �ൿ�� �� (����)
	// �޸𸮰� �پ��������� Ư¡
	// vector�� ���� access �ӵ��� ������ (����)
}