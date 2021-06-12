#include "Headers.h"
#include <format>		// 지난주에 올라온거임

int main()
{
	int n = 123;
	
	// printf를 C++에서도 쓰고 싶은 사람들을 위해
	format("{}\n", n);
}