#include "Headers.h"
#include "String.h"

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
	string s{ "Adding, removing and moving the elements within the list or across several lists does not invalidate the iterators or references. An iterator is invalidated only when the corresponding element is deleted." };

	// s를 파일에 썼다가 다시 읽어라.
	// 읽은걸 화면에 출력해라.
	*/

	list<int> con1{ 1, 3, 5, 7, 9 };
	list<int> con2{ 2, 4, 6, 8, 10 };

	// con1과 con2를 합해 하나로 만들어라 - merge
	list<int> con3;
	con3.merge(con1);
	con3.merge(con2);
	// merge하면 원래것은 없어진다 (옮겨버리기)

	print(con1);
	print(con2);
	print(con3);
}