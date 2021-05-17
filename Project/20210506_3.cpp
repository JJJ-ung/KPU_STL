#include "Headers.h"

/*
	[����] "�ҽ�.cpp"�� �ܾ �о ���̰� 5 ������ �͵��� ȭ�鿡 ����ϰ�
	��� �� �������� ����϶�.
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
	ifstream fin{ "�ҽ�.cpp" };

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
	cout << "���̰� 5 ������ �͵� : " << cnt << endl;
}