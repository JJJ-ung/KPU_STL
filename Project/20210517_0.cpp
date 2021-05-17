#include "Headers.h"

class 사전식
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
		[문제] String을 사전 '순서대로 정렬 (lexicographical)'하고 싶다
		set이 이렇게 정렬하게 하려면 어떻게 하면 좋을까
	*/

	set<String, 사전식> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	for (const String& s : s)
		cout << s.getString() << endl;
}