#include "Headers.h"

extern default_random_engine dre;
uniform_int_distribution<> uid{ 1, 1000 };
// event의 확률이 균등하다 (1000만번 부르면 1 만개, 2 만개, ....)

int main()
{
	//map<int, int> m;
	//for (int i = 0; i < 1000'0000; ++i)
	//	m[uid(dre)]++;

	//for (auto c : m)
	//	cout << "[" << c.first << "] -> " << c.second << endl;

	/*
		[문제] 랜덤값이 1~1000까지 나온다.
		이것을 10구간으로 나누어 횟수를 출력하라.	
		* 예시)
			[1~100] ->
			[101 ~ 200] ->
			.
			.
			.
			[901 ~ 1000] ->
	*/

	// ★★★★★★★★★★★★★★이런거 시험★★★★★★★★★★★★★★

	map<int, int> m;
	for (int i = 0; i < 1000'0000; ++i)
		m[(uid(dre) - 1) / 100]++;

	for (auto c : m)
		cout << "[" << c.first * 100 + 1 << "~" << c.first * 100 + 100 << "] -> " << c.second << endl;
}