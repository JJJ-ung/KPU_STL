#include "Headers.h"

int main()
{
	/*
	vector<int> v;
	list<int> con;

	cout << v.max_size() << endl;
	cout << con.max_size() << endl;

	// vector�� ������� (�޸� ����)
	// list�� ���� �ȵǾ��ִ�
	*/

	/*
	vector<int> v{ 1, 2, 3, 4, 5 };
	reverse(v.begin(), v.end());
	*/

	list<int> v{ 1, 2, 3, 4, 5 };
	v.reverse();

	for (int n : v)
		cout << n << " ";
	cout << endl;
}