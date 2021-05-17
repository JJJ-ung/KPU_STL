#include "Headers.h"

/*
	[문제] 키보드에서 단어를 set에 저장한 후 화면에 출력하라.
*/

int main()
{
	set<string> s;

	string str;
	while (cin >> str)
	{
		if(str == "stop")
			break;
		s.insert(str);
	}
	cout << "입력 끝" << endl;

	for (const string& s : s)
		cout << s << endl;
}