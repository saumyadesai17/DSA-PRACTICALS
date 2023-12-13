#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *preOrderTreeTraversal(struct Node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preOrderTreeTraversal(root->left);
        preOrderTreeTraversal(root->right);
    }
}

struct Node *postOrderTreeTraversal(struct Node *root){
    if(root!=NULL){
        postOrderTreeTraversal(root->left);
        postOrderTreeTraversal(root->right);
        printf("%d\t",root->data);
    }
}

struct Node *inOrderTreeTraversal(struct Node *root){
    if(root!=NULL){
        inOrderTreeTraversal(root->left);
        printf("%d\t",root->data);
        inOrderTreeTraversal(root->right);
    }
}

void main()
{
    struct Node *root = createNode(4);
    struct Node *p1 = createNode(1);    
    struct Node *p2 = createNode(6);
    struct Node *c1 = createNode(5);
    struct Node *c2 = createNode(2);
    // struct Node *c4 = createNode(3);
    
    root->left = p1;
    root->right = p2;

    p1->left = c1;
    p1->right = c2;

    p2->left = NULL;
    p2->right = NULL;

    /* 
        TREE LOOKS LIKE
            4
           / \
          1   6
         / \
        5   2
    */

    // printf("TRAVERSING THE TREE THROUGH PREORDER METHOD : \n");
    // printf("TRAVERSING THE TREE THROUGH POSTORDER METHOD : \n");
    printf("TRAVERSING THE TREE THROUGH INORDER METHOD : \n");
    inOrderTreeTraversal(root);
}