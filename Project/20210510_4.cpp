#include "Headers.h"

/*
	�˰��� copy
	copy(�������, ���������, ����� ����);

	[����] Ű���� �Է��� ó������, ������������, ȭ�鿡 ����
*/

template<class InIter, class OutIter>
OutIter my_copy(InIter beg, InIter end, OutIter dst)
{
	while (beg != end)
		*dst++ = *beg++;
	return dst;
}

// Ű����� �Է��� ��� �ܾ ���� "�ܾ��.txt"�� �����϶�
// my_copy�� �̿��� ��

int main()
{
	//copy(Ű������Է½���, Ű�����Է³�, ����ͷ�);
	//my_copy(istreambuf_iterator<char>{cin}, {}, ostream_iterator<char>{cout});		// cout ��ſ� : cerr, clog

	//ofstream fout{ "�ܾ��.txt" };
	//my_copy(istreambuf_iterator<String>{cin}, {}, ostream_iterator<String>{fout, "\n"});

	vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<int> v2;
	v2.resize(v1.size());

	my_copy(v1.begin(), v1.end(), v2.begin());

	for (int n : v2)
		cout << n << " ";
	cout << endl;
}