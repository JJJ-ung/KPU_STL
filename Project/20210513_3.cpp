#include "Headers.h"

/*
	[����] Ű���忡�� �ܾ set�� ������ �� ȭ�鿡 ����϶�.
*/

int main()
{
	set<string> s;

	string str;
	while (cin >> str)
	{
		if(str == "stop")
			break;
		s.insert(str);
	}
	cout << "�Է� ��" << endl;

	for (const string& s : s)
		cout << s << endl;
}