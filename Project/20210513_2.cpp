#include "Headers.h"

/*
	[문제] set이 내림차순 정렬되도록
*/

int main()
{
	//set<int, less<int>> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	set<int, greater<int>> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	for (int n : s)
		cout << n << " ";
	cout << endl;
}