#include <iostream>

using namespace std;

/*
// 2�� - Data
int a[10000];

int a[100'000'000] { 1 };
*/

void f(void)
{
	cout << "�׳� �Լ��Դϴ�" << endl;
}

int main()
{
	/*
	// 1�� - Stack
	int a[10000];

	// 3�� - Free Store
	new int[10000];
	*/

	// Data ������ ���� ���������� ũ�� ��ȭ

	//cout << a[0] << endl;
	//cout << *(end(a) - 1) << endl;

	// !! ���� �˻� Ű���� !!
	// data segment initialize
	// ���� ���� �ʱ�ȭ


	/*
	�Լ����� code ����

	int a{ 123 };

	cout << "���� - " << &a << endl;

	f();

	cout << "�Լ� f - " << f << endl;
	cout << "�Լ� main - " << main << endl;

	(*f)();		// f()
	*/


	/*
	int a;		// int : �޸� �޶�� ��û, a : ������ �ϱ� ���� �̸�

	f();		// *ȣ�� ������* Ÿ���� ��ü�� f�� ȣ���Ͽ���.
	// [����] f�� Ÿ���� �����Դϱ�
	// �Լ��� ����Ű�� ������ f;
	*/


	/*
	auto p = f;
	p();
	// p�� Ÿ���� ȭ�鿡 ����� ������.
	cout << typeid(p).name() << endl;
	// ��� : void (__cdecl*)(void)
	//				>> c �����̶�� �� (�Լ� ������ �ΰ��� - c, �Ľ�Į)
	*/


	//void(*p)(void) = f;		// �Լ� ������ �����ϱ�
}