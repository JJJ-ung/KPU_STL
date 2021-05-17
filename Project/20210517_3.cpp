#include "Headers.h"

int main()
{
	// 맵을 연관배열처럼 사용할 수 있다
	/*
		[문제] 소스에 있는 문자의 사용횟수를 알고 싶다.
		[문제 1] 셜록홈즈의 모험에 나오는 알파벳의 횟수를 출력하라
	*/

	map<char, int> freq;							// alphabet frequency

	//freq['a'];												// 무슨일이 일어나나
	//freq['a'] = 100;									// write access
	//cout << freq['a'] << endl;				// read

	ifstream fin{ "소스.cpp" };

	char c;
	while (fin >> c)
	{
		if(islower(c))
			freq[c]++;
	}

	for (auto c : freq)
		cout << "[" << c.first << "] -> " << c.second << endl;
}