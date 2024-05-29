#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

#include "Iterator.h"

namespace Eristic
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& x = T()) //匿名对象作为缺省值，变为默认构造函数
			:_next(nullptr)
			,_prev(nullptr)
			,_data(x)
		{}
	};
	 
	template<class T, class Ref, class Ptr> //通过模板参数实现const迭代器和普通迭代器版本的复用
	struct __list_iterator //重点：迭代器的底层封装
	{
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;
		node* _node;

		__list_iterator(node* n)
			:_node(n)
		{}

		Ref& operator*()
		{ 
			return _node->_data;
		}

		Ptr operator->()
		{
			 return &_node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return _node == s._node;
		}
		//不需要写拷贝构造，因为我们用默认生成的进行浅拷贝就能完成需求
		//析构函数也不需要写，释放节点是list的事，与迭代器无关
	};

	template<class T>
	class list
	{
		typedef list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef __list_reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef __list_reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		void list_init()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			list_init();
		}

		list(int n, const T& x = T())
		{
			list_init();
			for (int i = 0; i < n; i++)
				push_back(x);
		}

		template<class iterator>
		list(iterator first, iterator last)
		{
			list_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& lt)
		{
			list_init();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		list<T>& operator=(const list<T> lt)
		{
			swap(lt);
			return *this;
		}

		int size()
		{
			iterator it = begin();
			int count = 0;
			while (it != end())
			{
				++it;
				++count;
			}
			return count;
		}

		void resize(size_t n, const T& x = T())
		{
			if (n < size())
				while (n < size())
					pop_back();
			else if (n > size())
				while (n > size())
					push_back(x);
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		T& front()
		{
			return _head->_next->_data;
		}

		const T& front() const
		{
			return _head->_next->_data;
		}

		T& back()
		{
			return _head->_prev->_data;
		}

		const T& back() const
		{
			return _head->_prev->_data;
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;

			node* newnode = new node(x);

			cur->_prev = newnode;
			newnode->_next = cur;
			prev->_next = newnode;
			newnode->_prev = prev;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end()); //哨兵位不能删
			node* prev = pos._node->_prev;
			node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;

			delete pos._node;

			return iterator(next);
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

	private:
		node* _head;
	};

	void Test()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;

	}
}

