#include "Headers.h"
#include <forward_list>

/*
	[����] �ݺ��ڰ��� �Ÿ��� ����ϴ� my_distance�� �ۼ��϶�
*/

template <class iter>
int my_distance(iter beg, iter end)
{
	/*
	// �ݺ��ڸ� �ƴ϶�� -1�� ����
	if (typeid(iterator_traits<iter>::iterator_category) == typeid(bidirectional_iterator_tag))
		cout << "����Ʈ �ݺ���" << endl;
	else
		cout << "�ݺ��ڰ� �ƴϴ�" << endl; return -1;
	*/

	// ���� iter�� random_access���
	return end - begin;

	int cnt = 0;
	while (beg++ != end)
		++cnt;
	return cnt;
}

int main()
{
	list<int> con{ 1, 2, 3 };
	cout << my_distance(1, 100) << endl;
	cout << my_distance(con.begin(), con.end()) << endl;

	//forward_list<int> con{ 1, 2, 3 };
	//cout << my_distance(con.begin(), con.end()) << endl;

	vector<int> v{ 1, 2, 3, 4, 5 };
	cout << my_distance(v.begin(), v.end()) << endl;
}