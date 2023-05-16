/*Implementation of all stack operations using static array*/

#include<stdio.h>
#include <stdlib.h>

#define CAPACITY 5 //pre processor macro
int stack[CAPACITY];
int top=-1;

int isFull()
{
    if(top==(CAPACITY-1))
    {
        printf("top = %d\n",top);
        return 1;
    }
    else
    {
        printf("top = %d\n",top);
        return 0;
    }
}

int isEmpty()
{
    if(top==-1)
    {
        printf("top = %d\n",top);
        return 1;
    }
    else
    {
        printf("top = %d\n",top);
        return 0;
    }
}

void push(int ele)
{
    if(isFull())
    {
        printf("top = %d\n",top);
        printf("The stack is full\n");
    }
    else
    {
        top++;
        stack[top]=ele;
        printf("top = %d\n",top);
    }
    
}

int pop()
{
    int del;
    if(isEmpty())
    {
        printf("top = %d\n",top);
        return 0;
    }
    else
    {
        del=stack[top];
        top--;
        printf("top = %d\n",top);
        return stack[top+1];
    }
}

int peek()
{
    if(isEmpty())
    {
        printf("top = %d\n",top);
        return 0;
    }
    else
    {
        printf("top = %d\n",top);
        return stack[top];
    }
}

void traverse()
{
    if(isEmpty())
    {
        printf("No elements\n");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int ch,item;
    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Quit\n");

        printf("enter your choice : ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1 :printf("Enter element : ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2 : item=pop();
                    if(item==0)
                    {
                        printf("The stack is empty\n");
                    }
                    else
                    {
                        printf("The removed item is %d\n",item);
                    }
                    break;
            case 3 : item = peek();
                    if(item==0)
                    {
                        printf("The stack is empty\n");

                    }
                    else
                    {
                        printf("The top item is %d\n",item);
                    }
                    break;
            case 4 : traverse();
                    break;
            case 5 : exit(0);
            default : printf("Invalid input \n\n");
        }
    }
    return 0;    
}