#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top=NULL;

void push(int value)
{
    struct Node *extraNode=(struct Node *)malloc(sizeof(struct Node));
    if(extraNode==NULL)
    {
        printf("Stack is overflowed\n");

    }
    else
    {
        extraNode->data=value;
        extraNode->next=top;
        top=extraNode;
    }
    void pop()
    {
        if(top==NULL)
        {
            printf("Stack is Underflow\n");
        }
        else
        {
            struct Node *temp;
        }
        
    }
}