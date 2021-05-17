#include "Headers.h"

/*
	set, multiset : key�� �ִ�
	map, multimap : key, value �ѽ�
	>> key������ �з�
*/

/*
	<key, value>
	[����] ��ȭ �̸��� key������, ���ΰ����� value��
				����) ���ǽ� - ����, ���, ����
*/

int main()
{
	map<string, vector<string>> comics;

	comics.insert( pair<string, vector<string>>("���ǽ�", {"����", "����", "���"}));

	comics.insert(make_pair("���ݸ�", (vector<string>({ "����Ÿ��", "���뽺" }))));

	// ���� �����迭ó�� ����� �� �ִ�
	comics["�Ӵϰ���"] = { "1ȣ�ǳ���", "8ȣ�ǿ���" };
	
	for (const auto& comic : comics)
	{
		cout << comic.first << " --> ";
		for (const auto& character : comic.second)
			cout << character << " ";
		cout << endl;
	}
}