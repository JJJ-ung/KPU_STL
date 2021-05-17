#include <iostream>
#include <numeric>
#include <fstream>
#include <algorithm>

using namespace std;


/*

	int 10000���� ������ ������ Ȯ���ϰ� ���� 1���� �����ϴ� ������ ä���
	���� "int ����.txt"�� ���̳ʸ� ���� ���� int 10000���� ���� �����ߴ�.

	[����] ���� "int ����.txt"���� int ������ ���̳ʸ� ���� ����Ǿ� �ִ�.
	�о ������������ �����϶�.
	������ �� �� ���� ó���� ������ int���� ȭ�鿡 ����϶�.

*/

int arr[10'000] = {};

int main()
{
	//int arr[10000] = {};
	// ũ�Ⱑ ũ�ϱ� ������ �� ����

	//iota(begin(arr), end(arr), 1);
	//ofstream out("int 10000��.txt", ios::binary);
	//out.write((char*)arr, 10000 * sizeof(int));

	ifstream in("int 10000��.txt", ios::binary);
	if (!in)
	{
		cout << "���� �ҷ����� ����" << endl;
		exit(0);
	}
	in.read((char*)arr, 10000 * sizeof(int));						// ���̳ʸ� ���� ������ write()�� read()

	sort(begin(arr), end(arr), [](int a, int b) { return a > b; });

	//cout << arr[0] << endl;
	//cout << arr[9999] << endl;

	cout << "ù ���� - " << *begin(arr) << endl;
	cout << "������ ���� - " << *(end(arr) - 1) << endl;

}