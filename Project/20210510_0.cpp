#include "Headers.h"

// Algorithm �۵� ���

template <class iter>
int my_distance(iter beg, iter end)
{
	// �ݺ����϶��� ���ư��� �ڵ�� ���ڴ�.

	int cnt = 0;
	while (beg++ != end)
		++cnt;
	return cnt;
}

int main()
{
	vector<int> v{1, 2, 3};

	/*
		���׸� �Լ�
		my_distance(1, 2);
		my_distance("hello", "world");
		� �ڷ����̵� ��� ���� ������ �ȴ�
	*/

	cout << my_distance(1, 500) << endl;
	cout << my_distance("hello", "world") << endl;
	cout << my_distance(v.begin(), v.end()) << endl;
}