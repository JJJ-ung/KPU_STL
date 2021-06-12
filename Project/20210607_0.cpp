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
	ifstream in{ "단어들.txt" };
	vector<PS> v{ istream_iterator<string>{in}, {} };

	sort(v.begin(), v.end(), [](const PS& a, const PS& b) { return a.first < b.first; });

	// 모든 anagram 쌍을 찾아라. 모두 몇개나 있나?

	int cnt = 0;
	auto i = v.begin();
	while (true)
	{
		// auto i = 현재 원소와 다음 원소의 first 값이 같은 위치를 찾는다
	
		i = adjacent_find(i, v.end(), [](const PS& a, const PS& b) { return a.first == b.first; });

		if ( i == v.end() )
			break;

		// j+ 1부터 검사 시작해서 first값이 일치하지 않는 위치를 찾는다
		auto j = find_if_not(i + 1, v.end(), [i](const PS& a) { return a.first == i->first; });
		
		// [i, j]는 애너그램 구간이다
		cout << "[" << ++cnt << "]-";
		for (auto x = i; x < j; ++x)
			cout << x->second << "  ";
		cout << endl;

		i = j;
	}
}