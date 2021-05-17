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
	[문제] main을 변경하면 안된다.
	화면출력이 2, 1이 되도록 코딩하라.
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