#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// "�ҽ�.cpp"�� ���� �� �ҹ��ڸ� �빮�ڷ� �ٲ� ȭ�鿡 ����϶�

int main()
{
	ifstream in{ "�ҽ�.cpp" };
	vector<char> v;

	char c;

	while (in >> noskipws >> c)
	{
		//if (c >= 97 && c <= 122)
		//	c -= 32;
		v.push_back(c);
	}

	// v�� ���� �� �ҹ��ڸ� �빮�ڷ� �ٲ۴�
	for (char c : v)
		toupper(c);

	for (auto i = v.begin(); i < v.end(); ++i)
		cout << *i;
	cout << endl;
}