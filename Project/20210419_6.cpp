#include "Headers.h"

int main()
{
	/*
		[����] "�ҽ�.cpp"�� �о� �����̳ʿ� ������ ��
		�ҹ��ڸ� �빮�ڷ� �ٲ� ȭ�� ����϶�.

	ifstream in{ "�ҽ�.cpp" };

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
		[����] "�ҽ�.cpp"�� using�̶�� �ܾ �ֳ� ã�ƶ�
		�ִٸ� ���° �ܾ����� ����϶�

	ifstream in{ "�ҽ�.cpp" };

	string str;
	list<string> con;

	while (in >> str)
		con.push_back(str);

	string toFind{ "using" };
	//find(con.begin(), con.end(), "using");
	list<string>::iterator p = find(con.begin(), con.end(), toFind);

	if (p == con.end())
		cout << toFind << "�� �����ϴ�" << endl;
	else
		cout << distance(con.begin(), p) + 1 << "��° �ܾ��Դϴ�" << endl;
	*/


	/*
		[��������] "�ҽ�.cpp"�� string�� ������ ����϶�
	*/

}