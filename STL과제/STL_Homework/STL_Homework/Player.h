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
	string name = "";					// �̸�
	int score = 0;						// ����
	int id = 0;								// ���̵�
	size_t num = 1;					// Ȯ���� �޸� ����Ʈ ��
	char* p = nullptr;					// Ȯ���� �޸��� ���۹���
};

