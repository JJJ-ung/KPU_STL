#include "Headers.h"

// [문제] 컨테이너 원하는 값을 찾을때는 find를 사용하면 된다
// 컨테이너에서 원하는 조건에 맞는 원소를 찾을때는 find_if를 사용해야 한다.
// my_find_if를 작성해 보자.

template <class Iter, class Pred>
Iter my_find_if(Iter beg, Iter end, Pred fn)
{
	while (beg != end) 
	{
		if (fn(*beg))
			return beg;
		++beg;
	}
	return end;
}

bool len7(const String& s)
{
	if (s.size() >= 7)
		return true;
	return false;
}

int main()
{
	vector<String> v{ "오늘은", "5월", "6일", "입니다", "10주 1일째입니다" };

	// [문제] v에서 길이가 7 이상인 원소를 찾아라.
	// 찾아서 어디에서 찾았는지 출력하라. 없으면 없다고 출력하라.


	//auto p = find_if(v.begin(), v.end(), [](const String& s) { return 7 <= s.size(); });
	//if (p != v.end())
	//	cout << "위치 - " << distance(v.begin(), p) + 1 << "에서 <" << *p << ">를 발견" << endl;
	//else
	//	cout << "없습니다" << endl;


	//auto p = my_find_if(v.begin(), v.end(), [](const String& s) { return 7 <= s.size(); });
	auto p = my_find_if(v.begin(), v.end(), len7);
	if (p != v.end())
		cout << "위치 - " << distance(v.begin(), p) + 1 << "에서 <" << *p << ">를 발견" << endl;
	else
		cout << "없습니다" << endl;
}