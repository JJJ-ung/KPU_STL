#include <iostream>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;

// [문제] 리스트로 읽어와서 거꾸로 출력하기

int main()
{
	// list<char> con(반복자시작, 반복자끝);
	// #include <iterator> 해야한다

	ifstream in{ "20210415_3.cpp" };

	list<char> con(istreambuf_iterator<char>{in}, {});
	// istream_iterator : 그냥 공백 무시된다
	// istreambuf_iterator : 버퍼 그대로 읽어온다

	for (auto i = con.begin(); i != con.end(); ++i)
		cout << *i;
}