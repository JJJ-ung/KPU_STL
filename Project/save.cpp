/*
	한학기 강의내용을 덧붙여 저장한다.
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
		std::cout << "파일을 읽을 수 없습니다" << endl;
	}


}
