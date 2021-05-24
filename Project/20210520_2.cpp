#include "Headers.h"
#include <array>

/*
	컨테이너들의 찾기 실력을 비교실험을 통해 알아본다
	각 대표 컨테이너에 String NUM개를 저장한다
*/

const int NUM = 100;								// 컨테이너 원소 수
const int FNUM = 3;									// 찾아볼 원소 수

uniform_int_distribution<> uid{ 0, NUM - 1 };

int main()
{
	vector<String> v;
	v.reserve(NUM);

	// v에 길이가 1부터 NUM까지 증가하는 String을 담아본다.
	for (int i = 0; i < NUM; ++i)
		v.emplace_back(i + 1);

	// v에 있는지 찾아볼 원소 FNUM개를 array에 저장한다
	array<String, FNUM> toFind;

	// 실제 벡터에 존재하는 우너소를 toFind에 저장한다
	for (int i = 0; i < FNUM; ++i)
		toFind[i] = v[uid(dre)];

	{
		// 벡터의 찾기 성능 실험
		cout << "벡터 시간" << endl;
		auto b = steady_clock::now();
		// 시간 측정 시작
		for (int j = 0; j < 10; ++j)
		{
			for (int i = 0; i < FNUM; ++i)
				find(v.begin(), v.end(), toFind[i]);
		}
		// 시간 측정 끝
		cout << "경과 시간 - " <<
			duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
	}


	for (int i = 0; i < FNUM; ++i)
	{
		auto p = find(v.begin(), v.end(), toFind[i]);
		if (p != v.end())
			cout << toFind[i] << "를 발견 - " << *p << endl;
	}

	{
		set<String> s{ v.begin(), v.end() };
	}
	{
		unordered_set<String> us{ v.begin(), v.end() };
	}
}