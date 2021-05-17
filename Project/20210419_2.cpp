#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

/*
	[문제] "소스.cpp"를 단어 단위로 읽어 list에 저장하라
	list를 오름차순으로 정렬한 후 한줄에 한개씩 출력하라
*/

int main()
{
	ifstream in{ "save.cpp" };

	list<string> con(istream_iterator<string>{in}, {});

	con.sort();

	for (auto i = con.begin(); i != con.end(); ++i)
		cout << *i << endl;
}