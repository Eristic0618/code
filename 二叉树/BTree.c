#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* CreateNewNode(BTDataType x) //创建新节点
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

BTNode* CreateBinaryTree() //创建二叉树
{
	BTNode* node1 = CreateNewNode(1);
	BTNode* node2 = CreateNewNode(2);
	BTNode* node3 = CreateNewNode(3);
	BTNode* node4 = CreateNewNode(4);
	BTNode* node5 = CreateNewNode(5);
	BTNode* node6 = CreateNewNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void PreOrder(BTNode* root) //二叉树前序遍历
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root) //二叉树中序遍历
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root) //二叉树后序遍历
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

void LevelOrder(BTNode* root) //二叉树层序遍历(需要用到队列)
{
	Queue que;
	QueueInit(&que);
	if (root)
		QueuePush(&que, root);
	while (!QueueEmpty(&que))
	{
		BTNode* front = QueueFront(&que);
		QueuePop(&que);
		printf("%d ", front->data);
		if (front->left != NULL)
			QueuePush(&que, front->left);
		if (front->right != NULL)
			QueuePush(&que, front->right);
	}
	QueueDestroy(&que);
}

int BTreeSize(BTNode* root) //求二叉树节点个数
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

int BTreeHeight(BTNode* root) //求二叉树的高度
{
	if (root == NULL)
		return 0;
	int leftHeight = BTreeHeight(root->left);
	int rightHeight = BTreeHeight(root->right);//必须要记录返回值，否则会重复计算
	return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
	//不记录返回值：重复计算
	/*return BTreeHeight(root->left) >= BTreeHeight(root->right) ? BTreeHeight(root->left) + 1 : BTreeHeight(root->right) + 1;*/
}

int BTreeLevelKSize(BTNode* root, int k) //求二叉树第k层节点个数
{
	assert(k > 0);
	if (root == NULL)
		return 0;
	int count = k - 1;
	if (count == 0)
		return 1;
	return BTreeLevelKSize(root->left, count) + BTreeLevelKSize(root->right, count);
}

int BTreeLeafSize(BTNode* root) //求二叉树叶子节点个数
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}

BTNode* BTreeFind(BTNode* root, BTDataType x) //在二叉树中查找值为x的节点
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* left = BTreeFind(root->left, x);
	if (left)
		return left;
	BTNode* right = BTreeFind(root->right, x);
	if (right)
		return right;
	return NULL;
}

void BTreeDestroy(BTNode* root) //销毁二叉树(后序遍历)
{
	if (root == NULL)
		return;
	BTreeDestroy(root->left);
	BTreeDestroy(root->right);
	free(root);
}

bool BTreeComplete(BTNode* root) //判断是否为完全二叉树
{
	Queue que;
	QueueInit(&que);
	if (root)
		QueuePush(&que, root);
	while (!QueueEmpty(&que))
	{
		BTNode* front = QueueFront(&que);
		if (front == NULL)
			break;
		QueuePop(&que);
		QueuePush(&que, front->left);
		QueuePush(&que, front->right);
	}
	while (!QueueEmpty(&que))
	{
		BTNode* front = QueueFront(&que);
		QueuePop(&que);
		if (front != NULL)
		{
			QueueDestroy(&que);
			return false;
		}
	}
	QueueDestroy(&que);
	return true;
}

void test1()
{
	BTNode* tree = CreateBinaryTree();
	PreOrder(tree);
	printf("\n");

	InOrder(tree);
	printf("\n");

	PostOrder(tree);
	printf("\n");

	LevelOrder(tree);
	printf("\n");

	printf("BTreeSize:%d\n", BTreeSize(tree));
	printf("BTreeHeight:%d\n", BTreeHeight(tree));
	printf("BTreeLevelKSize:%d\n", BTreeLevelKSize(tree, 3));
	printf("BTreeLeafSize:%d\n", BTreeLeafSize(tree));

	if (BTreeComplete(tree))
		printf("完全二叉树\n");
	else
		printf("非完全二叉树\n");

	BTreeDestroy(tree);
}

int main()
{
	BTNode* tree = CreateBinaryTree();
	if (BTreeComplete(tree))
		printf("完全二叉树\n");
	else
		printf("非完全二叉树\n");

	return 0;
}