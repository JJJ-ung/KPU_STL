#include "Headers.h"

const int NUM = 20000;

int main()
{
	vector<String> v;
	v.reserve(NUM);										// �̰� ���ϸ� ����� �޸� ���� ���� ���� (String.h�� ���� Ű��)

	// v�� ���̰� 1���� NUM���� �����ϴ� String�� ��ƺ���.
	for (int i = 0; i < NUM; ++i)
		v.emplace_back(i + 1);						// push_back ��ſ� emplace_back : �ӽð�ü �Ȼ��

	//for (const String& s : v)
	//	cout << s << endl;
}