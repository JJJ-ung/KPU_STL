#include "Headers.h"
#include "String.h"

//String_iterator my_find(String_iterator beg, String_iterator end, char c)
//{
//	while (beg != end)
//	{
//		if (*beg == c)
//			return beg;
//		++beg;
//	}
//	return end;
//}

template<typename �ݺ���, typename ��>
�ݺ��� my_find(�ݺ��� beg, �ݺ��� end, �� c)
{
	while (beg != end)
	{
		if (*beg == c)
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