#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *insert(struct node *head)
{
    int val, pri;
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the value and its priority: ");
    scanf("%d %d", &val, &pri);
    ptr->data = val;
    ptr->priority = pri;
    if (head == NULL || pri < head->priority){
        ptr->next = head;
        head = ptr;
    }
    else{
        p = head;
        while (p->next != NULL && p->next->priority <= pri){
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return head;
}
void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    printf("\n Displaying Priority Queue:\n");
    while (ptr != NULL){
        printf(" %d (%d) -> ", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    int option;
    struct node *head = NULL;

    do{
        printf("\n\n 1. Insert ");
        printf("\n 2. Display ");
        printf("\n 3. Exit ");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option){
            case 1: head = insert(head);
                break;
            case 2: display(head);
                break;
            case 3: exit(0);
            default: printf("\n\n Invalid option, please try again!");
        }
    }while (option != 3);

    return 0;
}
