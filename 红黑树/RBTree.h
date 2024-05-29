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
		cur->_col = RED; //�½ڵ�Ĭ��Ϊ��ɫ
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

		while (parent && parent->_col == RED) //�����ڵ㲻����˵���ߵ����������ڵ�Ϊ��ɫ����Ҫ����
		{
			Node* grandfather = parent->_parent; //��¼�游�ڵ�

			if (grandfather->_left == parent) //���ڵ����游�ڵ����ʱ
			{
				Node* uncle = grandfather->_right; //��¼����ڵ�

				if (uncle && uncle->_col == RED) //�������ڵ������Ϊ��ɫ
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK; //�����ڵ�������ڵ㶼��Ϊ��ɫ
					grandfather->_col = RED; //���游�ڵ��Ϊ��ɫ
					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;  
				}
				else //����ڵ㲻���ڻ�Ϊ��ɫ
				{
					//��Ҫ��ת+��ɫ
					if (parent->_left == cur) //cur�ڵ��ڸ��ڵ���ߣ��ҵ���
					{
						RotateRight(grandfather);
						//��ɫ
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else //cur�ڵ��ڸ��ڵ��ұߣ�����˫��
					{
						RotateLeft(parent);
						RotateRight(grandfather);
						//��ɫ
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else //���ڵ����游�ڵ��ұߣ�������ͬ��
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
		_root->_col = BLACK; //������Σ���������Ϊ��ɫ
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
			cout << "�쳣����Ϊ��ɫ" << endl;
			return false;
		}
		
		//Ԥ�����ĳ��·���ĺ�ɫ�ڵ�����
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
				cout << "�쳣��·���ڽڵ���Ŀ��ͬ" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "�쳣������������ڵ�" << endl;
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

