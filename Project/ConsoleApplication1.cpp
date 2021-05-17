
/*
2021 1학기 stl 월56목910 - 3/8 월요일 (1주2일)
save 함수를 별도 파일로 분리한다.
많은 갯수의 자료를 다루어본다 (자료구조+알고리즘+stl)
*/

#include <iostream>
//#include "save.h"
#include <random>
#include <algorithm>

using namespace std;

/*
	[문제] int 10개를 저장할 수 있는 공간을 확보하라.
	랜덤엔진과 분포를 사용하여 int값을 채워라.
	int를 오름차순으로 정렬하라
	화면에 출력하라
*/

default_random_engine dre;

int x(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	// 내림차순 : if (x > y)
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int main()
{
	//save("save.h");
	//save("save.cpp");

	//cout << "정수의 최대값 : " << numeric_limits<int>::max() << endl;

	int arr[100] = {};	// >> 자료구조 (같은 종류를 여러개 담는거)

	//default_random_engine dre;				//random엔진 c++ 디폴트
	//cout << sizeof(dre) << endl;				// dre는 5000바이트 >> 크니까 전역으로 두자

	uniform_int_distribution<> uid{ 0, 100 };

	//for (int i = 0; i < 10; ++i)
	//	arr[i] = uid(dre);

	//for (int i = 0; i < 10; ++i)
	//{
	//	//arr[i] = rand() % 100;
	//	cout << arr[i] << " ";
	//}
	//cout << endl;

	// ** 틀린코드 **
	//for (int n : arr)
	//	n = uid(dre);						// n은 지역변수니까 for문 나가면 없어짐, 포인터로 받아야댐
	for (int& n : arr)
		n = uid(dre);


	// [문제] A를 오름차순으로 정렬하라
	
	// 1. 퀵소트
	// qsort(arr, 100, sizeof(int), /*어떻게정렬할까?*/ x);
	// qsort가 해줄 수 있는 메모리 유형 : [], array, vector, deque (메모리가 붙어있는 애들)

	// 2. <algorith> sort()
	int cnt = 0;
	sort(begin(arr), end(arr), /*어떻게? / 호출가능타입*/ [&cnt](int a, int b) /*->bool : 이건 옛날 문법, 생략가능해짐*/
														{ cnt++; return a < b; } );	// 람다함수, 오름차순
	// sort(a, a+100); 시작번지와 끝번지
	// sort함수는 NlogN

	cout << "비교함수 호출횟수 - " << cnt << endl;

	for (int x : arr)
		cout << x << " ";
	cout << endl;
}
