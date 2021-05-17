/*
	많은 수의 자료를 다룬다! (int에서 시작 -> Dog로 넘어가기)
	 - 메모리의 위치를 구분할 수 있는가?
	 - 파일로 저장하는 방법

	 sort로 정렬 - callable type
*/

#include <iostream>
#include <fstream>
using namespace std;

/*
	[문제] 정수 10개를 저장할 공간을 확보하자
	값을 1부터 10까지 값으로 순서대로 채우자.
	파일 "int 10개.txt"에 저장하다

	저장된 것을 확인 했으면 프로그램을 다 지우고
	파일 "int 10개.txt"를 읽어 int 값을 화면에 출력한다.
*/


/*

// 저장하기
int main()
{
	// 정수 저장하는 3가지 방법
	//int a[10];										// 1번째 방법 : 지역변수
	// 전역으로 >> int a[10];					// 2번째 방법 : 전역변수
	// new int[10];									// 3번째 방법 : 동적할당변수

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	ofstream out{ "int 10개.txt" };

	for (int num : a)
		out << num << "\t";
	cout << endl;
}

*/


// 파일 열기
int main()
{
	ifstream in{ "int 10개.txt" };
	// 하드디스크에 저장된 것 :  1	2	3	4	5	6	7	8	9	10	

	for (int i = 0; i < 10; ++i)
	{
		int num;
		in >> num;							// 공백을 만날때까지 읽음
		cout << num << endl;
	}

}