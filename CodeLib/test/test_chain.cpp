#include "stdafx.h"
#include "../chain.h"

template<typename T>
T add(const T& val, const T& a)
{
	return val + a;
}

template<typename T>
T mul(const T& val, const T&m)
{
	return val * m;
}
void test_chain()
{
	using namespace std::placeholders;
	auto fun = chain<int>(
		std::bind(add<int>, _1, 1)
		, std::bind(mul<int>, _1, 2)
		, std::bind(add<int>, _1, 7)
		);
	std::cout << fun(2) << std::endl;
}