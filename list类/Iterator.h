#pragma once

template<class Iterator, class Ref, class Ptr>
struct __list_reverse_iterator
{
	typedef __list_reverse_iterator<Iterator, Ref, Ptr> self;
	Iterator _cur;

	__list_reverse_iterator(Iterator it)
		:_cur(it)
	{}

	Ref operator*()
	{
		Iterator tmp = _cur;
		--tmp;
		return *tmp;
	}

	self& operator++()
	{
		--_cur;
		return *this;
	}

	self& operator--()
	{
		++_cur;
		return *this;
	}

	bool operator!=(const self& s)
	{
		return _cur != s._cur;
	}

	bool operator==(const self& s)
	{
		return _cur == s._cur;
	}
};