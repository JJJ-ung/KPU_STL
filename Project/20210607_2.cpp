#include "Headers.h"

#include <ranges>

int main()
{
	vector<int> v{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int a[10] = {};
	string b = "";

	// 얘내들 전부 여러개의 데이터를 관리하는 애다
	// 이거를 추상화해서 나타나는 애는 range

	// begin과 end를 제공하는 자료구조는 모두 range
	ranges::sort(v);			// v를 정렬하라

	// v에서 짝수만 출력하라
	for (int n : v 
			| views::filter([](int n) {return n%2 == 0;}))		// | -> 필터, 필터로 내용을 걸러내는것임
		cout << n << " ";
	cout << endl;

	// v에서 짝수의 값을 10배로 만들어라
	for (int n : v
		| views::filter([](int n) {return n % 2 == 0; })
		| views::transform([](int n) { return n * 10; }))		// | -> 필터, 필터로 내용을 걸러내는것임
		cout << n << " ";
	cout << endl;

	// 원래 v는?
	for (int n : v)		// | -> 필터, 필터로 내용을 걸러내는것임
		cout << n << " ";
	cout << endl;

	// 값을 변경하게 하려면?
	for (int n : v
		| views::transform([](int& n) { return n * 10; }))		// 레퍼런스
		cout << n << " ";
	cout << endl;

	// range 왜 쓰는거야
	// 이해하기가 쉽다
	// 지연평가 코루틴
}