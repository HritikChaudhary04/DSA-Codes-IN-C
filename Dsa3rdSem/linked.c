#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Data in node %d\n",ptr->data);
        ptr=->ptr next;
        struct Node *insertAtFirst(struct Node*head,int data)
        {
            struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
            ptr->next=head;
            ptr->data=data;
            return ptr;
        }
        struct Node *insertAtPosition(struct Node *head,int data,int position)
        {
            struct Node *extraNode=(struct Node*)malloc(sizeof(struct Node));
            struct Node *temp ptr=head;
            int i=0;
            while(i!=)
        }

    }
}