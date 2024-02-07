// https://www.nowcoder.com/share/jump/8993698061705806105481
// ��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
// �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
// ������˶������Ժ��ٶԶ������������������������������
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BTNode;

BTNode *CreateNewNode(BTDataType x) // �����½ڵ�
{
    BTNode *newnode = (BTNode *)malloc(sizeof(BTNode));
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

void BTreeDestroy(BTNode *root) // ���ٶ�����
{
    if (root == NULL)
        return;
    BTreeDestroy(root->left);
    BTreeDestroy(root->right);
    free(root);
}

BTNode *TreeBuild(char *arr, int *pi)
{
    if (arr[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    else
    {
        BTNode *root = CreateNewNode(arr[*pi]);
        (*pi)++;
        root->left = TreeBuild(arr, pi);
        root->right = TreeBuild(arr, pi);
        return root;
    }
}

void InOrder(BTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}

int main()
{
    char arr[100];
    scanf("%s", arr);
    int i = 0;
    BTNode *root = TreeBuild(arr, &i);
    InOrder(root);
    BTreeDestroy(root);
    return 0;
}