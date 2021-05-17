#include <iostream>
#include <random>
#include <fstream>

using namespace std;

mt19937 dre;

class Dog
{
public:
	Dog() {}
	~Dog() {}
public:
	int getID() { return 0; }
private:

};

int main()
{
	// dynamic / compile type
	// 미리 정해지나 나중에 정해지나에 따라


	// [문제] Dog객체 1000개를 파일 "Dog 천개"에 기록하라
	//	- 파일의 크기는 sizeof(Dog) * 1000 바이트가 되어야 한다.

	//ofstream out("Dog 천개", ios::binary);
	//for (int i = 0; i < 1000; ++i)
	//{
	//	Dog dog;
	//	out.write((char*)&dog, sizeof(Dog));
	//}
	//cout << "파일 크기는 " << sizeof(Dog) * 1000 << " 바이트" << endl;


	// [문제] "Dog 천개"에 Dog 객체 천개가 binary mode로 저장되어 있다
	// 읽어서 ID 오름차순으로 정렬한 후 출력하라

	ifstream in("Dog 천개", ios::binary);
	if (!in)
	{
		cout << "읽기 실패" << endl;
		exit(0);
	}

	Dog dogs[1000];
	in.read((char*)dogs, sizeof(Dog) * 1000);

	sort(begin(dogs), end(dogs), [](const Dog& a, const Dog& b) {
		return a.getID() < b.getID(); });

	// 시험문제
	// 파일 읽고 쓰기 많이 공부할 것
}