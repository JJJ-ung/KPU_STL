#include "Headers.h"

int main()
{
	ifstream in{ "단어들.txt" };

	vector<string> v{ istream_iterator<string>{in}, {} };
	cout << "모두 " << v.size() << " 단어를 읽었습니다" << endl;

	// [문제] 단어 길이 순으로 가장 긴 단어 10개만 화면에 출력하시오
	partial_sort(v.begin(), v.begin() + 10, v.end(), [](const string& a, const string& b) {
		return a.size() > b.size(); });
	
	for (int i = 0; i < 10; ++i)
		cout << v[i] << endl;
}

/*
	dichlorodiphenyltrichloroethane
	trinitrophenylmethylnitramine
	cyclotrimethylenetrinitramine
	hydroxydehydrocorticosterone
	antidisestablishmentarianism
	hydroxydesoxycorticosterone
	microspectrophotometrically
	electroencephalographically
	demethylchlortetracycline
	electroencephalographical

	* 얘내를 anagram 찾기에 넣으면 백만년 걸린다
	* anagram 찾기를 수정해야한다
*/