#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

/*
	[����] "�ҽ�.cpp"�� �ܾ� ������ �о� list�� �����϶�
	list�� ������������ ������ �� ���ٿ� �Ѱ��� ����϶�
*/

int main()
{
	ifstream in{ "save.cpp" };

	list<string> con(istream_iterator<string>{in}, {});

	con.sort();

	for (auto i = con.begin(); i != con.end(); ++i)
		cout << *i << endl;
}