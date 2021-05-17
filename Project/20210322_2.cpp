#include <iostream>
#include <functional>

using namespace std;

void f(void)
{
	cout << "�׳� �Լ��Դϴ�" << endl;
}

// ()�����ڸ� �����ε� �� Ŭ����
class Test
{
	// �Լ��� ��� ȣ��ƴ��� �˰� ������?
	int cnt = 0;
public:
	void operator()(void)
	{
		cout << "()�����ڸ� �����ε��� Ŭ���� - �Լ���ü(functor)" << endl;
	}
	// >> �� ���¸� ����� �� �ִ� �Լ�

	void MemberFunction(void)
	{
		cout << "Ŭ������ ���" << endl;
	}
};

int main()
{
	// ***ȣ�� ������ Ÿ��***

	// 1 - �Ϲ��Լ�
	void(*p)(void) = f;
	p();

	// 2 - Function Object
	Test t;
	t.operator()();
	t();
	cout << typeid(t).name() << endl;

	// 3 - ���� : �̸��� ����δ�, �θ� ������ ������ ���� ���ؼ� ���������
	// ���ٴ� �������� �ȵ�, �������θ� ����
	[](void) -> void
	{
		cout << "���ٸ� ȣ���Ͽ���" << endl;
	}();

	auto lambda = [](void) -> void
	{
		cout << "���ٸ� ȣ���Ͽ���" << endl;
	};
	lambda();

	// 4 - Ŭ������ ����� ȣ�Ⱑ�� Ÿ���̴�
	t.MemberFunction();
	auto x = &Test::MemberFunction;	// *** �������� �ҷ��� �ȴ�
	// x(); << �̰� �ȵȴ�.
	


	// Function : callable Ÿ�� ��ü�� ��ǥ, ���ø�
	// function : �̰� ��ü�� Ÿ����
	function<void(void)> ct;
	ct = f;
	ct = t;
	ct();
	ct = lambda;
	ct();
	// ct�� ������ ���� ����� �ٲ� �� �ְ� �̰� ����Ű�ų� �̰� ����Ű�ų� �� �� �ִ�
}