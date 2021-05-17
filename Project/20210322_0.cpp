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
	// �̸� �������� ���߿� ���������� ����


	// [����] Dog��ü 1000���� ���� "Dog õ��"�� ����϶�
	//	- ������ ũ��� sizeof(Dog) * 1000 ����Ʈ�� �Ǿ�� �Ѵ�.

	//ofstream out("Dog õ��", ios::binary);
	//for (int i = 0; i < 1000; ++i)
	//{
	//	Dog dog;
	//	out.write((char*)&dog, sizeof(Dog));
	//}
	//cout << "���� ũ��� " << sizeof(Dog) * 1000 << " ����Ʈ" << endl;


	// [����] "Dog õ��"�� Dog ��ü õ���� binary mode�� ����Ǿ� �ִ�
	// �о ID ������������ ������ �� ����϶�

	ifstream in("Dog õ��", ios::binary);
	if (!in)
	{
		cout << "�б� ����" << endl;
		exit(0);
	}

	Dog dogs[1000];
	in.read((char*)dogs, sizeof(Dog) * 1000);

	sort(begin(dogs), end(dogs), [](const Dog& a, const Dog& b) {
		return a.getID() < b.getID(); });

	// ���蹮��
	// ���� �а� ���� ���� ������ ��
}