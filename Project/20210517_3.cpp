#include "Headers.h"

int main()
{
	// ���� �����迭ó�� ����� �� �ִ�
	/*
		[����] �ҽ��� �ִ� ������ ���Ƚ���� �˰� �ʹ�.
		[���� 1] �ȷ�Ȩ���� ���迡 ������ ���ĺ��� Ƚ���� ����϶�
	*/

	map<char, int> freq;							// alphabet frequency

	//freq['a'];												// �������� �Ͼ��
	//freq['a'] = 100;									// write access
	//cout << freq['a'] << endl;				// read

	ifstream fin{ "�ҽ�.cpp" };

	char c;
	while (fin >> c)
	{
		if(islower(c))
			freq[c]++;
	}

	for (auto c : freq)
		cout << "[" << c.first << "] -> " << c.second << endl;
}