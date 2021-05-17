#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	ifstream in{ "THE ADVENTURES OF SHERLOCK HOLMES.txt"s };

	list<string> con(istream_iterator<string>{in}, {});
	cout << con.size() << endl;

	//list<string>::iterator p = find(con.begin(), con.end(), "Mauritius");
	//cout << distance(con.begin(), p) << endl;

	auto p = find(con.begin(), con.end(), "Mauritius");
	if (p == con.end())
		cout << "없다'" << endl;
	else
		cout << distance(con.begin(), p) + 1 << endl;

	for (auto iter = con.begin(); iter != con.end(); ++iter)
		transform((*iter).cbegin(), (*iter).cend(), (*iter).begin(), toupper);

	string word;
	while (true)
	{
		cin >> word;
		string originWord = word;
		transform(word.cbegin(), word.cend(), word.begin(), toupper);
		if (word == "그만")
			break;
		else
		{
			//int cnt = count(con.begin(), con.end(), word);
			int cnt = count_if(con.begin(), con.end(), [word](string& s)
				{
					// 다 소문자로 변환
					for (char& c : s)
						c = toupper(c);
					return s == word;
				});
			cout << originWord << "-" << cnt << "번 사용되었습니다" << endl;
		}
	}

	//for (auto iter = con.begin(); iter != con.end(); ++iter)
	//	transform((*iter).cbegin(), (*iter).cend(), (*iter).begin(), toupper);

	con.sort();
	con.unique();
	cout << con.size() << endl;
	
	//int cnt = 0;
	//for (auto str : con)
	//{
	//	if (str.find('Z') != string::npos)
	//		++cnt;
	//}
	//cout << cnt << endl;

	int cnt = count_if(con.begin(), con.end(), [](const string& s)
		{
			if (s.find('Z') != string::npos)
			{
				cout << s << "/";
				return true;
			}
			return false;
		});
	cout << cnt << endl;

}