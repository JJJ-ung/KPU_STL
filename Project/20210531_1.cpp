#include "Headers.h"

/*
	정렬 관련 알고리즘을 구분할 줄 안다

	stable_sort - equivalence한 (동등한) 원소의 순서를 유지한다
	sort - [1, N] 1등부터 N등까지 정렬한다
	partial_sort - 1등부터 10ㄷ등까지를 정렬한다
	nth_element - 10등까지와 나머지를 분리한다
*/

int main()
{
	vector<pair<int, int>> v;
	//for (int i = 0; i < 100; ++i)
	//	v.push_back(make_pair(i + 1, 100 - i));
	for (int i = 0; i < 100; ++i)
		v.push_back(make_pair((i + 1)%10, 100 - i));

	// 기준 1 오름차순으로 정렬하기
	//sort(v.begin(), v.end(), [](const pair<int, int>& a, const auto& b) { return a.first < b.first; });
	stable_sort(v.begin(), v.end(), [](const pair<int, int>& a, const auto& b) { return a.first < b.first; });

	for (const auto& [기준1, 기준2] : v)
		cout << 기준1 << "---" << 기준2 << endl;
}