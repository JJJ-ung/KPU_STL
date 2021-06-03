#include "Headers.h"

/*
	[문제] 단어들.txt를 벡터에 저장하고
	모두 몇 단어인지 출력하라
*/

int main()
{
	ifstream in{ "단어들.txt"s };
	if (!in)
	{
		cout << "파일을 열 수 없습니다" << endl;
		return 0;
	}

	string s;
	while (!in.eof())
	{
		in >> s;
		cout << s << " ";
	}

	// 단어를 입력하세요
	// 이 단어는 없습니다
	// 이 단어는 다음 단어들과 anagram 관계 입니다
	// tablet >> battle : anagram 관계
}