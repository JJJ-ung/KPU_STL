#include <iostream>
#include <vector>
#include <thread>
#include "String.h"

using namespace std;

int main()
{
	//vector<int> v{ 1, 22, 333, 4444, 55555 };

	//int** p = reinterpret_cast<int**>(&v);		// 포인터 자료형 변환은 reinterpret_cast****
	//for (int i = 0; i < v.size(); ++i)
	//	cout << *(*p + 1) << endl;
	//cout << endl;

	//auto p = v.data();
	//for (int i = 0; i < v.size(); ++i)
	//	cout << *(p++) << endl;

	vector<String> v{ "STL", "컨테이너" };

}