#include "Headers.h"

/* 
	[문제] String 길이 오름차순으로 정렬하는 set을 구현하라
	'<' 연산자를 알려주면 된다.
*/

/*
	[문제] String을 사전 '순서대로 정렬 (lexicographical)'하고 싶다
	set이 이렇게 정렬하게 하려면 어떻게 하면 좋을까
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