#include "Headers.h"

int main()
{
	ifstream in{ "�ܾ��.txt" };

	vector<string> v{ istream_iterator<string>{in}, {} };
	cout << "��� " << v.size() << " �ܾ �о����ϴ�" << endl;

	// �ܾ���� ���ĵǾ� �ִٴµ� �³�?
	// ��ġ�� �ܾ�� ����?
	// string Ŭ������ ���� ���������� �о�´�

	cout << "���ĵǾ� �ֳ�? " << boolalpha << is_sorted(v.begin(), v.end()) << endl;

	//for (const string& s : v)
	//	cout << s << endl;

	// ��ġ�� �ܾ�� ����?

	if (unique(v.begin(), v.end()) == v.end())
		cout << "��ġ�� ���� ����" << endl;
	else
		cout << "�ߺ� ���� �߰�" << endl;
}

void tmp()
{
	vector<int> x{ 1, 2, 3, 4, 5, 5 };
	if (unique(x.begin(), x.end()) == x.end())
		cout << "��ġ�� ���� ����" << endl;
	else
		cout << "�ߺ� ���� �߰�" << endl;
}