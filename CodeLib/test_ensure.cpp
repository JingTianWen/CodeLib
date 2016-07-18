#include "stdafx.h"
#include "ensure.h"

void test_ensure()
{
	initEnsure("f:");
	try
	{
		ENSURE(sizeof(int) == 3)(sizeof(int))(sizeof(double));
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		exit(1);
	}
}