#pragma once
#include "RBTree.h"

namespace Eristic
{
	template<class K,class T>
	class map
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, T>& kv)
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, pair<const K, T>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, T>, MapKeyOfT>::const_iterator const_iterator;
		
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		const_iterator begin() const
		{
			return _t.begin();
		}

		const_iterator end() const
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const pair<K, T>& kv)
		{
			return _t.insert(kv);
		}

		void InOrder()
		{
			_t.InOrder();
		}

		T& operator[](const K& key)
		{
			pair<iterator, bool> p = insert(make_pair(key, T()));
			return p.first->second;
		}
	private:
		RBTree<K, pair<const K, T>, MapKeyOfT> _t;
	};
}