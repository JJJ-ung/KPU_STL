#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int n : v)
		cout << n << " ";
	cout << endl;

	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << endl;
	cout << endl;

}
