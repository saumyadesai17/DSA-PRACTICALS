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

struct Node *inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d\t",root->data);
        inOrderTraversal(root->right);
    }
}

struct Node *inOrderPredecessor(struct Node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct Node *deleteElementFromBST(struct Node *root, int value){
    struct Node *pre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(value < root->data){
        root->left = deleteElementFromBST(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteElementFromBST(root->right, value);
    }
    else{
        pre = inOrderPredecessor(root);
        root->data = pre->data;
        root->left = deleteElementFromBST(root->left, pre->data);
    }
    return root;
}

void main()
{
    int value;
    struct Node *root = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *c1 = createNode(1);
    struct Node *c2 = createNode(4);

    root->left = p1;
    root->right = p2;

    p1->left = c1;
    p1->right = c2;

    /* 
        TREE LOOKS LIKE
            5
           / \
          3   6
         / \
        1   4
    */


    printf("INORDER TRAVERSAL : \n");
    inOrderTraversal(root);

    printf("\nENTER THE ELEMENT YOU WANT TO DELETE : ");
    scanf("%d",&value);

    deleteElementFromBST(root,value);
    inOrderTraversal(root);
}