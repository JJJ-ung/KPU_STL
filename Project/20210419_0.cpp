#include <iostream>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;

// [����] ����Ʈ�� �о�ͼ� �Ųٷ� ����ϱ�

int main()
{
	list<char> con;

	// list<char> con(�ݺ��ڽ���, �ݺ��ڳ�);
	// #include <iterator> �ؾ��Ѵ�

	ifstream in{ "20210415_3.cpp" };


	/*
	char c;
	while (in >> noskipws >> c)
		con.push_back(c);

	// ������� �Է��� �ȵȴ�
	// �� ������? ��ĳ �ذ�?
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