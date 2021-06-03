#include "Headers.h"

int main()
{
	/*
		[�غ�] [1, 100] vector<int>�� �ִ´�
		v�� ���´�
		�˰��� �����Ѵ� (sort, partial sort, nth elemet)
		����� ����Ѵ�
	*/

	vector<int> v;
	for (int i = 0; i < 100; ++i)
		v.push_back(i + 1);

	random_device rd;
	default_random_engine eng{ rd() };
	{
		shuffle(v.begin(), v.end(), eng);

		sort(v.begin(), v.end());

		cout << endl;
		cout << "sort ���" << endl;
		for (int n : v)
			cout << n << " ";
		cout << endl;
	}

	{
		shuffle(v.begin(), v.end(), eng);

		partial_sort(v.begin(), v.begin() + 40, v.end());

		cout << endl;
		cout << "partial_sort ���" << endl;
		for (int n : v)
			cout << n << " ";
		cout << endl;
	}

	{
		shuffle(v.begin(), v.end(), eng);

		nth_element(v.begin(), v.begin() + 40, v.end());

		cout << endl;
		cout << "nth_element ���" << endl;
		for (int n : v)
			cout << n << " ";
		cout << endl;
	}
}