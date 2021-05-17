#include "Headers.h"

// Algorithm 작동 방식

template <class iter>
int my_distance(iter beg, iter end)
{
	// 반복자일때만 돌아가는 코드면 좋겠다.

	int cnt = 0;
	while (beg++ != end)
		++cnt;
	return cnt;
}

int main()
{
	vector<int> v{1, 2, 3};

	/*
		제네릭 함수
		my_distance(1, 2);
		my_distance("hello", "world");
		어떤 자료형이든 상관 없이 컴파일 된다
	*/

	cout << my_distance(1, 500) << endl;
	cout << my_distance("hello", "world") << endl;
	cout << my_distance(v.begin(), v.end()) << endl;
}