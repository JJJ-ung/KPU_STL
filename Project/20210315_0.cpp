#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <numeric>

using namespace std;

/*
	[문제] 파일 "int 천개.txt"에는 int 1000개가 저장되어 있다.
	(질문) int 1000개를 저장하는데 필요한 메모리는 몇 바이트?
		>> sizeof(int) * 1000 바이트
	(질문) int 1000개를 저장하기 위해 필요한 하드디스크는 몇 바이트가 있어야 하나?
		>> 1000 * sizeof(int)
		>> 4000 바이트면 어떤 값을 갖더라도 정수 1000개를 저장할 수 있따
		>> 파일 크기를 확인하면 - 10,489 바이트 사용
*/


/*
	[문제] 메모리에 기록된 bit를 그대로 파일에 저장하고 싶다
		>> 파일을 바이너리 모드로 열고 읽고 쓰면 된다

	int 100개를 저장할 공간을 확보하고 값을 1부터 100까지 값으로 기록한다
	파일 "int 백개.txt"를 바이너리 모드로 열어 int 100개의 값을 쓴다.
*/


int main()
{
	int arr[100];
	iota(begin(arr), end(arr), 1);				// 3번째 인자 : 1 넣으면 1부터 시작해서 2, 3, 4, 5... 으로 값을 채워줌 (numeric.h에 들어있다!)

	ofstream out("int 100개.txt"/*, ios::binary*/);
	// out << arr[i];  -  고수준 입출력
	// out.write(어디를, 얼마나);  -  바이트 내용 그대로 써줌
	// ios::binary로 안하면 텍스트모드로 열림 >> 401바이트

	// 크기가 다른 이유?
	// 원래 개행은 1바이트 (아스키코드)
	// 텍스트모드에서 개행은 2바이트 (줄을 내리는 명령 + 맨앞으로 커서를 가져가는 명령)
	// 바이너리모드에서는 그걸 안해도 되니까 1바이트로 처리

	out.write((char*)arr, 100 * sizeof(int));
	// 1바이트 단위로 놀아서 int형 같은걸 몰라 >> char* 형이라고 해주기
}