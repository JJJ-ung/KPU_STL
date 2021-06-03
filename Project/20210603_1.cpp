#include "Headers.h"

/*
	[문제] 사용자가 입력한 단어를 v에서 찾는다
	없으면 없다라고 출력
	있으면 있다라고 출력하고 이 단어와 anagram 관계를 갖는 모든 단어를 출력한다
*/

int main()
{
	ifstream in{ "단어들.txt" };
	vector<string> v{ istream_iterator<string>{in}, {} };
	
	cout << "ANAGRAM을 찾겠습니다" << endl;

	while (true)
	{
		cout << " >> ";
		string str;
		cin >> str;

		// str이 v에 있나 찾는다

		// 없으면
		if (!binary_search(v.begin(), v.end(), str))
		{
			cout << "없습니다" << endl;
			continue;
		}

		// 있으면
		cout << "Anagrams : ";
		sort(str.begin(), str.end());
		do {
			//if (binary_search(v.begin(), v.end(), str))
			//	cout << str << "● ";
			//else
			//	cout << str << "○ ";
			if (binary_search(v.begin(), v.end(), str))
				cout << str << " ";
		} while (next_permutation(str.begin(), str.end()));		// 정렬된 상태에서만 된다
		cout << endl;
	}
}