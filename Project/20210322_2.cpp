#include <iostream>
#include <functional>

using namespace std;

void f(void)
{
	cout << "그냥 함수입니다" << endl;
}

// ()연산자를 오버로딩 한 클래스
class Test
{
	// 함수가 몇번 호출됐는지 알고 싶으면?
	int cnt = 0;
public:
	void operator()(void)
	{
		cout << "()연산자를 오버로딩한 클래스 - 함수객체(functor)" << endl;
	}
	// >> 내 상태를 기억할 수 있는 함수

	void MemberFunction(void)
	{
		cout << "클래스의 멤버" << endl;
	}
};

int main()
{
	// ***호출 가능한 타입***

	// 1 - 일반함수
	void(*p)(void) = f;
	p();

	// 2 - Function Object
	Test t;
	t.operator()();
	t();
	cout << typeid(t).name() << endl;

	// 3 - 람다 : 이름이 없어두대, 부를 이유가 없을때 쓰기 위해서 만들어진것
	// 람다는 전역선언 안됨, 지역으로만 가능
	[](void) -> void
	{
		cout << "람다를 호출하였다" << endl;
	}();

	auto lambda = [](void) -> void
	{
		cout << "람다를 호출하였다" << endl;
	};
	lambda();

	// 4 - 클래스의 멤버도 호출가능 타입이다
	t.MemberFunction();
	auto x = &Test::MemberFunction;	// *** 번지수로 불러야 된다
	// x(); << 이거 안된다.
	


	// Function : callable 타입 전체를 대표, 템플릿
	// function : 이거 자체가 타입임
	function<void(void)> ct;
	ct = f;
	ct = t;
	ct();
	ct = lambda;
	ct();
	// ct가 설정에 따라 기능이 바뀔 수 있게 이걸 가리키거나 이걸 가리키거나 할 수 있다
}