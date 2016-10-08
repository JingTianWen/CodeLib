// CodeLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "test/test.h"

class Base
{
	template<typename THIS>
	Base* clone() const
	{
		return new THIS;
	};
};


int main()
{
	//test_chain();
	//test_ensure();
	//test_compile_string();
    
	return 0;
}

