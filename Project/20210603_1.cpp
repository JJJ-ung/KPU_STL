#include "Headers.h"

/*
	[����] ����ڰ� �Է��� �ܾ v���� ã�´�
	������ ���ٶ�� ���
	������ �ִٶ�� ����ϰ� �� �ܾ�� anagram ���踦 ���� ��� �ܾ ����Ѵ�
*/

int main()
{
	ifstream in{ "�ܾ��.txt" };
	vector<string> v{ istream_iterator<string>{in}, {} };
	
	cout << "ANAGRAM�� ã�ڽ��ϴ�" << endl;

	while (true)
	{
		cout << " >> ";
		string str;
		cin >> str;

		// str�� v�� �ֳ� ã�´�

		// ������
		if (!binary_search(v.begin(), v.end(), str))
		{
			cout << "�����ϴ�" << endl;
			continue;
		}

		// ������
		cout << "Anagrams : ";
		sort(str.begin(), str.end());
		do {
			//if (binary_search(v.begin(), v.end(), str))
			//	cout << str << "�� ";
			//else
			//	cout << str << "�� ";
			if (binary_search(v.begin(), v.end(), str))
				cout << str << " ";
		} while (next_permutation(str.begin(), str.end()));		// ���ĵ� ���¿����� �ȴ�
		cout << endl;
	}
}