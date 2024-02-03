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

BTNode* CreateNewNode(BTDataType x) //�����½ڵ�
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

BTNode* CreateBinaryTree() //����������
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

void PreOrder(BTNode* root) //������ǰ�����
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

void InOrder(BTNode* root) //�������������
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

void PostOrder(BTNode* root) //�������������
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

void LevelOrder(BTNode* root) //�������������(��Ҫ�õ�����)
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

int BTreeSize(BTNode* root) //��������ڵ����
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

int BTreeHeight(BTNode* root) //��������ĸ߶�
{
	if (root == NULL)
		return 0;
	int leftHeight = BTreeHeight(root->left);
	int rightHeight = BTreeHeight(root->right);//����Ҫ��¼����ֵ��������ظ�����
	return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
	//����¼����ֵ���ظ�����
	/*return BTreeHeight(root->left) >= BTreeHeight(root->right) ? BTreeHeight(root->left) + 1 : BTreeHeight(root->right) + 1;*/
}

int BTreeLevelKSize(BTNode* root, int k) //���������k��ڵ����
{
	assert(k > 0);
	if (root == NULL)
		return 0;
	int count = k - 1;
	if (count == 0)
		return 1;
	return BTreeLevelKSize(root->left, count) + BTreeLevelKSize(root->right, count);
}

int BTreeLeafSize(BTNode* root) //�������Ҷ�ӽڵ����
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}

BTNode* BTreeFind(BTNode* root, BTDataType x) //�ڶ������в���ֵΪx�Ľڵ�
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

void BTreeDestroy(BTNode* root) //���ٶ�����(�������)
{
	if (root == NULL)
		return;
	BTreeDestroy(root->left);
	BTreeDestroy(root->right);
	free(root);
}

bool BTreeComplete(BTNode* root) //�ж��Ƿ�Ϊ��ȫ������
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
		printf("��ȫ������\n");
	else
		printf("����ȫ������\n");

	BTreeDestroy(tree);
}

int main()
{
	BTNode* tree = CreateBinaryTree();
	if (BTreeComplete(tree))
		printf("��ȫ������\n");
	else
		printf("����ȫ������\n");

	return 0;
}