#pragma once
#include <exception>
#include <sstream>
#include <assert.h>
#include <fstream>
#include <windows.h>

std::string __ensure_out_dir;

class EnsureHelper
{
	std::string _str;
public:
	EnsureHelper(const char* exp)
		: ENSURE_A(*this)
		, ENSURE_B(*this)
		, ENSURE_C(*this)
	{
		_str = "Assertion:";
		_str += exp;
		_str += " failed";
	}
	EnsureHelper& ENSURE_A;
	EnsureHelper& ENSURE_B;
	EnsureHelper& ENSURE_C;
	template<typename T>
	EnsureHelper& capture(const char* text, const T& val)
	{
		std::stringstream ss;
		ss << '\t' << text << " = " << val << '\n';
		_str += ss.str();

		return *this;
	}
	EnsureHelper& context(const char* file, int line)
	{
		_str += "\nin ";
		_str += file;
		_str += ": ";
		char buf[20];
		_str += _itoa(line, buf, 10);
		_str += "\nValues:";

		return *this;
	}
	~EnsureHelper()
	{
		std::ofstream fout;
		SYSTEMTIME time;
		GetLocalTime(&time);
		char buf[255];
		sprintf(
			buf, "%d-%d-%d %d:%d:%d:%d %d.log"
			, time.wYear, time.wMonth, time.wDay
			, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds
			, GetCurrentThreadId()
			);
		auto filename = __ensure_out_dir + "\\" + buf;
		fout.open(filename, std::ios_base::out | std::ios_base::binary | std::ios_base::ate);
		fout.write(&_str[0], _str.size());
	}
};

void initEnsure(const std::string &outDir)
{
	__ensure_out_dir = outDir;
}

#define ENSURE_A(x) ENSURE_(x, B)
#define ENSURE_B(x) ENSURE_(x, A)
#define ENSURE_(x, next) \
	capture(#x, x).ENSURE_##next

#define ENSURE_C(x) \
	capture(#x, x).ENSURE_C

#define ENSURE(expression) \
	if(!(expression)) EnsureHelper(#expression).context(__FILE__, __LINE__).ENSURE_A

