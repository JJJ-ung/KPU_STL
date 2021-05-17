#include <iostream>

using namespace std;

/*
// 2번 - Data
int a[10000];

int a[100'000'000] { 1 };
*/

void f(void)
{
	cout << "그냥 함수입니다" << endl;
}

int main()
{
	/*
	// 1번 - Stack
	int a[10000];

	// 3번 - Free Store
	new int[10000];
	*/

	// Data 영역에 따른 실행파일의 크기 변화

	//cout << a[0] << endl;
	//cout << *(end(a) - 1) << endl;

	// !! 구글 검색 키워드 !!
	// data segment initialize
	// 전역 변수 초기화


	/*
	함수들은 code 영역

	int a{ 123 };

	cout << "스택 - " << &a << endl;

	f();

	cout << "함수 f - " << f << endl;
	cout << "함수 main - " << main << endl;

	(*f)();		// f()
	*/


	/*
	int a;		// int : 메모리 달라고 요청, a : 엑세스 하기 위한 이름

	f();		// *호출 가능한* 타입의 객체인 f를 호출하였다.
	// [질문] f의 타입은 무엇입니까
	// 함수를 가리키는 포인터 f;
	*/


	/*
	auto p = f;
	p();
	// p의 타입을 화면에 출력해 보세요.
	cout << typeid(p).name() << endl;
	// 결과 : void (__cdecl*)(void)
	//				>> c 형식이라는 것 (함수 형식은 두가지 - c, 파스칼)
	*/


	//void(*p)(void) = f;		// 함수 포인터 선언하기
}