#include "Headers.h"
#include <array>

/*
	�����̳ʵ��� ã�� �Ƿ��� �񱳽����� ���� �˾ƺ���
	�� ��ǥ �����̳ʿ� String NUM���� �����Ѵ�
*/

const int NUM = 100;								// �����̳� ���� ��
const int FNUM = 3;									// ã�ƺ� ���� ��

uniform_int_distribution<> uid{ 0, NUM - 1 };

int main()
{
	vector<String> v;
	v.reserve(NUM);

	// v�� ���̰� 1���� NUM���� �����ϴ� String�� ��ƺ���.
	for (int i = 0; i < NUM; ++i)
		v.emplace_back(i + 1);

	// v�� �ִ��� ã�ƺ� ���� FNUM���� array�� �����Ѵ�
	array<String, FNUM> toFind;

	// ���� ���Ϳ� �����ϴ� ��ʼҸ� toFind�� �����Ѵ�
	for (int i = 0; i < FNUM; ++i)
		toFind[i] = v[uid(dre)];

	{
		// ������ ã�� ���� ����
		cout << "���� �ð�" << endl;
		auto b = steady_clock::now();
		// �ð� ���� ����
		for (int j = 0; j < 10; ++j)
		{
			for (int i = 0; i < FNUM; ++i)
				find(v.begin(), v.end(), toFind[i]);
		}
		// �ð� ���� ��
		cout << "��� �ð� - " <<
			duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
	}


	for (int i = 0; i < FNUM; ++i)
	{
		auto p = find(v.begin(), v.end(), toFind[i]);
		if (p != v.end())
			cout << toFind[i] << "�� �߰� - " << *p << endl;
	}

	{
		set<String> s{ v.begin(), v.end() };
	}
	{
		unordered_set<String> us{ v.begin(), v.end() };
	}
}