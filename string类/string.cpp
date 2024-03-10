#include<iostream>
#include<assert.h>
using namespace std;

namespace Eristic
{
	class string
	{
		friend ostream& operator<<(ostream& cout, const string& s);
		friend istream& operator>>(istream& cout, const string& s);
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size == 0 ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		bool empty() const
		{
			size_t len = strlen(_str);
			return !len;
		}

		char& at(size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& at(size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		char& back()
		{
			return at(_size - 1);
		}

		const char& back() const
		{
			return at(_size - 1);
		}

		char& front()
		{
			return at(0);
		}

		const char& front() const
		{
			return at(0);
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else if (n > _size)
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		void push_back(char ch)
		{
			if (_size + 2 > _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
			//insert(_size, ch); //或者直接复用
		}

		void push_back(const char* str)
		{
			append(str);
		}

		void append(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity)
			{
				reserve(_capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len >= _size - pos)
			{
				_str[pos] = '\0';
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
			}
			_size -= len;
			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(const string& s, size_t pos = 0) const
		{
			assert(pos < _size);
			char* p = strstr(_str + pos, s._str);
			if (p == nullptr)
			{
				return npos;
			}
			return p - _str;
		}

		size_t find(const char* str, size_t pos = 0) const
		{
			assert(pos < _size);
			char* p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}
			return p - _str;
		}

		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const string& s)
		{
			push_back(s._str);
			return *this;
		}

		string& operator+=(const char* str)
		{
			push_back(str);
			return *this;
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		bool operator>(const string& s) const
		{			
			return strcmp(_str, s._str) > 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>=(const string& s) const
		{
			return	*this > s || *this == s;
		}

		bool operator<(const string& s) const
		{
			return	!(*this >= s);
		}

		bool operator<=(const string& s) const
		{
			return	!(*this > s);
		}

		bool operator!=(const string& s) const
		{
			return	!(*this == s);
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		const char* c_str() const
		{
			return _str;
		}

		~string()
		{
			delete[] _str;
			_capacity = _size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
	};

	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
}