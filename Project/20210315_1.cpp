#include <iostream>
#include <numeric>
#include <fstream>
#include <algorithm>

using namespace std;


/*

	int 10000개를 저장할 공간을 확보하고 값을 1부터 시작하는 값으로 채운다
	파일 "int 만개.txt"를 바이너리 모드로 열어 int 10000개의 값을 저장했다.

	[문제] 파일 "int 만개.txt"에는 int 만개가 바이너리 모드로 저장되어 있다.
	읽어서 내림차순으로 정렬하라.
	정렬한 값 중 제일 처음과 마지막 int값을 화면에 출력하라.

*/

int arr[10'000] = {};

int main()
{
	//int arr[10000] = {};
	// 크기가 크니까 전역이 더 나음

	//iota(begin(arr), end(arr), 1);
	//ofstream out("int 10000개.txt", ios::binary);
	//out.write((char*)arr, 10000 * sizeof(int));

	ifstream in("int 10000개.txt", ios::binary);
	if (!in)
	{
		cout << "파일 불러오기 실패" << endl;
		exit(0);
	}
	in.read((char*)arr, 10000 * sizeof(int));						// 바이너리 모드는 무적권 write()랑 read()

	sort(begin(arr), end(arr), [](int a, int b) { return a > b; });

	//cout << arr[0] << endl;
	//cout << arr[9999] << endl;

	cout << "첫 원소 - " << *begin(arr) << endl;
	cout << "마지막 원소 - " << *(end(arr) - 1) << endl;

}