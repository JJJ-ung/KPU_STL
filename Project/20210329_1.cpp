#include <iostream>
#include <random>
#include <algorithm>

#include <array>

using namespace std;


/*
	STL �����̳ʴ� �����Դϱ�?
	- �����̳ʴ� �ٸ� ��ü�� �����ϴ� ��ü�Դϴ�.

	< STL Sequence Containers <
	- array
	- vector
	- deque
	- foward_list
	- list

*/



int main()
{
	// [����] array�� ������ ������ ���� - ��� �����̳� ���� ����
	// int ��� �־�� ������ string�� �־��

	// �Լ� ���ø��� ���ڷ� Ÿ�� �߷� �����ؼ� <>�� Ÿ�� ��� ����
	array<int, 5> a{ 1, 2, 3, 4, 5 };
	array<int, 100> b;

	// a�� b�� ũ�⸦ ���Ͻÿ�
	cout << "a�� ũ��� " << sizeof(a) << endl;		// 20
	cout << "b�� ũ��� " << sizeof(b) << endl;		// 400
	cout << endl;

	/*
	// �ڷᱸ�� a�� ������ access �غ��ϴ�.
	for (auto p = a.begin(); p != a.end(); ++p)
		*p = (*p) * (*p);

	for (auto p = a.begin(); p != a.end(); ++p)
		cout << *p << " ";
	cout << endl;
	*/

	// �ڷᱸ�� a�� ������ �����ϴ�.
	for (int i = 0; i < a.size(); ++i)
		a[i] *= a[i];
	// �ڷᱸ�� a�� ������ ����϶�
	for (int num : a)
		cout << num << " ";
	cout << endl;
}