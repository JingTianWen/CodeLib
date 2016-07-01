#pragma once

#include <iostream>
#include <osg/Timer>
#include <string>
class ScopeTimePrompter
{
	std::wostream& out;
	std::wstring _line;
	osg::ElapsedTime _timer;
	static int &instanceCount()
	{
		static int ___ = 0;
		return ___;
	}
	static void incInstance()
	{
		++instanceCount();
	}
	static void decInstance()
	{
		--instanceCount();
	}
public:
	ScopeTimePrompter(const std::wstring&line, std::wostream& os = std::wcout)
		: out(os), _line(line)
	{
		incInstance();
		std::wstring indent(instanceCount() - 1, '\t');
		out << indent << L"START:" << _line << std::endl;
	}
	~ScopeTimePrompter()
	{
		std::wstring indent(instanceCount() - 1, '\t');
		out << indent << L"FINISH:" << _line << L". TAKES:" << _timer.elapsedTime() << L" SECONDS" << std::endl;
		decInstance();
	}
};