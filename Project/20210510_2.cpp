#include "Headers.h"
#include <forward_list>

/*
	[문제] 반복자간의 거리를 계산하는 my_distance를 작성하라
*/

template <class iter>
int my_distance(iter beg, iter end)
{
	/*
	// 반복자만 아니라면 -1을 리턴
	if (typeid(iterator_traits<iter>::iterator_category) == typeid(bidirectional_iterator_tag))
		cout << "리스트 반복자" << endl;
	else
		cout << "반복자가 아니다" << endl; return -1;
	*/

	// 만일 iter가 random_access라면
	return end - begin;

	int cnt = 0;
	while (beg++ != end)
		++cnt;
	return cnt;
}

int main()
{
	list<int> con{ 1, 2, 3 };
	cout << my_distance(1, 100) << endl;
	cout << my_distance(con.begin(), con.end()) << endl;

	//forward_list<int> con{ 1, 2, 3 };
	//cout << my_distance(con.begin(), con.end()) << endl;

	vector<int> v{ 1, 2, 3, 4, 5 };
	cout << my_distance(v.begin(), v.end()) << endl;
}