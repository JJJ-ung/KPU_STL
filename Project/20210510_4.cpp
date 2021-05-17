#include "Headers.h"

/*
	알고리즘 copy
	copy(여기부터, 여기까지를, 저기로 복사);

	[문제] 키보드 입력의 처음부터, 마지막까지를, 화면에 복사
*/

template<class InIter, class OutIter>
OutIter my_copy(InIter beg, InIter end, OutIter dst)
{
	while (beg != end)
		*dst++ = *beg++;
	return dst;
}

// 키보드로 입력한 모든 단어를 파일 "단어들.txt"에 저장하라
// my_copy를 이용할 것

int main()
{
	//copy(키보드로입력시작, 키보드입력끝, 모니터로);
	//my_copy(istreambuf_iterator<char>{cin}, {}, ostream_iterator<char>{cout});		// cout 대신에 : cerr, clog

	//ofstream fout{ "단어들.txt" };
	//my_copy(istreambuf_iterator<String>{cin}, {}, ostream_iterator<String>{fout, "\n"});

	vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<int> v2;
	v2.resize(v1.size());

	my_copy(v1.begin(), v1.end(), v2.begin());

	for (int n : v2)
		cout << n << " ";
	cout << endl;
}