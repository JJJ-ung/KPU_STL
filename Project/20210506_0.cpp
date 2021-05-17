#include "Headers.h"

template<typename Iter, typename Val>
Iter my_find(Iter beg, Iter end, Val val)
{
	while (beg != end)
	{
		if (*beg == val)
			return beg;
		++beg;
	}
	return end;
}

int main()
{
	String s{ "the quick brown fox jumps over the lazy dog" };
	// [����] �ѱ��ڸ� �Է��ϸ� ���° �������� ����϶�
	// ������ ���ٰ� ����϶�

	cout << "���° �������� �˷��帮�ڽ��ϴ�" << endl;
	while (true)
	{
		cout << "ã�� ���ڸ� �Է��ϼ��� : ";
		char c;
		cin >> c;

		auto p = my_find(s.begin(), s.end(), c);
		if (p != s.end())
			cout << "��ġ " << distance(s.begin(), p) + 1 << "���� �߰�" << endl;
		else
			cout << "�� ã��" << endl;
	}
}