#include "stdafx.h"
#include "../chain.h"

template<typename T>
T add(const T& val, const T& a)
{
	return val + a;
}
template<typename T>
T sub(const T& val, const T& a)
{
	return val - a;
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
		, std::bind(mul<int>, _1, _1)
		, std::bind(sub<int>, 7, _1)
		);
	std::cout << fun(9) << std::endl;
}