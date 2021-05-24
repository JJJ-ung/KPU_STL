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

	cout << "언오더드셋의 메모리를 출력합니다" << endl;
	cout << "정수값을 입력하면 언오더드셋에 저장합니다" << endl << endl;
	while (true)
	{
		cout << "정수를 입력하시오 : ";
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