#include "Headers.h"

// ���ǿ� �´� �Ͱ� �׷��� ���� �͵��� ���� �и��Ѵ�

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//�и��� ���۵Ǵ� ��ġ = partition(v.begin(), v.end(), Ȧ���϶� ���� �����ϴ� predicate);
	//auto p = partition(v.begin(), v.end(), [](int n) { return n & 1; });
	// 1, 9, 3, 7, 5

	auto p = stable_partition(v.begin(), v.end(), [](int n) { return n & 1; });
	// 1, 3, 5, 7, 9

	cout << "Ȧ�� �Դϴ�" << endl;
	copy(v.begin(), p, ostream_iterator<int>{cout, " "});
	cout << endl;

	cout << "¦�� �Դϴ�" << endl;
	copy(p, v.end(), ostream_iterator<int>{cout, " "});
	cout << endl;

	for (int n : v)
		cout << n << " ";
	cout << endl;
}