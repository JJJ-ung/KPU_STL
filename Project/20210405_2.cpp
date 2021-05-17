#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
 	ifstream in{ "¼Ò½º.cpp" };
	vector<char> v;

	char c;

	while (in >> noskipws >> c)
	{
		cout << c;
		v.push_back(c);
	}

	for (auto i = v.rbegin(); i < v.rend(); ++i)
		cout << *i;
	cout << endl;
}