#include <iostream>
#include <vector>
#include <deque>

#include "String.h"

using namespace std;

/*
[����] vector�� deque�� ������ �� �ִ� ���� �� ��
vector�� ���Ҹ� push_back�ϸ� v�� �ִ� size() ���
*/

int main()
{
	//vector<int> v;
	deque<int> v;

	//cout << "�ִ� int - " << v.max_size() << endl;


	try
	{
		while (true)
			v.push_back(1);
	}
	catch(...)
	{
		cout << "�ִ� size : " << v.size() << endl;
	}

	cout << endl;

	/*
	
	deque�� vector���� �� ���� ���� �� �ִ� (����)
	vector���� access �ӵ��� ������ (����)
	
	*/
}