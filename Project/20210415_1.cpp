#include <iostream>
#include <vector>
#include <deque>

#include "String.h"

using namespace std;

/*
[문제] vector와 deque가 저장할 수 있는 원소 수 비교
vector에 원소를 push_back하며 v의 최대 size() 출력
*/

int main()
{
	//vector<int> v;
	deque<int> v;

	//cout << "최대 int - " << v.max_size() << endl;


	try
	{
		while (true)
			v.push_back(1);
	}
	catch(...)
	{
		cout << "최대 size : " << v.size() << endl;
	}

	cout << endl;

	/*
	
	deque는 vector보다 더 많이 담을 수 있다 (장점)
	vector보다 access 속도가 느리다 (단점)
	
	*/
}