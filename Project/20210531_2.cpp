#include "Headers.h"

int main()
{
	/*
		[준비] [1, 100] vector<int>에 넣는다
		v를 섞는다
		알고리즘 실행한다 (sort, partial sort, nth elemet)
		결과를 출력한다
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
		cout << "sort 결과" << endl;
		for (int n : v)
			cout << n << " ";
		cout << endl;
	}

	{
		shuffle(v.begin(), v.end(), eng);

		partial_sort(v.begin(), v.begin() + 40, v.end());

		cout << endl;
		cout << "partial_sort 결과" << endl;
		for (int n : v)
			cout << n << " ";
		cout << endl;
	}

	{
		shuffle(v.begin(), v.end(), eng);

		nth_element(v.begin(), v.begin() + 40, v.end());

		cout << endl;
		cout << "nth_element 결과" << endl;
		for (int n : v)
			cout << n << " ";
		cout << endl;
	}
}