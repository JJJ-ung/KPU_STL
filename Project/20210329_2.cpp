#include <iostream>
#include <random>
#include <algorithm>

#include <array>

using namespace std;

template< typename t, int N >
class Array
{
public:
	Array() {}
	~Array() {}

public:
	size_t size() const	{ return N; }
};

int main()
{
	Array<int, 5> a;

	// 자료구조 a의 내용을 제곱하다.
	for (int i = 0; i < a.size(); ++i)
		a[i] *= a[i];
	// 자료구조 a의 내용을 출력하라
	for (int num : a)
		cout << num << " ";
	cout << endl;
}