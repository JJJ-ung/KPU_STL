#include "Headers.h"

/* 
	[����] String ���� ������������ �����ϴ� set�� �����϶�
	'<' �����ڸ� �˷��ָ� �ȴ�.
*/

/*
	[����] String�� ���� '������� ���� (lexicographical)'�ϰ� �ʹ�
	set�� �̷��� �����ϰ� �Ϸ��� ��� �ϸ� ������
*/

//struct t
//{
//	bool operator() (const String& a, const String& b) const
//	{
//		return a.size() < b.size();
//	}
//};

int main()
{
	//set<String, t> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	set<String> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	for (const String& s : s)
		cout << s << endl;
}