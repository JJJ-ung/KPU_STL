#include "Headers.h"

extern default_random_engine dre;
uniform_int_distribution<> uid{ 1, 1000 };
// event�� Ȯ���� �յ��ϴ� (1000���� �θ��� 1 ����, 2 ����, ....)

int main()
{
	//map<int, int> m;
	//for (int i = 0; i < 1000'0000; ++i)
	//	m[uid(dre)]++;

	//for (auto c : m)
	//	cout << "[" << c.first << "] -> " << c.second << endl;

	/*
		[����] �������� 1~1000���� ���´�.
		�̰��� 10�������� ������ Ƚ���� ����϶�.	
		* ����)
			[1~100] ->
			[101 ~ 200] ->
			.
			.
			.
			[901 ~ 1000] ->
	*/

	// �ڡڡڡڡڡڡڡڡڡڡڡڡڡ��̷��� ����ڡڡڡڡڡڡڡڡڡڡڡڡڡ�

	map<int, int> m;
	for (int i = 0; i < 1000'0000; ++i)
		m[(uid(dre) - 1) / 100]++;

	for (auto c : m)
		cout << "[" << c.first * 100 + 1 << "~" << c.first * 100 + 100 << "] -> " << c.second << endl;
}