#include "Headers.h"

int main()
{
	unordered_set<int> us;

	//for (int i = 0; i < 10; ++i)
	//{
	//	us.insert(i);
	//	for (int n : us)
	//		cout << n << " ";
	//	cout << endl;
	//}

	cout << "���������� �޸𸮸� ����մϴ�" << endl;
	cout << "�������� �Է��ϸ� �������¿� �����մϴ�" << endl << endl;
	while (true)
	{
		cout << "������ �Է��Ͻÿ� : ";
		int num;
		cin >> num;
		if (num == 0)
			break;
		us.insert(num);
		cout << endl << endl;

		for (int i = 0; i < us.bucket_count(); ++i)
		{
			cout << "[" << i << "]";
			for (auto p = us.begin(i); p != us.end(i); ++p)
				cout << " -> " << *p;
			cout << endl;
		}
	}
}