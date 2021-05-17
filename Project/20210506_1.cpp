#include "Headers.h"

// [����] �����̳� ���ϴ� ���� ã������ find�� ����ϸ� �ȴ�
// �����̳ʿ��� ���ϴ� ���ǿ� �´� ���Ҹ� ã������ find_if�� ����ؾ� �Ѵ�.
// my_find_if�� �ۼ��� ����.

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
	vector<String> v{ "������", "5��", "6��", "�Դϴ�", "10�� 1��°�Դϴ�" };

	// [����] v���� ���̰� 7 �̻��� ���Ҹ� ã�ƶ�.
	// ã�Ƽ� ��𿡼� ã�Ҵ��� ����϶�. ������ ���ٰ� ����϶�.


	//auto p = find_if(v.begin(), v.end(), [](const String& s) { return 7 <= s.size(); });
	//if (p != v.end())
	//	cout << "��ġ - " << distance(v.begin(), p) + 1 << "���� <" << *p << ">�� �߰�" << endl;
	//else
	//	cout << "�����ϴ�" << endl;


	//auto p = my_find_if(v.begin(), v.end(), [](const String& s) { return 7 <= s.size(); });
	auto p = my_find_if(v.begin(), v.end(), len7);
	if (p != v.end())
		cout << "��ġ - " << distance(v.begin(), p) + 1 << "���� <" << *p << ">�� �߰�" << endl;
	else
		cout << "�����ϴ�" << endl;
}