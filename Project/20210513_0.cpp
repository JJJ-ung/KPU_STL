#include "Headers.h"

template<class InIter, class OutIter>
OutIter my_copy(InIter beg, InIter end, OutIter dst)
{
	while (beg != end)
		*dst++ = *beg++;
	return dst;
}

int main()
{
	vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<int> v2;
	v2.reserve(100);

	my_copy(v1.begin(), v1.end(), back_inserter(v2) /*반복자처럼 행동하지만 실제로는 push_back()을 하는 객체*/);
														  // back_inserter, front_inserter, inserter
														  // 이거는 간이 형식이고, 아래가 정식 형태임 (back_insert_iterator)
	// my_copy(v1.begin(), v1.end(), back_insert_iterator<vector<int>>(v2));

	for (int n : v2)
		cout << n << " ";
	cout << endl;
}