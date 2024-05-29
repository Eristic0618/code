#pragma once
#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:

	bool insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
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

		cur = new Node(key);

		if (key > prev->_key)
			prev->_right = cur;
		else
			prev->_left = cur;
		return true;
	}

	bool insertR(const K& key) //�ݹ�汾
	{
		return _insertR(_root, key);
	}

	bool find(const K& key)
	{
		Node* cur = _root;

		while (cur)
		{
			if (key > cur->_key)
				cur = cur->_right;
			else if (key < cur->_key)
				cur = cur->_left;
			else
				return true;
		}

		return false;
	}

	bool findR(const K& key) //�ݹ�汾
	{
		return _findR(_root, key);
	}

	bool erase(const K& key) //�滻������Ŀ���滻�������������ֵ������������Сֵ
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
				if (cur->_left == nullptr) //������Ϊ��
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
				else if(cur->_right == nullptr) //������Ϊ��
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
				else //������������Ϊ��
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

	bool eraseR(const K& key) //�ݹ�汾
	{
		return _eraseR(_root, key);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	BSTree() = default;

	BSTree(const BSTree<K>& t)
	{
		_root = copy(t._root);
	}

	~BSTree()
	{
		Destroy(_root);
	}

private:
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newroot = new Node(root->_key);
		newroot->_left = copy(root->_left);
		newroot->_right = copy(root->_right);

		return newroot;
	}

	void Destroy(Node*& root)
	{
		if (root == nullptr)
			return;

		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
		root = nullptr;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	bool _findR(Node* root, const K& key)
	{
		if (root == nullptr)
			return false;
		if (root->_key == key)
			return true;

		if (key > root->_key)
			return _findR(root->_right, key);
		else
			return _findR(root->_left, key);
	}

	bool _insertR(Node*& root, const K& key) //ָ��Ҫ�����ã���Ȼ���Ӳ���
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (key > root->_key)
			return _insertR(root->_right, key);
		else if (key < root->_key)
			return _insertR(root->_left, key);
		else
			return false;
	}

	bool _eraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
			return false;

		if (key > root->_key)
			return _eraseR(root->_right, key);
		else if (key < root->_key)
			return _eraseR(root->_left, key);
		else
		{
			if (root->_left == nullptr)
			{
				Node* tmp = root;
				root = root->_right; //�������ã�root�Ǹ��ڵ������ı��������Կ���ֱ���޸�
				delete tmp;
			}
			else if (root->_right == nullptr)
			{
				Node* tmp = root;
				root = root->_left;
				delete tmp;
			}
			else
			{
				Node* leftmid = root->_left;
				while (leftmid->_right)
					leftmid = leftmid->_right;
				swap(root->_key, leftmid->_key);
				return _eraseR(root->_left, key);
			}
			return true;
		}
	}
private:
	Node* _root = nullptr;
};


