#include "Headers.h"

#include <ranges>

int main()
{
	vector<int> v{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int a[10] = {};
	string b = "";

	// �곻�� ���� �������� �����͸� �����ϴ� �ִ�
	// �̰Ÿ� �߻�ȭ�ؼ� ��Ÿ���� �ִ� range

	// begin�� end�� �����ϴ� �ڷᱸ���� ��� range
	ranges::sort(v);			// v�� �����϶�

	// v���� ¦���� ����϶�
	for (int n : v 
			| views::filter([](int n) {return n%2 == 0;}))		// | -> ����, ���ͷ� ������ �ɷ����°���
		cout << n << " ";
	cout << endl;

	// v���� ¦���� ���� 10��� ������
	for (int n : v
		| views::filter([](int n) {return n % 2 == 0; })
		| views::transform([](int n) { return n * 10; }))		// | -> ����, ���ͷ� ������ �ɷ����°���
		cout << n << " ";
	cout << endl;

	// ���� v��?
	for (int n : v)		// | -> ����, ���ͷ� ������ �ɷ����°���
		cout << n << " ";
	cout << endl;

	// ���� �����ϰ� �Ϸ���?
	for (int n : v
		| views::transform([](int& n) { return n * 10; }))		// ���۷���
		cout << n << " ";
	cout << endl;

	// range �� ���°ž�
	// �����ϱⰡ ����
	// ������ �ڷ�ƾ
}