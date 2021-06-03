#include "Headers.h"

int main()
{
	ifstream in{ "�ܾ��.txt" };

	vector<string> v{ istream_iterator<string>{in}, {} };
	cout << "��� " << v.size() << " �ܾ �о����ϴ�" << endl;

	// [����] �ܾ� ���� ������ ���� �� �ܾ� 10���� ȭ�鿡 ����Ͻÿ�
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

	* �곻�� anagram ã�⿡ ������ �鸸�� �ɸ���
	* anagram ã�⸦ �����ؾ��Ѵ�
*/