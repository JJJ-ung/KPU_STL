#include "Headers.h"

int main()
{
	// cpp reference ����Ʈ���� �˰��� �Լ��� �� ���캸��

	/*
		[����] abcde�� ���� �� �ִ� ��� ������ ����϶� >> 5! = 120
	*/

	String s = "12345";	
	int i = 0;
	do {
		cout << "[" << ++i << "]" <<  s << endl;
	} 	while (next_permutation(s.begin(), s.end()));		// ���ĵ� ���¿����� �ȴ�
}