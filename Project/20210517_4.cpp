#include "Headers.h"

int main()
{
	/*
		[����] �ҽ��� �ִ� ������ ���Ƚ���� �˰� �ʹ�.
		[���� 2] Ƚ�� ������������ ����϶�
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