#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// [문제] vector가 메모리 관리하는 모습을 관찰한다

int main()
{
	vector<int> v;	// 벡터는 12바이트, 담는 내용 3가지

	while (true)
	{
		this_thread::sleep_for(33ms);
		v.push_back(1);
		if (v.size() == v.capacity())
		{
			v.push_back(1);
			cout << "원소의 위치 - " << v.data() << endl;									// 위치
			cout << "원소 수 - " << v.size() << endl;									// 크기
			cout << "재할당 없이 담을 수 있는 원소의 수 - " << v.capacity() << endl;		// 남은 자리 (용량)
			cout << "============================================" << endl;
		}
	}


}