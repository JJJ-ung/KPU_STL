#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// [����] ���Ϳ��� ���ǿ� �´� ���Ҹ� ã�� �����Ѵ�

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "���� �� ��� - ";
	for (int n : v)
		cout << n << " ";
	cout << endl;

	//v���� Ȧ�� ����


	cout << "���� �� ��� - ";
	for (int n : v)
		cout << n << " ";
	cout << endl;
}