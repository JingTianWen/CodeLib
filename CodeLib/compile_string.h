#pragma once
#include <string>

//template<size_t Mask>
constexpr std::string compile_string()
{
	return std::string("abc") + std::string("def");
}