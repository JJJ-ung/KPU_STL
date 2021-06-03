#include "Headers.h"

/*
	정렬된 데이터가 있을때 find()로 찾는 것은 바보다.
	binary_search() 알고리즘으로 존재유무를 판단
	equal_range()로 원소의 위치를 찾는다
*/

int main()
{
	/*
		[준비] "소스.cpp"의 알파벳을 벡터에 저장한다
		정렬한 후 출력하라
	*/

	vector<char> v;
	ifstream in{ "20210531_3.cpp" };
	copy_if(istream_iterator<char>{in}, {}, back_inserter(v), [](char c) { return isalpha(c); });

	sort(v.begin(), v.end());

	for (char c : v)
		cout << c;
	cout << endl;

	/*
		[문제] 한 문자를 입력받는다.
		없는 글자라면 없다고 출력한다.
		있는 글자라면 모두 몇개가 있는지 출력한다.
	*/

	char c;	// loop optimization 루프 최적화
	while (true)
	{
		// char c; << 여기에 냅둬도 컴파일러가 위에 위치에 옮겨준다
		cout << "알파벳을 입력하세요 : ";
		cin >> c;

		bool result = binary_search(v.begin(), v.end(), c);
		if (!result)
		{
			cout << c << "는 없습니다" << endl << endl;
			continue;
		}

		auto [하한, 상한] = equal_range(v.begin(), v.end(), c);
		//			>> structured binding 구조화된 바인딩
		cout << c << "는 모두 " << 상한 - 하한 << "개 있습니다." << endl << endl;
	}
}