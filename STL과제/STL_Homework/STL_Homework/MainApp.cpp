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

	/* 파일 불러오기 */
	if (FAILED(ReadFile(vecPlayer)))
		return 0;

	/* 1. 마지막 객체 정보 출력 */
	if (FAILED(LastElement(vecPlayer)))
		return 0;
	system("pause");
	cout << endl;

	/* 2. 점수 평균값 */
	if (FAILED(AverageScore(vecPlayer)))
		return 0;
	system("pause");
	cout << endl;

	/* 3. 바이트 수가 500 */
	if (FAILED(MemorySize(vecPlayer, 500)))
		return 0;
	system("pause");
	cout << endl;

	/* 4. 아이디 값 입력 후 정보 출력 */
	if (FAILED(RenderInfo(vecPlayer)))
		return 0;

	/* 프로그램 종료시 할당했던 포인터 해제 */
	if (FAILED(Release(vecPlayer)))
		return 0;
}

HRESULT ReadFile(VEC& vec)
{
	ifstream fin{ "2021 STL 과제 파일", ios::binary };
	if (!fin)
	{
		cout << "==========ERROR : 파일 읽기 실패==========" << endl;
		return E_FAIL;
	}

	cout << "==========읽기 시작==========" << endl;
	while (true)
	{
		if (fin.eof())
			break;
		Player* tmp = new Player;
		tmp->read(fin);
		if (tmp->check())
			vec.emplace_back(tmp);
	}
	cout << "총 객체의 수 : " << vec.size() << endl;
	cout << "==========읽기 완료" << "==========" << endl << endl;

	fin.close();
	return NOERROR;
}

HRESULT LastElement(VEC& vec)
{
	if (vec.empty())
	{
		cout << "==========ERROR : 컨테이너가 비어있습니다==========" << endl;
		return E_FAIL;
	}

	Player* last = vec.back();
	cout << " << 1. 마지막 객체의 정보 >> " << endl;
	last->information();
	cout << endl;

	return NOERROR;
}

HRESULT AverageScore(VEC& vec)
{
	if (vec.empty())
	{
		cout << "==========ERROR : 컨테이너가 비어있습니다==========" << endl;
		return E_FAIL;
	}

	long long scores = 0;

	for (auto& p : vec)
		scores += p->GetScore();

	cout << " << 2. 점수 평균값 >> " << endl;
	cout << " 점수 총합 : " << scores << endl;
	cout << " 점수 평균 : " << scores / vec.size() << endl;
	cout << endl;

	return NOERROR;
}

HRESULT MemorySize(VEC& vec, size_t bytes)
{
	if (vec.empty())
	{
		cout << "==========ERROR : 컨테이너가 비어있습니다==========" << endl;
		return E_FAIL;
	}

	ofstream fout{ "바이트 수가 500", ios::binary };
	if (!fout)
	{
		cout << "==========ERROR : ofstream 실패==========" << endl;
		return E_FAIL;
	}

	cout << " << 3. 바이트 수가 500 >> " << endl;
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
	cout << "** 파일 작성 완료 ! **" << endl;
	cout << "작성된 객체의 수 : " << iCnt << endl;
	cout << endl;

	return NOERROR;
}

HRESULT RenderInfo(VEC& vec)
{
	if (vec.empty())
	{
		cout << "==========ERROR : 컨테이너가 비어있습니다==========" << endl;
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
		cout << "아이디를 입력하세요 (끝내기를 입력하면 프로그램이 종료됩니다)" << endl;
		cout << " >> ";
		cin >> tmp;

		if (tmp == "끝내기")
			return NOERROR;

		auto iter = find_if(vec.begin(), vec.end(), [&tmp](Player* p) { return p->GetName() == tmp; });
		if (iter == vec.end())
		{
			cout << "존재하지 않는 ID 입니다." << endl;
			system("pause");
			continue;
		}

		cout << "==========================================" << endl;
		cout << "** ID 오름차순 정렬 **" << endl;
		iter = find_if(vecSortID.begin(), vecSortID.end(), [&tmp](Player* p) { return p->GetName() == tmp; });
		BeforeAfterInformation(vecSortID, iter);
		cout << "==========================================" << endl;
		cout << "** Name 오름차순 정렬 **" << endl;
		iter = find_if(vecSortName.begin(), vecSortName.end(), [&tmp](Player* p) { return p->GetName() == tmp; });
		BeforeAfterInformation(vecSortName, iter);
		cout << "==========================================" << endl;
		cout << "** Score 오름차순 정렬 **" << endl;
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
		cout << "==========ERROR : 컨테이너가 비어있습니다==========" << endl;
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

	cout << " ** 메모리 삭제 완료 ** " << endl;
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
	cout << "소요 시간 : " << GetTickCount64() - start << "ms" << endl;
#endif
}

void BeforeAfterInformation(VEC& vec, ITER& iter)
{
	if (iter == vec.end() || vec.empty())
		return;
	cout << "해당 - "; (*iter)->information();

	ITER iter_before = iter, iter_after = iter;
	if (iter_before != vec.begin())
	{
		--iter_before;
		cout << "앞 - ";  (*iter_before)->information();
	}
	else
		cout << "앞 - 존재하지 않습니다." << endl;

	if (iter_after != vec.end())
	{
		++iter_after;
		cout << "뒤 - ";  (*iter_after)->information();
	}
	else
		cout << "뒤 - 존재하지 않습니다." << endl;
}
