#include "Headers.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	if(p)
		delete[] p;
}

void Player::read(istream& is)
{
	is.read((char*)this, sizeof(Player));
	p = new char[num];
	is.read((char*)p, num);
}

void Player::write(ostream& os)
{
	os.write((char*)this, sizeof(Player));
	os.write((char*)p, num);
}

bool Player::check()
{
	if (id == 0 || score == 0 || num == 1 || p == nullptr)
		return false;

	if (name == "")
		return false;

	return true;
}

void Player::information()
{
	cout << "이름 : " << name << ", ";
	cout << "아이디 : " << id << ", ";
	cout << "점수 : " << score << ", ";
	cout << "자원수 : " << num << endl;
}
