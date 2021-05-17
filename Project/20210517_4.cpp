#include "Headers.h"

int main()
{
	/*
		[문제] 소스에 있는 문자의 사용횟수를 알고 싶다.
		[문제 2] 횟수 내림차순으로 출력하라
	*/

	map<char, int> freq;							// alphabet frequency
	ifstream fin{ "THE ADVENTURES OF SHERLOCK HOLMES.txt" };

	char c;
	while (fin >> c)
	{
		if (islower(c))
			freq[c]++;
	}

	map<int, char, greater<int>> freq2;
	for (const pair<char, int>& p : freq)
		freq2[p.second] = p.first;
		//freq2.insert(make_pair(p.second, p.first));

	for (auto c : freq2)
		cout  << c.second << " -> [" << c.first << "]" << endl;

	//for (auto c : freq)
	//	cout << "[" << c.first << "] -> " << c.second << endl;
}