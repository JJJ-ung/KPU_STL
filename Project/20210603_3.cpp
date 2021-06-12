#include "Headers.h"

struct PS : public pair<string, string>
{
	PS(const string& str)
		: pair<string, string>(str, str)
	{
		sort(first.begin(), first.end());
	}
};

int main()
{
	ifstream in{ "�ܾ��.txt" };
	vector<PS> v{ istream_iterator<string>{in}, {} };

	sort(v.begin(), v.end(), [](const PS& a, const PS& b)	{ return a.first < b.first; });

	// anagram ã��
	while (true)
	{
		cout << ">> ";
		string str;
		cin >> str;

		// ã�� �ڵ�
		// �� str�� PS�� �����
		PS test(str);
		auto [����, ����] = equal_range(v.begin(), v.end(), test, 
			[](const PS& elem, const PS& val) { return elem.first < val.first; });
		// ���ĵǾ��ִ� range������ ���ư��� �ִ�
		// ���ĵ� ������ ������� equal �ϰ� ���ư��°�
		if (���� == ����)
		{
			cout << str << " not exists" << endl;
			continue;
		}

		cout << ���� - ���� << " anagram words : ";
		for (auto i = ����; i < ����; ++i)
			cout << i->second << "  ";
		cout << endl;
	}

	// ��� anagram ���� ã�ƶ�. ��� ��� �ֳ�?
}