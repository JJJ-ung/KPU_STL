#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v{ 1, 2, 4, 5 };

	// vector에 원소를 한 개 추가해서 1, 2, 3, 4, 5로 만들고 싶다

	//v.insert(v.begin() + 2, 3);

	//vector<int>::const_iterator p = v.begin();
	//v.insert(p + 2, { 3, 3, 3, 3, 3, 3, 3, 3 });			// 원하는만큼 넣을 수 있어

	auto p = v.begin();
	advance(p, 2);		// 포인터 앞으로

	//v.insert(p, 100, 3);		// iter, size(갯수), 값 >> 똑같은거 여러개 넣을때

	//v.insert(p, v.begin(), v.end());

	v.insert(p, 3);

	cout << "중간에 원소를 끼워 넣은 후 벡터가 관리하는 멤버변수" << endl;
	cout << "원소 수 : " << v.size() << endl;
	cout << "용량 : " << v.capacity() << endl;


	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << ' ';
	cout << endl;
}