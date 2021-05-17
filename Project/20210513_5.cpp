#include "Headers.h"

// [문제] 정수를 홀짝 순서로 정렬하는 set을 만들어라

class 홀짝
{
public:
	bool operator() (int a, int b) const
	{
		// b가 홀수이면 swap
		if (b & 1)
			return true;
		return false;
	}
};

int main()
{
	set<int, 홀짝> s{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 2번째 인자가 정렬 기준 (자료형) >> pred

	for (auto i : s)
		cout << i << ' ';
	cout << endl;
}