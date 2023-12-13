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
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf("%d\t",root->data);
        inOrderTraversal(root->right);
    }
}

struct Node *searchBST(struct Node *root, int search){
    if(root == NULL){
        return NULL;
    }
    else if(search == root->data){
        return root;
    }
    else if(search < root->data){
        return searchBST(root->left,search);
    }
    else{
        return searchBST(root->right,search);
    }
}

void insertInBST(struct Node *root, int insert){
    struct Node *previous = NULL;

    while(root != NULL){
        previous = root;
        if(insert == root->data){
            printf("\nCANNOT INSERT %d AS IT ALREADY EXISTS.",insert);
            return;
        }
        else if(insert < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct Node *new = createNode(insert);
    if(new->data < previous->data){
        previous->left = new;
    }
    else{
        previous->right = new;
    }
}

void main()
{
    struct Node *root = createNode(5);
    struct Node *p1 = createNode(3);    
    struct Node *p2 = createNode(6);
    struct Node *c1 = createNode(1);
    struct Node *c2 = createNode(4);
    // struct Node *c3 = createNode(55);
    // struct Node *c4 = createNode(70);
    int insert;
    // int search;
    
    root->left = p1;
    root->right = p2;

    p1->left = c1;
    p1->right = c2;

    // p2->left = c3;
    // p2->right = c4;

    /* 
        TREE LOOKS LIKE
             50
           /    \
         40      60
        /  \    /  \
       20  45  55  70
    */

//    printf("ENTER THE ELEMENT YOU WANT TO SEARCH IN THE BST : ");
//    scanf("%d",&search);

//    printf("TRAVERSING THE BINARY SEARCH TREE THROUGH INORDER : \n");
//    struct Node *found = searchBST(root,search);
//    if(found !=NULL){
//         printf("ELEMENT %d IS FOUND.",found->data);
//    }
//    else{
//         printf("ERROR ELEMENT %d IS NOT FOUND",search);
//    }

    /* 
        TREE LOOKS LIKE
            5
           / \
          3   6
         / \
        1   4
    */

    inOrderTraversal(root);

    printf("\nENTER THE ELEMENT YOU WANT TO INSERT IN THE BST : ");
    scanf("%d",&insert);

    insertInBST(root,insert);
    // printf("%d",root->right->right->data);
    printf("\n");
    inOrderTraversal(root);
}