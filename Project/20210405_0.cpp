#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cout << "int를 입력해 주세요. 끝내려면 ctrl+z를 누르세요" << endl;

	vector<int> numbers;

	int num;
	while (true)
	{
		cin >> num;
		numbers.push_back(num);
	}

	int sum = 0;
	for (int n : numbers)
		sum += n;
	cout << "합게 : " << sum << ", 평균 : " << sum / numbers.size() << endl;
}
