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

int arr[40'000'000] = {};
// [] - ���ӵǾ��ִ� �޸�

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
																
	sort(begin(arr), end(arr));

	for (int i = 0; i < 20000; ++i)
		cout << arr[i] << ' ';
	cout << endl;

	cout << "ù ���� - " << *begin(arr) << endl;
	cout << "������ ���� - " << *(end(arr) - 1) << endl;

}