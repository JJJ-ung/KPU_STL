#include <iostream>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <random>
#include <string>

using namespace std;

/*
	[����] main�� �����ϸ� �ȵȴ�.
	ȭ������� 2, 1�� �ǵ��� �ڵ��϶�.
*/

// using

class Dog
{
public:
	int i = 0;
};

void change(Dog& a, Dog& b)
{
	int tmp = a.i;
	a.i = b.i;
	b.i = tmp;
}

int main()
{
	Dog a{ 1 };
	Dog b{ 2 };

	change(a, b);

	//cout << a << ", " << b << endl;
}