#pragma once

class Player
{
public:
	Player();
	~Player();

public:
	const string& GetName() { return name; }
	const int& GetScore() { return score; }
	const int& GetID() { return id; }
	const size_t& GetNum() { return num; }
	const char* GetPointer() { return p; }

public:
	void read(istream& is);
	void write(ostream& os);

public:
	bool check();
	void information();

private:
	string name = "";					// 이름
	int score = 0;						// 점수
	int id = 0;								// 아이디
	size_t num = 1;					// 확보한 메모리 바이트 수
	char* p = nullptr;					// 확보한 메모리의 시작번지
};

