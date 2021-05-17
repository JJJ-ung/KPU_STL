#include "Headers.h"

int main()
{
	/*
	vector<int> v;
	list<int> con;

	cout << v.max_size() << endl;
	cout << con.max_size() << endl;

	// vector는 순서대로 (메모리 연속)
	// list는 연속 안되어있다
	*/

	/*
	vector<int> v{ 1, 2, 3, 4, 5 };
	reverse(v.begin(), v.end());
	*/

	list<int> v{ 1, 2, 3, 4, 5 };
	v.reverse();

	for (int n : v)
		cout << n << " ";
	cout << endl;
}