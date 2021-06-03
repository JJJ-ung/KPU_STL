#include "Headers.h"

// 조건에 맞는 것과 그렇지 않은 것들을 서로 분리한다

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//분리가 시작되는 위치 = partition(v.begin(), v.end(), 홀수일때 참을 리턴하는 predicate);
	//auto p = partition(v.begin(), v.end(), [](int n) { return n & 1; });
	// 1, 9, 3, 7, 5

	auto p = stable_partition(v.begin(), v.end(), [](int n) { return n & 1; });
	// 1, 3, 5, 7, 9

	cout << "홀수 입니다" << endl;
	copy(v.begin(), p, ostream_iterator<int>{cout, " "});
	cout << endl;

	cout << "짝수 입니다" << endl;
	copy(p, v.end(), ostream_iterator<int>{cout, " "});
	cout << endl;

	for (int n : v)
		cout << n << " ";
	cout << endl;
}