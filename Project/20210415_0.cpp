#include <iostream>
#include <vector>
#include <deque>

#include "String.h"

using namespace std;

struct Test
{
	char c[1024];
	void show() const
	{
		cout << this << endl;
	}
};

int main()
{
	/*
	컨테이너
			sequence 컨테이너
				array, vector
				deque - 왜 씀?	
	*/
	
	/*deque<String> d{ "제일처음", "마지막" };
	for (const String& s : d)
		cout << s << endl;*/

	//deque : 메모리가 연속되어 있는가?
	// [i] : 연속된 애들만 쓸 수 있는




	/*
	vector<Test> v(10);
	for (const Test& t : v)
		t.show();
	// 메모리가 붙어있으니까 400 바이트씩 차이가 남 주소값에

	cout << "추가 후 다시 출력 " << endl;
	v.push_back({});

	for (const Test& t : v)
		t.show();
	// 위에 출력했던 주소에서 이사갔음
	*/

		
	deque<Test> v(10);
	for (const Test& t : v)
		t.show();
	// 8바이트씩 더 쓴다
	// 메모리 연속

	cout << "추가 후 다시 출력 " << endl;
	v.push_back({});

	for (const Test& t : v)
		t.show();
	// 이사도 안감
	

	// deque는 연속된 것 같이 행동할 뿐 (사기꾼)
	// 메모리가 붙어있을때의 특징
	// vector에 비해 access 속도가 느리다 (단점)
}