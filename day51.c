#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct node* insert(struct node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

struct node* findLCA(struct node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

   
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    return root;
}

int main() {
    int n, x, n1, n2;
    struct node* root = NULL;


    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &n1, &n2);

 
    struct node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}