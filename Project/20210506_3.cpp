#include "Headers.h"

/*
	[문제] "소스.cpp"의 단어를 읽어서 길이가 5 이하인 것들을 화면에 출력하고
	모두 몇 개인지도 출력하라.
*/

template <class Iter, class Pred>
size_t my_count_if(Iter beg, Iter end, Pred func)
{
	size_t cnt = 0;
	while (beg != end)
	{
		if (func(*beg++))
			++cnt;
	}
	return cnt;
}

int main()
{
	ifstream fin{ "소스.cpp" };

	vector<string> v{ istream_iterator<string>{fin}, {} };

	int cnt = my_count_if(v.begin(), v.end(), [](const string& s)
		{
			if (s.size() <= 5)
			{
				cout << s << "\t";
				return true;
			}
			return false;
		});
	cout << endl;
	cout << "길이가 5 이하인 것들 : " << cnt << endl;
}