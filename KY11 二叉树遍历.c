// https://www.nowcoder.com/share/jump/8993698061705806105481
// 编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
// 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
// 建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
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

BTNode *CreateNewNode(BTDataType x) // 创建新节点
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

void BTreeDestroy(BTNode *root) // 销毁二叉树
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