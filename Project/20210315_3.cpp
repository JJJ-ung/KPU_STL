#include <iostream>
#include <thread>

using namespace std;

/*

	[문제] 사용자가 원하는 만큼 int 저장할 공간을 만든다
	제일 첫 값과 마지막 값을 화면 출력하라

*/


		//int a;									// 2 전역변수 (data영역)

int main()
{
		//	int a;								// 1 지역변수 (stack영역)
		//	new int;							// 3 free-store (heap영역)

	//cout << "몇 개의 int를 원하시나요?" << endl;

	//int num = 0;
	//cin >> num;

	//int* p = new int[num] {};			// 0 초기화

	//cout << "처음 - " << p[0] << endl;
	//cout << "마지막 - " << p[num - 1] << endl;

	// 5억개를 입력하면 프로그램 강제종료 된다
	// 프로그램이 사용할 수 있는 메모리 2G가 최대 : window에서 정해준 리미트 



/*

	[문제] char 100메가 생성을 계속 무한루프 돌리면?

*/


	/*
		int cnt = 0;
		while (true)
		{
			new char[100'000'000];						// char 100메가 어치
			++cnt;
			this_thread::sleep_for(1s);					// 1s, 1m, 1ms, 1us, 1ns ... 동안 프로그램 쉬기
			cout << cnt << " 성공" << '\r';
		}
	*/

	/*
		int cnt = 0;
		while (true)
		{
			char* p = new char[100'000'000];			// char 100메가 어치
			++cnt;
			this_thread::sleep_for(100ms);
			cout << cnt << " 성공" << '\r';
			delete[] p;														// 사용한 자원은 반환!!
		}
	*/

	int cnt = 0;
	while (true)
	{
		try
		{
			char* p = new char[100'000'000];			// char 100메가 어치
		}

		/*
			catch (...)				// 예외를 던졌으면 잡아주는애, 모든 예외를 잡아주는 커맨드 : ... (점3개)
			{
				cout << "더 못줘" << endl;
				continue;			// 이게 없어도 있는거랑 똑같이 작동함. (while문 시작으로 감)
			}
		*/

		catch (exception& e)
		{
			cout << e.what() << endl;					// 에러 원인이 나온당
			break;
		}

		// STL은 속도에 최적화 되어 있다!!!
		// 속도를 1순위로 중요시 하면 저거 안넣음


		// 32비트 환경이랑 64비트 환경 다르다 쓰는 메모리양


		++cnt;
		this_thread::sleep_for(100ms);
		cout << cnt << " 성공" << '\r';
	}
}