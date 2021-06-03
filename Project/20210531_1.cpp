#include "Headers.h"

/*
	���� ���� �˰����� ������ �� �ȴ�

	stable_sort - equivalence�� (������) ������ ������ �����Ѵ�
	sort - [1, N] 1����� N����� �����Ѵ�
	partial_sort - 1����� 10��������� �����Ѵ�
	nth_element - 10������� �������� �и��Ѵ�
*/

int main()
{
	vector<pair<int, int>> v;
	//for (int i = 0; i < 100; ++i)
	//	v.push_back(make_pair(i + 1, 100 - i));
	for (int i = 0; i < 100; ++i)
		v.push_back(make_pair((i + 1)%10, 100 - i));

	// ���� 1 ������������ �����ϱ�
	//sort(v.begin(), v.end(), [](const pair<int, int>& a, const auto& b) { return a.first < b.first; });
	stable_sort(v.begin(), v.end(), [](const pair<int, int>& a, const auto& b) { return a.first < b.first; });

	for (const auto& [����1, ����2] : v)
		cout << ����1 << "---" << ����2 << endl;
}