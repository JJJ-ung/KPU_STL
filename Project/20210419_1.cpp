#include <iostream>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;

// [����] ����Ʈ�� �о�ͼ� �Ųٷ� ����ϱ�

int main()
{
	// list<char> con(�ݺ��ڽ���, �ݺ��ڳ�);
	// #include <iterator> �ؾ��Ѵ�

	ifstream in{ "20210415_3.cpp" };

	list<char> con(istreambuf_iterator<char>{in}, {});
	// istream_iterator : �׳� ���� ���õȴ�
	// istreambuf_iterator : ���� �״�� �о�´�

	for (auto i = con.begin(); i != con.end(); ++i)
		cout << *i;
}