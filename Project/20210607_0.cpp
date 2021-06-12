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

	int cnt = 0;
	auto i = v.begin();
	while (true)
	{
		// auto i = ���� ���ҿ� ���� ������ first ���� ���� ��ġ�� ã�´�
	
		i = adjacent_find(i, v.end(), [](const PS& a, const PS& b) { return a.first == b.first; });

		if ( i == v.end() )
			break;

		// j+ 1���� �˻� �����ؼ� first���� ��ġ���� �ʴ� ��ġ�� ã�´�
		auto j = find_if_not(i + 1, v.end(), [i](const PS& a) { return a.first == i->first; });
		
		// [i, j]�� �ֳʱ׷� �����̴�
		cout << "[" << ++cnt << "]-";
		for (auto x = i; x < j; ++x)
			cout << x->second << "  ";
		cout << endl;

		i = j;
	}
}