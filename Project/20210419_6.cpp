#include "Headers.h"

int main()
{
	/*
		[문제] "소스.cpp"을 읽어 컨테이너에 저장한 후
		소문자를 대문자로 바꿔 화면 출력하라.

	ifstream in{ "소스.cpp" };

	vector<char> v(istreambuf_iterator<char>{in}, {});
	for (char& c : v)
		c = toupper(c);
	for (char c : v)
		cout << c;
	*/


	string str = "abc";
	transform(str.cbegin(), str.cend(), str.begin(), toupper);
	cout << str << endl;

	/*
		[문제] "소스.cpp"에 using이라는 단어가 있나 찾아라
		있다면 몇번째 단어인지 출력하라

	ifstream in{ "소스.cpp" };

	string str;
	list<string> con;

	while (in >> str)
		con.push_back(str);

	string toFind{ "using" };
	//find(con.begin(), con.end(), "using");
	list<string>::iterator p = find(con.begin(), con.end(), toFind);

	if (p == con.end())
		cout << toFind << "는 없습니다" << endl;
	else
		cout << distance(con.begin(), p) + 1 << "번째 단어입니다" << endl;
	*/


	/*
		[도전과제] "소스.cpp"의 string을 뒤집어 출력하라
	*/

}