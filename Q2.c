#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 改用Ｃ寫
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *root, )
{
}

int pseudoPalindromicPaths(struct TreeNode *root, int s)
{
    if (!root)
        return 0;

    return -1;
}

struct TreeNode *newNode(int data)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = node->right = NULL;
    return (node);
}

struct TreeNode *insertLevelOrder(int arr[], struct TreeNode *root, int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        if (arr[i] == -1)
        {
            return NULL;
        }
        struct TreeNode *temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void inOrder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d \t", root->val);
        inOrder(root->right);
    }
}

int main()
{
    int arr[] = {2, 3, 1, 3, 1, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct TreeNode *root = insertLevelOrder(arr, root, 0, n);
    // rule : left -> center -> right
    inOrder(root);
    printf("\n");
    // printf("ans : %d", pseudoPalindromicPaths(root));
}