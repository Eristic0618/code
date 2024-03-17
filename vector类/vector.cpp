#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

namespace Eristic
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			//此处包括下面的初始化列表都可以换用缺省值
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector<T>& operator=(vector<T>& v)
		{
			if (this != &v)
			{
				reserve(v.capacity());
				for (size_t i = 0; i < v.size(); ++i)
				{
					_start[i] = v._start[i];
				}
				_finish = _start + v.size();
				return *this;
			}
		}

		iterator begin()
		{
			return _start;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			if (n > size())
			{
				if (n > capacity())
					reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		bool empty() const
		{
			return _start == _finish;
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t range = pos - _start; //在扩容前需要记录相对位置
				//在插入数据时发生了扩容，迭代器的位置会发生改变,叫做迭代器失效
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + range; //将pos也更新到新的位置
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator start = pos + 1;
			while (start < _finish)
			{
				*(start - 1) = *start;
				++start;
			}
			--_finish;
			return pos;
		}

		T& front()
		{
			return *_start;
		}

		const T& front() const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}

		const T& back() const
		{
			return *(_finish - 1);
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}