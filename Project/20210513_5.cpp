#include "Headers.h"

// [����] ������ Ȧ¦ ������ �����ϴ� set�� ������

class Ȧ¦
{
public:
	bool operator() (int a, int b) const
	{
		// b�� Ȧ���̸� swap
		if (b & 1)
			return true;
		return false;
	}
};

int main()
{
	set<int, Ȧ¦> s{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 2��° ���ڰ� ���� ���� (�ڷ���) >> pred

	for (auto i : s)
		cout << i << ' ';
	cout << endl;
}