#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <string>
#include <span>

#include "String.h"

using namespace std;

//template<typename T>
//void print(span<T> s)			// span : ���ӵ� �ֵ�
//{
//	for (T val : s)
//		cout << val << " ";
//	cout << endl;
//}

int main()
{
	// �޸𸮰� �پ��ִ� �ֵ�
	int a[]{ 3, 5, 1, 9, 7 };
	vector<int> v{ 3, 5, 1, 9, 7 };
	array<int, 5> arr{ 3, 5, 1, 9, 7 };
	string s{ "35197" };

	// ���� : 1, 3, 5, 7, 9�� �����

	sort(begin(a), end(a));
	sort(v.begin(), v.end());
	sort(arr.begin(), arr.end());
	sort(s.begin(), s.end());

	for (int n : a)
		cout << n << " ";
	cout << endl;
	//print(span<int>{a});


	// deque�� vector�� list�� �߰�
}