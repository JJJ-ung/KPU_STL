#include <iostream>
#include <vector>

using namespace std;

// [문제] vector가 메모리 관리하는 모습을 관찰한다

int main()
{
	vector<int> v;	// 벡터는 12바이트, 담는 내용 3가지

	while (true)
	{
		cout << "원소의 위치 - " << v.data() << endl;									// 위치
		cout << "원소 수 - " << v.size() << endl;									// 크기
		cout << "재할당 없이 담을 수 있는 원소의 수 - " << v.capacity() << endl;		// 남은 자리 (용량)

		cout << "키를 누르면 원소를 하나 추가합니다: ";
		char c;
		cin >> c;
		v.push_back(1);
		cout << "============================================" << endl;
	}


} 