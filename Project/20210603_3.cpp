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

	sort(v.begin(), v.end(), [](const PS& a, const PS& b)	{ return a.first < b.first; });

	// anagram 찾기
	while (true)
	{
		cout << ">> ";
		string str;
		cin >> str;

		// 찾는 코드
		// 얼른 str을 PS로 만든다
		PS test(str);
		auto [하한, 상한] = equal_range(v.begin(), v.end(), test, 
			[](const PS& elem, const PS& val) { return elem.first < val.first; });
		// 정렬되어있는 range에서만 돌아가는 애다
		// 정렬된 기준을 적어줘야 equal 하게 돌아가는것
		if (하한 == 상한)
		{
			cout << str << " not exists" << endl;
			continue;
		}

		cout << 상한 - 하한 << " anagram words : ";
		for (auto i = 하한; i < 상한; ++i)
			cout << i->second << "  ";
		cout << endl;
	}

	// 모든 anagram 쌍을 찾아라. 모두 몇개나 있나?
}