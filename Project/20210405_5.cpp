#include <iostream>
#include <vector>

using namespace std;

// [����] vector�� �޸� �����ϴ� ����� �����Ѵ�

int main()
{
	vector<int> v;	// ���ʹ� 12����Ʈ, ��� ���� 3����

	while (true)
	{
		cout << "������ ��ġ - " << v.data() << endl;									// ��ġ
		cout << "���� �� - " << v.size() << endl;									// ũ��
		cout << "���Ҵ� ���� ���� �� �ִ� ������ �� - " << v.capacity() << endl;		// ���� �ڸ� (�뷮)

		cout << "Ű�� ������ ���Ҹ� �ϳ� �߰��մϴ�: ";
		char c;
		cin >> c;
		v.push_back(1);
		cout << "============================================" << endl;
	}


} 