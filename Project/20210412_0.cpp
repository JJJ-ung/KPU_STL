#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v{ 1, 2, 4, 5 };

	// vector�� ���Ҹ� �� �� �߰��ؼ� 1, 2, 3, 4, 5�� ����� �ʹ�

	//v.insert(v.begin() + 2, 3);

	//vector<int>::const_iterator p = v.begin();
	//v.insert(p + 2, { 3, 3, 3, 3, 3, 3, 3, 3 });			// ���ϴ¸�ŭ ���� �� �־�

	auto p = v.begin();
	advance(p, 2);		// ������ ������

	//v.insert(p, 100, 3);		// iter, size(����), �� >> �Ȱ����� ������ ������

	//v.insert(p, v.begin(), v.end());

	v.insert(p, 3);

	cout << "�߰��� ���Ҹ� ���� ���� �� ���Ͱ� �����ϴ� �������" << endl;
	cout << "���� �� : " << v.size() << endl;
	cout << "�뷮 : " << v.capacity() << endl;


	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << ' ';
	cout << endl;
}