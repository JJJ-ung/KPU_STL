#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// [����] vector�� �޸� �����ϴ� ����� �����Ѵ�

int main()
{
	vector<int> v;	// ���ʹ� 12����Ʈ, ��� ���� 3����

	while (true)
	{
		this_thread::sleep_for(33ms);
		v.push_back(1);
		if (v.size() == v.capacity())
		{
			v.push_back(1);
			cout << "������ ��ġ - " << v.data() << endl;									// ��ġ
			cout << "���� �� - " << v.size() << endl;									// ũ��
			cout << "���Ҵ� ���� ���� �� �ִ� ������ �� - " << v.capacity() << endl;		// ���� �ڸ� (�뷮)
			cout << "============================================" << endl;
		}
	}


}