#include "Headers.h"

void print(const list<int>&);
void print(const list<int>& cont)
{
	for (auto iter : cont)
		cout << iter << " ";
	cout << endl;
}

int main()
{
	/*
	list<int> con{ 1, 2, 3, 4, 1, 1, 2, 3, 3, 3, 7, 8 };

	con.sort();
	con.unique();
	// 동일한거는 다 없애기

	print(con);
	*/


	/*
		[문제] "소스.cpp"에 #include가 몇번 나오나 출력하라

	ifstream in{ "Headers.h" };
	list<string> con(istream_iterator<string>{in}, {});

	cout << count(con.begin(), con.end(), "#include");
	*/


	/*
	ifstream in{ "소스.cpp" };
	vector<string> v{ istream_iterator<string>{in}, {} };
	size_t cnt = count(v.begin(), v.end(), "#include"s);		// s를 붙여주면
	cout << cnt << endl;
	*/


	ifstream in{ "소스.cpp" };
	size_t cnt = count(istream_iterator<string>{in}, {}, "#include"s);
	// 읽으면서 바로 갯수 세는것 가능
	cout << cnt << endl;

}