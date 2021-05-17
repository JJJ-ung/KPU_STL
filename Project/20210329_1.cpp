#include <iostream>
#include <random>
#include <algorithm>

#include <array>

using namespace std;


/*
	STL 컨테이너는 무엇입니까?
	- 컨테이너는 다른 객체를 저장하는 객체입니다.

	< STL Sequence Containers <
	- array
	- vector
	- deque
	- foward_list
	- list

*/



int main()
{
	// [문제] array의 사용법을 연습해 본다 - 모든 컨테이너 동일 동작
	// int 몇개를 넣어보고 다음에 string을 넣어보자

	// 함수 템플릿은 인자로 타입 추론 가능해서 <>로 타입 명시 안함
	array<int, 5> a{ 1, 2, 3, 4, 5 };
	array<int, 100> b;

	// a와 b의 크기를 비교하시오
	cout << "a의 크기는 " << sizeof(a) << endl;		// 20
	cout << "b의 크기는 " << sizeof(b) << endl;		// 400
	cout << endl;

	/*
	// 자료구조 a의 내용을 access 해봅니다.
	for (auto p = a.begin(); p != a.end(); ++p)
		*p = (*p) * (*p);

	for (auto p = a.begin(); p != a.end(); ++p)
		cout << *p << " ";
	cout << endl;
	*/

	// 자료구조 a의 내용을 제곱하다.
	for (int i = 0; i < a.size(); ++i)
		a[i] *= a[i];
	// 자료구조 a의 내용을 출력하라
	for (int num : a)
		cout << num << " ";
	cout << endl;
}