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

	sort(v.begin(), v.end(), [](const PS& a, const PS& b) { return a.first < b.first; });

	// ��� anagram ���� ã�ƶ�. ��� ��� �ֳ�?
	// ���� ������ ���� anagram�� �����?
	// ���� ������������ �����Ͽ� ���� "�ֳʱ׷�������������.txt"

	auto i = v.begin();
	vector<list<string>> anagrams;
	anagrams.reserve(32000);			// �� ���� ����

	while (true)
	{
		// auto i = ���� ���ҿ� ���� ������ first ���� ���� ��ġ�� ã�´�

		i = adjacent_find(i, v.end(), [](const PS& a, const PS& b) { return a.first == b.first; });

		if (i == v.end())
			break;

		// j+ 1���� �˻� �����ؼ� first���� ��ġ���� �ʴ� ��ġ�� ã�´�
		auto j = find_if_not(i + 1, v.end(), [i](const PS& a) { return a.first == i->first; });

		// [i, j]�� �ֳʱ׷� �����̴�
		list<string> anagram;
		for (auto x = i; x < j; ++x)
			anagram.push_back(x->second);
		anagrams.push_back(anagram);

		i = j;
	}

	// ���� ������������ ����
	sort(anagrams.begin(), anagrams.end(), [](const list<string>& a, const list<string>& b) { return a.size() > b.size(); });

	// ���� "�ֳʱ׷�������������.txt"�� ���
	int cnt = 0;
	ofstream out{ "�ֳʱ׷�������������.txt" };
	for (list<string>& anagram : anagrams)
	{
		out << "[" << ++cnt << "]-";
		anagram.sort();
		for (const string& word : anagram)
			out << word << "  ";
		out << endl;
	}
	out << "���� ������ ���� ���� - " << anagrams[0].size() << endl;
}
