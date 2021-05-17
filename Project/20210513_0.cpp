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

	my_copy(v1.begin(), v1.end(), back_inserter(v2) /*�ݺ���ó�� �ൿ������ �����δ� push_back()�� �ϴ� ��ü*/);
														  // back_inserter, front_inserter, inserter
														  // �̰Ŵ� ���� �����̰�, �Ʒ��� ���� ������ (back_insert_iterator)
	// my_copy(v1.begin(), v1.end(), back_insert_iterator<vector<int>>(v2));

	for (int n : v2)
		cout << n << " ";
	cout << endl;
}