#include "Headers.h"

int main()
{
	// cpp reference 사이트에서 알고리즘 함수들 잘 살펴보긔

	/*
		[문제] abcde로 만들 수 있는 모든 순열을 출력하라 >> 5! = 120
	*/

	String s = "12345";	
	int i = 0;
	do {
		cout << "[" << ++i << "]" <<  s << endl;
	} 	while (next_permutation(s.begin(), s.end()));		// 정렬된 상태에서만 된다
}