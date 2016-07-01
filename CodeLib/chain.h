#pragma once

template<typename Type, typename Last>
auto chain(Last last)//->decltype(last)
{
	return last;
}

template<typename Type, typename First, typename ...T>
auto chain(First f, T ...args)//->decltype(std::bind(chain(args...), std::placeholders::_1))
{
	return [=](const Type& val)
	{
		auto tmp = f(val);
		return chain<Type>(args...)(tmp);
	};
}
