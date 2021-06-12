#include "Headers.h"

#include "Player.h"

//#define SpeedCheck

typedef vector<Player*> VEC;
typedef vector<Player*>::iterator ITER;

HRESULT ReadFile(VEC& vec);
HRESULT LastElement(VEC& vec);
HRESULT AverageScore(VEC& vec);
HRESULT MemorySize(VEC& vec, size_t bytes);
HRESULT RenderInfo(VEC& vec);
HRESULT Release(VEC& vec);
void CreateSortedVector(VEC& src, VEC& dst, string tag);
void BeforeAfterInformation(VEC& vec, ITER& iter);

int main()
{
	VEC vecPlayer;

	/* ���� �ҷ����� */
	if (FAILED(ReadFile(vecPlayer)))
		return 0;

	/* 1. ������ ��ü ���� ��� */
	if (FAILED(LastElement(vecPlayer)))
		return 0;
	system("pause");
	cout << endl;

	/* 2. ���� ��հ� */
	if (FAILED(AverageScore(vecPlayer)))
		return 0;
	system("pause");
	cout << endl;

	/* 3. ����Ʈ ���� 500 */
	if (FAILED(MemorySize(vecPlayer, 500)))
		return 0;
	system("pause");
	cout << endl;

	/* 4. ���̵� �� �Է� �� ���� ��� */
	if (FAILED(RenderInfo(vecPlayer)))
		return 0;

	/* ���α׷� ����� �Ҵ��ߴ� ������ ���� */
	if (FAILED(Release(vecPlayer)))
		return 0;
}

HRESULT ReadFile(VEC& vec)
{
	ifstream fin{ "2021 STL ���� ����", ios::binary };
	if (!fin)
	{
		cout << "==========ERROR : ���� �б� ����==========" << endl;
		return E_FAIL;
	}

	cout << "==========�б� ����==========" << endl;
	while (true)
	{
		if (fin.eof())
			break;
		Player* tmp = new Player;
		tmp->read(fin);
		if (tmp->check())
			vec.emplace_back(tmp);
	}
	cout << "�� ��ü�� �� : " << vec.size() << endl;
	cout << "==========�б� �Ϸ�" << "==========" << endl << endl;

	fin.close();
	return NOERROR;
}

HRESULT LastElement(VEC& vec)
{
	if (vec.empty())
	{
		cout << "==========ERROR : �����̳ʰ� ����ֽ��ϴ�==========" << endl;
		return E_FAIL;
	}

	Player* last = vec.back();
	cout << " << 1. ������ ��ü�� ���� >> " << endl;
	last->information();
	cout << endl;

	return NOERROR;
}

HRESULT AverageScore(VEC& vec)
{
	if (vec.empty())
	{
		cout << "==========ERROR : �����̳ʰ� ����ֽ��ϴ�==========" << endl;
		return E_FAIL;
	}

	long long scores = 0;

	for (auto& p : vec)
		scores += p->GetScore();

	cout << " << 2. ���� ��հ� >> " << endl;
	cout << " ���� ���� : " << scores << endl;
	cout << " ���� ��� : " << scores / vec.size() << endl;
	cout << endl;

	return NOERROR;
}

HRESULT MemorySize(VEC& vec, size_t bytes)
{
	if (vec.empty())
	{
		cout << "==========ERROR : �����̳ʰ� ����ֽ��ϴ�==========" << endl;
		return E_FAIL;
	}

	ofstream fout{ "����Ʈ ���� 500", ios::binary };
	if (!fout)
	{
		cout << "==========ERROR : ofstream ����==========" << endl;
		return E_FAIL;
	}

	cout << " << 3. ����Ʈ ���� 500 >> " << endl;
	int iCnt = 0;
	for (auto& p : vec)
	{
		if (p->GetNum() == bytes)
		{
			p->write(fout);
			++iCnt;
		}
	}
	fout.close();
	cout << "** ���� �ۼ� �Ϸ� ! **" << endl;
	cout << "�ۼ��� ��ü�� �� : " << iCnt << endl;
	cout << endl;

	return NOERROR;
}

HRESULT RenderInfo(VEC& vec)
{
	if (vec.empty())
	{
		cout << "==========ERROR : �����̳ʰ� ����ֽ��ϴ�==========" << endl;
		return E_FAIL;
	}

#ifdef SpeedCheck
	system("cls");
#endif
	VEC vecSortID;
	CreateSortedVector(vec, vecSortID, "ID");
	VEC vecSortName;
	CreateSortedVector(vec, vecSortName, "Name");
	VEC vecSortScore;
	CreateSortedVector(vec, vecSortScore, "Score");
#ifdef SpeedCheck
	system("pause");
#endif

	while (true)
	{
		system("cls");
		string tmp = "";
		cout << "���̵� �Է��ϼ��� (�����⸦ �Է��ϸ� ���α׷��� ����˴ϴ�)" << endl;
		cout << " >> ";
		cin >> tmp;

		if (tmp == "������")
			return NOERROR;

		auto iter = find_if(vec.begin(), vec.end(), [&tmp](Player* p) { return p->GetName() == tmp; });
		if (iter == vec.end())
		{
			cout << "�������� �ʴ� ID �Դϴ�." << endl;
			system("pause");
			continue;
		}

		cout << "==========================================" << endl;
		cout << "** ID �������� ���� **" << endl;
		iter = find_if(vecSortID.begin(), vecSortID.end(), [&tmp](Player* p) { return p->GetName() == tmp; });
		BeforeAfterInformation(vecSortID, iter);
		cout << "==========================================" << endl;
		cout << "** Name �������� ���� **" << endl;
		iter = find_if(vecSortName.begin(), vecSortName.end(), [&tmp](Player* p) { return p->GetName() == tmp; });
		BeforeAfterInformation(vecSortName, iter);
		cout << "==========================================" << endl;
		cout << "** Score �������� ���� **" << endl;
		iter = find_if(vecSortScore.begin(), vecSortScore.end(), [&tmp](Player* p) { return p->GetName() == tmp; });
		BeforeAfterInformation(vecSortScore, iter);
		cout << "==========================================" << endl;
		cout << endl;
		system("pause");
	}

	return NOERROR;
}

HRESULT Release(VEC& vec)
{
	if (vec.empty())
	{
		cout << "==========ERROR : �����̳ʰ� ����ֽ��ϴ�==========" << endl;
		return E_FAIL;
	}

	for (auto& p : vec)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
	vec.clear();

	cout << " ** �޸� ���� �Ϸ� ** " << endl;
	system("pause");

	return NOERROR;
}

void CreateSortedVector(VEC& src, VEC& dst, string tag)
{
	dst.resize(src.size());
	copy(src.begin(), src.end(), dst.begin());

#ifdef SpeedCheck
	cout << "Sorted By " << tag << endl;
	ULONGLONG start = GetTickCount64();
#endif

	if (tag == "ID")
		sort(dst.begin(), dst.end(), [](Player* a, Player* b) {return a->GetID() < b->GetID(); });
	else if (tag == "Name")
		sort(dst.begin(), dst.end(), [](Player* a, Player* b) {return a->GetName() < b->GetName(); });
	else if (tag == "Score")
		sort(dst.begin(), dst.end(), [](Player* a, Player* b) {return a->GetScore() < b->GetScore(); });

#ifdef SpeedCheck
	cout << "�ҿ� �ð� : " << GetTickCount64() - start << "ms" << endl;
#endif
}

void BeforeAfterInformation(VEC& vec, ITER& iter)
{
	if (iter == vec.end() || vec.empty())
		return;
	cout << "�ش� - "; (*iter)->information();

	ITER iter_before = iter, iter_after = iter;
	if (iter_before != vec.begin())
	{
		--iter_before;
		cout << "�� - ";  (*iter_before)->information();
	}
	else
		cout << "�� - �������� �ʽ��ϴ�." << endl;

	if (iter_after != vec.end())
	{
		++iter_after;
		cout << "�� - ";  (*iter_after)->information();
	}
	else
		cout << "�� - �������� �ʽ��ϴ�." << endl;
}
