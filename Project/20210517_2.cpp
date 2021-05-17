#include "Headers.h"

/*
	<key, value>
	[문제] 찾을 만화책 이름을 입력하면 등장인물을 출력해준다
*/

int main()
{
	map<string, vector<string>> comics;
	comics.insert(pair<string, vector<string>>("원피스", { "루피", "초파", "우솝" }));
	comics.insert(make_pair("원펀맨", (vector<string>({ "사이타마", "제노스" }))));
	comics["머니게임"] = { "1호실남성", "8호실여성" };

	while (true)
	{
		string book;
		cout << "찾을 만화책 제목 >> ";
		cin >> book;

		auto iter = comics.find(book);
		if (iter == comics.end())
		{
			cout << "없습니다" << endl;
			cout << "추가하겠습니까? >> ";
			string input;
			cin >> input;
			if (input == "y")
			{
				vector<string> charac;
				cout << "캐릭터 >> ";
				while (true)
				{
					string tmp;
					cin >> tmp;
					if (tmp == "end")
						break;
					charac.push_back(tmp);
				}
				comics[book] = charac;
			}
			else if (input == "n")
				continue;
		}
		else
		{
			for (const auto& characters : (*iter).second)
				cout << characters << " ";
			cout << endl;
		}
	}
}