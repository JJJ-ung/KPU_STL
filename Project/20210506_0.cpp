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
	// [문제] 한글자를 입력하면 몇번째 글자인지 출력하라
	// 없으면 없다고 출력하라

	cout << "몇번째 글자인지 알려드리겠습니다" << endl;
	while (true)
	{
		cout << "찾을 글자를 입력하세요 : ";
		char c;
		cin >> c;

		auto p = my_find(s.begin(), s.end(), c);
		if (p != s.end())
			cout << "위치 " << distance(s.begin(), p) + 1 << "에서 발견" << endl;
		else
			cout << "못 찾음" << endl;
	}
}