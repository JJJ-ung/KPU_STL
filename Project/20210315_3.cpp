#include <iostream>
#include <thread>

using namespace std;

/*

	[����] ����ڰ� ���ϴ� ��ŭ int ������ ������ �����
	���� ù ���� ������ ���� ȭ�� ����϶�

*/


		//int a;									// 2 �������� (data����)

int main()
{
		//	int a;								// 1 �������� (stack����)
		//	new int;							// 3 free-store (heap����)

	//cout << "�� ���� int�� ���Ͻó���?" << endl;

	//int num = 0;
	//cin >> num;

	//int* p = new int[num] {};			// 0 �ʱ�ȭ

	//cout << "ó�� - " << p[0] << endl;
	//cout << "������ - " << p[num - 1] << endl;

	// 5�ﰳ�� �Է��ϸ� ���α׷� �������� �ȴ�
	// ���α׷��� ����� �� �ִ� �޸� 2G�� �ִ� : window���� ������ ����Ʈ 



/*

	[����] char 100�ް� ������ ��� ���ѷ��� ������?

*/


	/*
		int cnt = 0;
		while (true)
		{
			new char[100'000'000];						// char 100�ް� ��ġ
			++cnt;
			this_thread::sleep_for(1s);					// 1s, 1m, 1ms, 1us, 1ns ... ���� ���α׷� ����
			cout << cnt << " ����" << '\r';
		}
	*/

	/*
		int cnt = 0;
		while (true)
		{
			char* p = new char[100'000'000];			// char 100�ް� ��ġ
			++cnt;
			this_thread::sleep_for(100ms);
			cout << cnt << " ����" << '\r';
			delete[] p;														// ����� �ڿ��� ��ȯ!!
		}
	*/

	int cnt = 0;
	while (true)
	{
		try
		{
			char* p = new char[100'000'000];			// char 100�ް� ��ġ
		}

		/*
			catch (...)				// ���ܸ� �������� ����ִ¾�, ��� ���ܸ� ����ִ� Ŀ�ǵ� : ... (��3��)
			{
				cout << "�� ����" << endl;
				continue;			// �̰� ��� �ִ°Ŷ� �Ȱ��� �۵���. (while�� �������� ��)
			}
		*/

		catch (exception& e)
		{
			cout << e.what() << endl;					// ���� ������ ���´�
			break;
		}

		// STL�� �ӵ��� ����ȭ �Ǿ� �ִ�!!!
		// �ӵ��� 1������ �߿�� �ϸ� ���� �ȳ���


		// 32��Ʈ ȯ���̶� 64��Ʈ ȯ�� �ٸ��� ���� �޸𸮾�


		++cnt;
		this_thread::sleep_for(100ms);
		cout << cnt << " ����" << '\r';
	}
}