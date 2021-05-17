#include "Headers.h"

/*
	Sequence Container
	Associative Container (연관 컨테이너) : set / map >> key, value
	Unordered Container
*/

int  main()
{
	set<int> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	//s.insert(11);


	//	[문제] 3은 이미 있는 원소이다. 이 함수의 리턴값으로 이 사실을 알 수 있다.
	//auto p = s.insert(3);
	pair<set<int>::iterator, bool> p = s.insert(3);
	if (p.second == true)
		;
	else
		cout << "이미 존재하는 원소라 추가할 수 없다" << endl;


	// structured binding
	auto [위치, 성공여부] = s.insert(100);
	// auto [ignore, 성공여부] = s.insert(100);   // ignore 사용
	if (성공여부 == false)
		cout << "추가 실패" << endl;


	for (int n : s)
		cout << n << " ";
	cout << endl;
}