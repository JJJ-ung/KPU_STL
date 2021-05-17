#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// [문제] 벡터에서 조건에 맞는 원소를 찾아 제거한다

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "제거 전 출력 - ";
	for (int n : v)
		cout << n << " ";
	cout << endl;

	//v에서 홀수 제거


	cout << "제거 후 출력 - ";
	for (int n : v)
		cout << n << " ";
	cout << endl;
}