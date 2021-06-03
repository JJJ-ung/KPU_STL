#include "Headers.h"

int main()
{
	ifstream in{ "단어들.txt" };

	vector<string> v{ istream_iterator<string>{in}, {} };
	cout << "모두 " << v.size() << " 단어를 읽었습니다" << endl;

	// 단어들이 정렬되어 있다는데 맞나?
	// 겹치는 단어는 없나?
	// string 클래스는 원래 사전식으로 읽어온다

	cout << "정렬되어 있나? " << boolalpha << is_sorted(v.begin(), v.end()) << endl;

	//for (const string& s : v)
	//	cout << s << endl;

	// 겹치는 단어는 없나?

	if (unique(v.begin(), v.end()) == v.end())
		cout << "겹치는 것이 없다" << endl;
	else
		cout << "중복 원소 발견" << endl;
}

void tmp()
{
	vector<int> x{ 1, 2, 3, 4, 5, 5 };
	if (unique(x.begin(), x.end()) == x.end())
		cout << "겹치는 것이 없다" << endl;
	else
		cout << "중복 원소 발견" << endl;
}