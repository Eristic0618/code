#pragma once

enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T, class Ref, class Ptr>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator--()
	{
		Node* parent = _node->_parent;
		if (_node->_left)
			_node = _node->_left;
		else if (_node == parent->_right)
			_node = parent;
		else
		{
			Node* cur = _node;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			Node* cur = _node->_right;
			while (cur->_left)
				cur = cur->_left;
			_node = cur;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T, T&, T*> iterator;
	typedef __TreeIterator<T, const T&, const T*> const_iterator;
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
			cur = cur->_left;
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
			cur = cur->_left;
		return const_iterator(cur);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr);
	}

	pair<Node*, bool> insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		KeyOfT kot;

		while (cur)
		{
			parent = cur;
			if (kot(data) > kot(cur->_data))
				cur = cur->_right;
			else if (kot(data) < kot(cur->_data))
				cur = cur->_left;
			else
				return make_pair(cur, false);
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED; //新节点默认为红色
		if (kot(data) > kot(parent->_data))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		while (parent && parent->_col == RED) //若父节点不存在说明走到根，若父节点为黑色则不需要处理
		{
			Node* grandfather = parent->_parent; //记录祖父节点

			if (grandfather->_left == parent) //父节点在祖父节点左边时
			{
				Node* uncle = grandfather->_right; //记录叔叔节点

				if (uncle && uncle->_col == RED) //如果叔叔节点存在且为红色
				{
					//变色
					parent->_col = uncle->_col = BLACK; //将父节点与叔叔节点都变为黑色
					grandfather->_col = RED; //将祖父节点变为红色
					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;  
				}
				else //叔叔节点不存在或为黑色
				{
					//需要旋转+变色
					if (parent->_left == cur) //cur节点在父节点左边，右单旋
					{
						RotateRight(grandfather);
						//变色
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else //cur节点在父节点右边，左右双旋
					{
						RotateLeft(parent);
						RotateRight(grandfather);
						//变色
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else //父节点在祖父节点右边，和上面同理
			{
				Node* uncle = grandfather->_left;

				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_right == cur)
					{
						RotateLeft(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateRight(parent);
						RotateLeft(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK; //无论如何，都将根变为黑色
		return make_pair(newnode, true);
	}

	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;

		if (parent != _root)
		{
			subR->_parent = parentParent;
			if (parent == parentParent->_left)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;
		}
		else
		{
			_root = subR;
			subR->_parent = nullptr;
		}

		subR->_left = parent;
		parent->_parent = subR;
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		if (parent != _root)
		{
			subL->_parent = parentParent;
			if (parent == parentParent->_left)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;
		}
		else
		{
			_root = subL;
			subL->_parent = nullptr;
		}

		subL->_right = parent;
		parent->_parent = subL;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		if (_root == nullptr)
			return true;
		if (_root->_col == RED)
		{
			cout << "异常：根为红色" << endl;
			return false;
		}
		
		//预先求出某条路径的黑色节点数量
		size_t blackcount = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				blackcount++;
			cur = cur->_left;
		}

		size_t k = 0;
		return _IsBalance(_root, k, blackcount);
	}

	iterator Find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (key > kot(cur->_data))
				cur = cur->_right;
			else if (key < kot(cur->_data))
				cur = cur->_left;
			else
				return iterator(cur);
		}
		return iterator(nullptr);
	}

	int Height()
	{
		return _Height(_root);
	}

	size_t Size()
	{
		return _Size(_root);
	}
private:
	void _InOrder(Node* root)
	{
		KeyOfT kot;
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << kot(root->_data) << " ";
		_InOrder(root->_right);
	}

	bool _IsBalance(Node* root, size_t k, size_t blackcount)
	{
		if (root == nullptr)
		{
			if (k != blackcount)
			{
				cout << "异常：路径黑节点数目不同" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "异常：出现连续红节点" << endl;
			return false;
		}
		if (root->_col == BLACK)
			k++;

		return _IsBalance(root->_left, k, blackcount)
			&& _IsBalance(root->_right, k, blackcount);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int higher = max(_Height(root->_left), _Height(root->_right));
		return higher + 1;
	}

	size_t _Size(Node* root)
	{
		if (root == nullptr)
			return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}
private:
	Node* _root = nullptr;
};

