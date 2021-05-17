#include "Headers.h"

/*
	[����] �ݺ��ڰ��� �Ÿ��� ����ϴ� my_distance�� �ۼ��϶�
	- �ݺ��� ������ ���� �ٸ� �ڵ带 �����Ѵ� 
		>> tag dispaching
		>> c++17 ���� : constexpr if
*/

template <class Iter>
int my_distance(Iter beg, Iter end)
{
	// ���� iter�� random_access���
	if constexpr (random_access_iterator<Iter>)	// C++ 20 concept
	{
		cout << "���� -���� ��� : ";  
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