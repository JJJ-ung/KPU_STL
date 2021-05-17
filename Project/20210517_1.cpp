#include "Headers.h"

/*
	set, multiset : key만 있다
	map, multimap : key, value 한쌍
	>> key값으로 분류
*/

/*
	<key, value>
	[문제] 만화 이름을 key값으로, 주인공들을 value로
				예시) 원피스 - 루피, 상디, 초파
*/

int main()
{
	map<string, vector<string>> comics;

	comics.insert( pair<string, vector<string>>("원피스", {"루피", "초파", "우솝"}));

	comics.insert(make_pair("원펀맨", (vector<string>({ "사이타마", "제노스" }))));

	// 맵을 연관배열처럼 사용할 수 있다
	comics["머니게임"] = { "1호실남성", "8호실여성" };
	
	for (const auto& comic : comics)
	{
		cout << comic.first << " --> ";
		for (const auto& character : comic.second)
			cout << character << " ";
		cout << endl;
	}
}