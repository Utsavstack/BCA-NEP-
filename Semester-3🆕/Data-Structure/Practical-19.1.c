#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    // Allocate memory for new node
    struct node *node = (struct node *)malloc(sizeof(struct node));

    // Assign data to this node
    node->data = data;

    // Initialize left and
    // right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    /*create root*/
    struct node *root = newNode(1);
    /* following is the tree after above statement
         1
        / \
    NULL   NULL
    */

    root->left = newNode(2);
    root->right = newNode(3);
    /* 2 and 3 become left and right children of 1
             1
           /   \
          2      3
        /   \  /   \
     NULL  NULL NULL NULL
    */

    root->left->left = newNode(4);
    /* 4 becomes left child of 2
             1
           /   \
          2      3
        /   \  /   \
      4   NULL NULL NULL
     / \
 NULL  NULL
    */
    preorder(root);
    return 0;
}
