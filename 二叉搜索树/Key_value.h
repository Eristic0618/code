#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	K _key;
	V _val;

	BSTreeNode(const K& key, const V& val)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
		, _val(val)
	{}
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	bool insert(const K& key, const V& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, val);
			return true;
		}

		Node* prev = nullptr;
		Node* cur = _root;

		while (cur)
		{
			prev = cur;
			if (key > cur->_key)
				cur = cur->_right;
			else if (key < cur->_key)
				cur = cur->_left;
			else
				return false;
		}

		cur = new Node(key, val);

		if (key > prev->_key)
			prev->_right = cur;
		else
			prev->_left = cur;
		return true;
	}

	Node* find(const K& key)
	{
		Node* cur = _root;

		while (cur)
		{
			if (key > cur->_key)
				cur = cur->_right;
			else if (key < cur->_key)
				cur = cur->_left;
			else
				return cur;
		}

		return nullptr;
	}

	bool erase(const K& key) //替换法：把目标替换成左子树的最大值或右子树的最小值
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				if (cur->_left == nullptr) //左子树为空
				{
					if (cur == _root)
						_root = cur->_right;
					else
					{
						if (cur == parent->_right)
							parent->_right = cur->_right;
						else
							parent->_left = cur->_right;
					}
				}
				else if (cur->_right == nullptr) //右子树为空
				{
					if (cur == _root)
						_root = cur->_left;
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
				}
				else //左右子树都不为空
				{
					parent = cur;
					Node* leftmid = cur->_left;
					while (leftmid->_right)
					{
						parent = leftmid;
						leftmid = leftmid->_right;
					}
					swap(cur->_key, leftmid->_key);
					if (parent == cur)
						parent->_left = leftmid->_left;
					else
						parent->_right = leftmid->_left;
					cur = leftmid;
				}

				delete cur;
				return true;
			}
		}
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " : " << root->_val << endl;
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};