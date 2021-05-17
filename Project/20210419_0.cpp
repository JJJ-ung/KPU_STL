#include <iostream>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;

// [문제] 리스트로 읽어와서 거꾸로 출력하기

int main()
{
	list<char> con;

	// list<char> con(반복자시작, 반복자끝);
	// #include <iterator> 해야한다

	ifstream in{ "20210415_3.cpp" };


	/*
	char c;
	while (in >> noskipws >> c)
		con.push_back(c);

	// 공백들이 입력이 안된다
	// 왜 무시함? 어캐 해결?
	// noskipws****
	*/


	char c;
	while (in >> noskipws >> c)
		con.push_front(c);

	
	/*
	con.reverse();
	for (char c : con)
		cout << c;
	*/


	/*
	// reverse begin, reverse end
	for (auto i = con.rbegin(); i != con.rend(); ++i)
		cout << *i;
	*/

	
	for (auto i = con.begin(); i != con.end(); ++i)
		cout << *i;
}