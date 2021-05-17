#include "Headers.h"

/*
	Sequence Container
	Associative Container (���� �����̳�) : set / map >> key, value
	Unordered Container
*/

int  main()
{
	set<int> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	//s.insert(11);


	//	[����] 3�� �̹� �ִ� �����̴�. �� �Լ��� ���ϰ����� �� ����� �� �� �ִ�.
	//auto p = s.insert(3);
	pair<set<int>::iterator, bool> p = s.insert(3);
	if (p.second == true)
		;
	else
		cout << "�̹� �����ϴ� ���Ҷ� �߰��� �� ����" << endl;


	// structured binding
	auto [��ġ, ��������] = s.insert(100);
	// auto [ignore, ��������] = s.insert(100);   // ignore ���
	if (�������� == false)
		cout << "�߰� ����" << endl;


	for (int n : s)
		cout << n << " ";
	cout << endl;
}