#include "Headers.h"

class ������
{
public:
	bool operator()(const String& a, const String& b)
	{
		a.getString() < b.getString();
	}
};

int main()
{
	/*
		[����] String�� ���� '������� ���� (lexicographical)'�ϰ� �ʹ�
		set�� �̷��� �����ϰ� �Ϸ��� ��� �ϸ� ������
	*/

	set<String, ������> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	for (const String& s : s)
		cout << s.getString() << endl;
}