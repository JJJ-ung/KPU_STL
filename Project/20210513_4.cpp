#include "Headers.h"

/*
	[����] "�ҽ�.cpp"�� ���ĺ��� ������������ �����ϵ��� set�� ����
	ȭ�鿡 set�� ����غ��� ����� �����غ���
*/

int main()
{
	//set<char> s;
	multiset<char> s;		// �ߺ� ���

	ifstream in{"20210513_4.cpp"};

	char c;
	while (in >> c)
	{
		if (isalpha(c))
			s.insert(c);
	}

	for (char c : s)
		cout << c;
	cout << endl;
}