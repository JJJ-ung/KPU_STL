/*
	���б� ���ǳ����� ���ٿ� �����Ѵ�.
	2021.3.8
*/

#include <iostream>
#include <fstream>
#include <filesystem>
#include <time.h>
#include "save.h"

void save(const std::string_view& filename)
{
	std::ifstream in{ filename };

	using std::endl;

	if (!in)
	{
		std::cout << "������ ���� �� �����ϴ�" << endl;
	}


}
