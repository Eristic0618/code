#pragma once
#include "RBTree.h"

namespace Eristic
{
	template<class K>
	class set 
	{
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin() const
		{
			return _t.begin();
		}

		iterator end() const
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _t.insert(key);
		}

		void InOrder()
		{
			_t.InOrder();
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}