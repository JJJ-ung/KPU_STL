#include "Headers.h"

const int NUM = 20000;

int main()
{
	vector<String> v;
	v.reserve(NUM);										// 이거 안하면 생기는 메모리 낭비 막기 가능 (String.h의 관찰 키기)

	// v에 길이가 1부터 NUM까지 증가하는 String을 담아본다.
	for (int i = 0; i < NUM; ++i)
		v.emplace_back(i + 1);						// push_back 대신에 emplace_back : 임시객체 안사용

	//for (const String& s : v)
	//	cout << s << endl;
}