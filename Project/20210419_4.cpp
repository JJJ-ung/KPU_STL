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

	// s�� ���Ͽ� ��ٰ� �ٽ� �о��.
	// ������ ȭ�鿡 ����ض�.
	*/

	list<int> con1{ 1, 3, 5, 7, 9 };
	list<int> con2{ 2, 4, 6, 8, 10 };

	// con1�� con2�� ���� �ϳ��� ������ - merge
	list<int> con3;
	con3.merge(con1);
	con3.merge(con2);
	// merge�ϸ� �������� �������� (�Űܹ�����)

	print(con1);
	print(con2);
	print(con3);
}