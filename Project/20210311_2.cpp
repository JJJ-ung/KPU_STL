#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;

/*
	[문제] int 1000개를 저장할 수 있는 공간을 확보한다
	정수의 값을 uid(dre)로 채워라
	파일 "int 천개.txt"에 저장하라.

	읽어서 오름차순으로 정렬하라.
	화면에 출력하라.
*/

default_random_engine dre;
uniform_int_distribution<> uid{ 0, 1000 };

// 저장하기
int main()
{
	// 지역 분리하면 지역 변수 따로 쓸 수 잇음
	// 저장하기!
	{
		int num[1000] = {};

		ofstream out{ "int 천개.txt" };

		for (int& n : num)
		{
			n = uid(dre);
			out << n << ' ';
		}
	}

	// 불러오기!
	{
		ifstream in{ "int 천개.txt" };
		if (!in)
		{
			cout << "파일 열기 실패" << endl;
			exit(0);
		}

		int a[1000];

		for (int& num : a)
			in >> num;

		sort(begin(a), end(a));

		for (int num : a)
			cout << num << "\t\t";
		cout << endl;
	}
}