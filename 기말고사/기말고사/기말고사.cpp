#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	ifstream in{ "THE ADVENTURES OF SHERLOCK HOLMES.txt"s };

	if (!in)
		return 0;


	// 문제 1

	vector<string> v1{ istream_iterator<string>{in}, {} };
	cout << v1.size() << endl;


	//문제2
	sort(v1.begin(), v1.end());
	vector<string> v1Unique;
	unique_copy(v1.begin(), v1.end(), back_inserter(v1Unique));

	vector<pair<string, int>> v1Count;
	for (auto s : v1Unique)
		v1Count.push_back(make_pair(s, count(v1.begin(), v1.end(), s)));
	sort(v1Count.begin(), v1Count.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) { return p1.second > p2.second; });

	for (int i = 0; i < 3; ++i)
		cout << v1Count[i].first << " - " << v1Count[i].second << endl;


	// 문제3
	ifstream word{ "단어들.txt" };
	vector<string> Words{ istream_iterator<string>{word}, {} };

	vector<string> v2;
	copy_if(v1.begin(), v1.end(), back_inserter(v2), [Words](const string& s) { return find(Words.begin(), Words.end(), s) == Words.end(); });
	sort(v2.begin(), v2.end());
	unique(v2.begin(), v2.end());

	ofstream out{ "test.txt" };
	for (auto s : v2)
		out << s << endl;
	cout << v2.size() << endl;
}