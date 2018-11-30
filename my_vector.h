#pragma once
#include <vector>
#include <functional>

template <typename _type>
class my_vector : std::vector<_type>
{
public:

	my_vector<_type> where(std::function<bool(_type)> f);

	my_vector<_type> select(std::function<_type(_type)> f);

	using std::vector<_type>::vector;
};

template <typename _type>
my_vector<_type> my_vector<_type>::where(std::function<bool(_type)> f)
{
	my_vector res;
	for (auto &itr : *this)
	{
		if (f(itr)) res.push_back(itr);
	}
	return res;
}

template <typename _type>
my_vector<_type> my_vector<_type>::select(std::function<_type(_type)> f)
{
	my_vector res;
	for (auto &itr : *this)
	{
		res.push_back(f(itr));
	}
	return res;
}

