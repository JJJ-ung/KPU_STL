#include "Headers.h"

/*
	<key, value>
	[����] ã�� ��ȭå �̸��� �Է��ϸ� �����ι��� ������ش�
*/

int main()
{
	map<string, vector<string>> comics;
	comics.insert(pair<string, vector<string>>("���ǽ�", { "����", "����", "���" }));
	comics.insert(make_pair("���ݸ�", (vector<string>({ "����Ÿ��", "���뽺" }))));
	comics["�Ӵϰ���"] = { "1ȣ�ǳ���", "8ȣ�ǿ���" };

	while (true)
	{
		string book;
		cout << "ã�� ��ȭå ���� >> ";
		cin >> book;

		auto iter = comics.find(book);
		if (iter == comics.end())
		{
			cout << "�����ϴ�" << endl;
			cout << "�߰��ϰڽ��ϱ�? >> ";
			string input;
			cin >> input;
			if (input == "y")
			{
				vector<string> charac;
				cout << "ĳ���� >> ";
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