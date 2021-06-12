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
	// 가장 개수가 많은 anagram은 어떤거지?
	// 개수 내림차순으로 정렬하여 파일 "애너그램개수많은순서.txt"

	auto i = v.begin();
	vector<list<string>> anagrams;
	anagrams.reserve(32000);			// 총 쌍의 개수

	while (true)
	{
		// auto i = 현재 원소와 다음 원소의 first 값이 같은 위치를 찾는다

		i = adjacent_find(i, v.end(), [](const PS& a, const PS& b) { return a.first == b.first; });

		if (i == v.end())
			break;

		// j+ 1부터 검사 시작해서 first값이 일치하지 않는 위치를 찾는다
		auto j = find_if_not(i + 1, v.end(), [i](const PS& a) { return a.first == i->first; });

		// [i, j]는 애너그램 구간이다
		list<string> anagram;
		for (auto x = i; x < j; ++x)
			anagram.push_back(x->second);
		anagrams.push_back(anagram);

		i = j;
	}

	// 길이 내림차순으로 정렬
	sort(anagrams.begin(), anagrams.end(), [](const list<string>& a, const list<string>& b) { return a.size() > b.size(); });

	// 파일 "애너그램개수많은순서.txt"에 기록
	int cnt = 0;
	ofstream out{ "애너그램개수많은순서.txt" };
	for (list<string>& anagram : anagrams)
	{
		out << "[" << ++cnt << "]-";
		anagram.sort();
		for (const string& word : anagram)
			out << word << "  ";
		out << endl;
	}
	out << "가장 개수가 많은 조합 - " << anagrams[0].size() << endl;
}
