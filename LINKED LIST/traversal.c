#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *deleteAtBeginning(struct Node*head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node*head,int index){
    struct Node *ptr = head;
    int i=0;
    while(i!=index-2){
        ptr = ptr->next;
        i++;
    }
    struct Node *q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

struct Node *deleteAtEnd(struct Node*head){
    struct Node *ptr = head;
    struct Node *q = head->next;
    while(q->next != NULL){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtValue(struct Node *head,int value){
    struct Node *ptr = head;
    struct Node *q = head->next;
    if(ptr->data == value){
        deleteAtBeginning(head);
    }
    else{
        while(q->data!=value && q->next!=NULL){
            ptr = ptr->next;
            q = q->next;
        }
        if(q->data == value){
            ptr->next = q->next;
            free(q);
        }
        else{
            printf("ENTER A VALID INPUT\n");
        }
        return head;
    }
}

struct Node *linkedlisttraversal(struct Node*head){
    struct Node *ptr = head;
    while(ptr!=NULL){
        printf("ELEMENT IS : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

void main()
{
    printf("HELLO WORLD\n\n");

    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));
    int index,value;

    // FOR DELETING A NODE IN BETWEEN A LINKED LIST
    // printf("ENTER THE INDEX YOU WANT TO DELETE THE NODE AT : ");
    // scanf("%d",&index);

    head->data = 55;
    head->next = second;

    second->data = 65;
    second->next = third;

    third->data = 75;
    third->next = fourth;

    fourth->data = 85;
    fourth->next = NULL;

    linkedlisttraversal(head);

    printf("ENTER THE VALUE YOU WANT TO DELETE THE NODE AT : ");
    scanf("%d",&value);

    printf("\nLINKED LIST BEFORE DELETION\n");
    linkedlisttraversal(head);

    printf("\nLINKED LIST AFTER DELETION\n");
    // head = deleteAtBeginning(head);
    // head = deleteAtIndex(head,index);
    head = deleteAtValue(head,value);
    linkedlisttraversal(head);
}