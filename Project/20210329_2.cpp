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

	// �ڷᱸ�� a�� ������ �����ϴ�.
	for (int i = 0; i < a.size(); ++i)
		a[i] *= a[i];
	// �ڷᱸ�� a�� ������ ����϶�
	for (int num : a)
		cout << num << " ";
	cout << endl;
}