#include "Headers.h"

/*
	[����] "�ҽ�.cpp"�� �ܾ �о ���̰� 5 ������ �͵��� ȭ�鿡 ����ϰ�
	��� �� �������� ����϶�.
*/

int main()
{
	vector<string> v;

	ifstream fin{ "�ҽ�.cpp" };

	string tmp;
	while (fin >> tmp)
		v.emplace_back(tmp);

	int cnt = count_if(v.begin(), v.end(), [](const string& s)
		{
			if (s.size() <= 5)
			{
				cout << s << "\t";
				return true;
			}
			return false;
		});
	cout << endl;
	cout << "���̰� 5 ������ �͵� : " << cnt << endl;
}