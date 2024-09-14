#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int count;
    struct Node *left;
    struct Node *right;
};

typedef struct {
    struct Node *root;
} BinarySearchTree;

void insertNode(BinarySearchTree *tree, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->count = 1;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (tree->root == NULL) {
        tree->root = newNode;
    }
    struct Node *temp = tree->root;
    while (1) {
        if (temp->data == data) {
            temp->count++;
            return;
        }
        if (temp->data < data) {
            if (temp->right == NULL) {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        } else {
            if (temp->left == NULL) {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
    }
}

void findNode(BinarySearchTree *tree, int data) {
    if (tree->root == NULL) {
        return;
    }

    struct Node *temp = tree->root;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("founded: [%d] \n", temp->data);
            return;
        }
        if (temp->data < data) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }

    printf("not found \n");
}

void BFSTraverse(const struct Node *root) {
    printf("[%d] -> ", root->data);
    if (root->left != NULL) {
        BFSTraverse(root->left);
    }
    if (root->right != NULL) {
        BFSTraverse(root->right);
    }
}

void BreadthFirstSearch(const BinarySearchTree *tree) {
    if (tree->root == NULL) {
        return;
    }
    const struct Node *temp = tree->root;
    BFSTraverse(temp);
    printf("\n");
}

void PostOrderTraverse(const struct Node *root) {
    if (root->left != NULL) {
        PostOrderTraverse(root->left);
    }
    if (root->right != NULL) {
        PostOrderTraverse(root->right);
    }
    printf("[%d] -> ", root->data);
}

void DFSPostOrder(const BinarySearchTree *tree) {
    if (tree->root == NULL) {
        return;
    }
    const struct Node *temp = tree->root;
    PostOrderTraverse(temp);
    printf("\n");
}

void InOrderTraverse(const struct Node *root) {
    if (root->left != NULL) {
        PostOrderTraverse(root->left);
    }
    printf("[%d] -> ", root->data);
    if (root->right != NULL) {
        PostOrderTraverse(root->right);
    }
}

void DFSInOrder(const BinarySearchTree *tree) {
    if (tree->root == NULL) {
        return;
    }
    const struct Node *temp = tree->root;
    InOrderTraverse(temp);
    printf("\n");
}

int main(void)
{
    BinarySearchTree tree;
    insertNode(&tree, 10);
    insertNode(&tree, 20);
    insertNode(&tree, 5);
    insertNode(&tree, 15);
    insertNode(&tree, 1);
    insertNode(&tree, 10);

    findNode(&tree, 10);
    findNode(&tree, 1);
    findNode(&tree, 15);
    findNode(&tree, 0);
    BreadthFirstSearch(&tree);
    DFSPostOrder(&tree);
    DFSInOrder(&tree);
    return 0;
}
