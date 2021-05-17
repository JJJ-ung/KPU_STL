#include "Headers.h"

/*
	[문제] 반복자간의 거리를 계산하는 my_distance를 작성하라
	- 반복자 종류에 따라 다른 코드를 실행한다 
		>> tag dispaching
		>> c++17 이후 : constexpr if
*/

template <class Iter>
int my_distance(Iter beg, Iter end)
{
	// 만일 iter가 random_access라면
	if constexpr (random_access_iterator<Iter>)	// C++ 20 concept
	{
		cout << "랜덤 -으로 계산 : ";  
		return end - beg;
	}
	else
	{
		int cnt = 0;
		while (beg++ != end)
			++cnt;
		return cnt;
	}
}

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	cout << my_distance(v.begin(), v.end()) << endl;

	String s{ "1234567890" };
	cout << my_distance(s.begin(), s.end()) << endl;

	list<int> con{ 1, 2, 3 };
	cout << my_distance(con.begin(), con.end()) << endl;
}