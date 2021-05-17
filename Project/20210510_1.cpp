#include "Headers.h"

/*
	[����] ���ø� �Լ��� � Ÿ���̶� ����ϱ� ������
	�Լ��� �ǵ��� �´� �ڷ����� �˻��� ����� �ʿ��ϴ�.
*/

// * �Լ� f�� int �϶��� ����Ǵ� �Լ��̴�.

template<class Type>
void f(Type a)
{
	// Type�� int�� int��� ���
	// �ƴϸ� �ƴ϶�� ����Ѵ�
	if (is_integral_v<Type>)
		cout << a << "�� integral Ÿ���̴�" << endl;
	else
		cout << a << "�� integral Ÿ���� �ƴϴ�" << endl;

	// Type�� float�� float��� ���
	// �ƴϸ� �ƴ϶�� ����Ѵ�
	if (is_floating_point_v<Type>)
		cout << a << "�� float Ÿ���̴�" << endl;
	else
		cout << a << "�� float Ÿ���� �ƴϴ�" << endl;
}

int main()
{
	f(1);
	f('a');
	f("hello");
	f(3.14);
}