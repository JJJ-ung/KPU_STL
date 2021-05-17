#include "Headers.h"

/*
	[문제] "소스.cpp"의 알파벳을 오름차순으로 저장하도록 set에 넣자
	화면에 set을 출력해보고 결과를 설명해보자
*/

int main()
{
	//set<char> s;
	multiset<char> s;		// 중복 허용

	ifstream in{"20210513_4.cpp"};

	char c;
	while (in >> c)
	{
		if (isalpha(c))
			s.insert(c);
	}

	for (char c : s)
		cout << c;
	cout << endl;
}