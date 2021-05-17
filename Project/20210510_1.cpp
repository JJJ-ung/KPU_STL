#include "Headers.h"

/*
	[문제] 템플릿 함수는 어떤 타입이라도 사용하기 때문에
	함수의 의도에 맞는 자료형을 검사할 방법이 필요하다.
*/

// * 함수 f는 int 일때만 실행되는 함수이다.

template<class Type>
void f(Type a)
{
	// Type이 int면 int라고 출력
	// 아니면 아니라고 출력한다
	if (is_integral_v<Type>)
		cout << a << "는 integral 타입이다" << endl;
	else
		cout << a << "는 integral 타입이 아니다" << endl;

	// Type이 float면 float라고 출력
	// 아니면 아니라고 출력한다
	if (is_floating_point_v<Type>)
		cout << a << "는 float 타입이다" << endl;
	else
		cout << a << "는 float 타입이 아니다" << endl;
}

int main()
{
	f(1);
	f('a');
	f("hello");
	f(3.14);
}