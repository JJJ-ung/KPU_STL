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
	// �����ѰŴ� �� ���ֱ�

	print(con);
	*/


	/*
		[����] "�ҽ�.cpp"�� #include�� ��� ������ ����϶�

	ifstream in{ "Headers.h" };
	list<string> con(istream_iterator<string>{in}, {});

	cout << count(con.begin(), con.end(), "#include");
	*/


	/*
	ifstream in{ "�ҽ�.cpp" };
	vector<string> v{ istream_iterator<string>{in}, {} };
	size_t cnt = count(v.begin(), v.end(), "#include"s);		// s�� �ٿ��ָ�
	cout << cnt << endl;
	*/


	ifstream in{ "�ҽ�.cpp" };
	size_t cnt = count(istream_iterator<string>{in}, {}, "#include"s);
	// �����鼭 �ٷ� ���� ���°� ����
	cout << cnt << endl;

}