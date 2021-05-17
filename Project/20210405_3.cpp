#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// "소스.cpp"를 읽은 후 소문자를 대문자로 바꿔 화면에 출력하라

int main()
{
	ifstream in{ "소스.cpp" };
	vector<char> v;

	char c;

	while (in >> noskipws >> c)
	{
		//if (c >= 97 && c <= 122)
		//	c -= 32;
		v.push_back(c);
	}

	// v의 문자 중 소문자를 대문자로 바꾼다
	for (char c : v)
		toupper(c);

	for (auto i = v.begin(); i < v.end(); ++i)
		cout << *i;
	cout << endl;
}