#include "Headers.h"

/*
	[����] �ܾ��.txt�� ���Ϳ� �����ϰ�
	��� �� �ܾ����� ����϶�
*/

int main()
{
	ifstream in{ "�ܾ��.txt"s };
	if (!in)
	{
		cout << "������ �� �� �����ϴ�" << endl;
		return 0;
	}

	string s;
	while (!in.eof())
	{
		in >> s;
		cout << s << " ";
	}

	// �ܾ �Է��ϼ���
	// �� �ܾ�� �����ϴ�
	// �� �ܾ�� ���� �ܾ��� anagram ���� �Դϴ�
	// tablet >> battle : anagram ����
}