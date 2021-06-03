#include "Headers.h"

/*
	���ĵ� �����Ͱ� ������ find()�� ã�� ���� �ٺ���.
	binary_search() �˰������� ���������� �Ǵ�
	equal_range()�� ������ ��ġ�� ã�´�
*/

int main()
{
	/*
		[�غ�] "�ҽ�.cpp"�� ���ĺ��� ���Ϳ� �����Ѵ�
		������ �� ����϶�
	*/

	vector<char> v;
	ifstream in{ "20210531_3.cpp" };
	copy_if(istream_iterator<char>{in}, {}, back_inserter(v), [](char c) { return isalpha(c); });

	sort(v.begin(), v.end());

	for (char c : v)
		cout << c;
	cout << endl;

	/*
		[����] �� ���ڸ� �Է¹޴´�.
		���� ���ڶ�� ���ٰ� ����Ѵ�.
		�ִ� ���ڶ�� ��� ��� �ִ��� ����Ѵ�.
	*/

	char c;	// loop optimization ���� ����ȭ
	while (true)
	{
		// char c; << ���⿡ ���ֵ� �����Ϸ��� ���� ��ġ�� �Ű��ش�
		cout << "���ĺ��� �Է��ϼ��� : ";
		cin >> c;

		bool result = binary_search(v.begin(), v.end(), c);
		if (!result)
		{
			cout << c << "�� �����ϴ�" << endl << endl;
			continue;
		}

		auto [����, ����] = equal_range(v.begin(), v.end(), c);
		//			>> structured binding ����ȭ�� ���ε�
		cout << c << "�� ��� " << ���� - ���� << "�� �ֽ��ϴ�." << endl << endl;
	}
}