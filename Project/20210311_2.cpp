#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;

/*
	[����] int 1000���� ������ �� �ִ� ������ Ȯ���Ѵ�
	������ ���� uid(dre)�� ä����
	���� "int õ��.txt"�� �����϶�.

	�о ������������ �����϶�.
	ȭ�鿡 ����϶�.
*/

default_random_engine dre;
uniform_int_distribution<> uid{ 0, 1000 };

// �����ϱ�
int main()
{
	// ���� �и��ϸ� ���� ���� ���� �� �� ����
	// �����ϱ�!
	{
		int num[1000] = {};

		ofstream out{ "int õ��.txt" };

		for (int& n : num)
		{
			n = uid(dre);
			out << n << ' ';
		}
	}

	// �ҷ�����!
	{
		ifstream in{ "int õ��.txt" };
		if (!in)
		{
			cout << "���� ���� ����" << endl;
			exit(0);
		}

		int a[1000];

		for (int& num : a)
			in >> num;

		sort(begin(a), end(a));

		for (int num : a)
			cout << num << "\t\t";
		cout << endl;
	}
}