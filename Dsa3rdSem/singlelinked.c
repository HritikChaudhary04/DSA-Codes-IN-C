#include <stdio.h>
#include <stdlib.h> 

struct node
{
    int data;
    struct node* link;
};

struct node* root=NULL;

void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data: \n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        while(p->link != NULL)
        {
            p=p->link;
        }
        p->link=temp;

        printf("Node added successfully\n");
    }
    
}

int length()
{
    struct node* temp;
    temp=root;
    int count=0;
    while(temp !=NULL)
    {
        count++;
        temp=temp->link;

    }
    return count;
}

void display()
{
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp !=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }    
    }
    printf("\n");
}

void delete()
{
    struct node* temp,*p,*q;
    temp=root;
    int value,len;
    
    len=length();
    if(len==0)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("Enter the value to be deleted: ");
        scanf("%d",&value);
            while(value != temp->data && temp->link!=NULL)
            {
                    p=temp;
                    temp=temp->link;
                        
            }
            if(value ==temp->data && temp==root)
            {
                root=temp->link;
                temp->link=NULL;
                free(temp);
            }
            else if(value == temp->data)
            {
                p->link=temp->link; 
                temp->link=NULL;
                free(temp);
            } 
            else
            {
                printf("ID not found\n");
            } 
    }
    
}

void addtoafter()
{
    struct node* p,*temp;
    int value,len;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be added: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    printf("\n");
    printf("The value after which it should be added:\n");
    scanf("%d",&value);
    p=root;
    len=length();
    if(len==0)
    {
       root=temp;
    }
    else
    {
        while(value != p->data && p->link!=NULL)
            {
                    p=p->link;            
            }
            if(value==p->data)
            {
                temp->link=p->link;
                p->link=temp;
            }
            else
            {
                printf("Id not found.\n");
            }
    }

}
void addtobegin()
{
    struct node* temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be added: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    printf("\n");
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}
void swap()
{
    struct node* temp,*p,*q;
    temp=root;
    int value;
    printf("Enter value needed to swap with adjacent element\n");
    scanf("%d",&value);
    while(value!=temp->data && temp!=NULL)
    {
        p=temp;
        temp=temp->link;
    }
    if(value==temp->data && temp==root)
    {
        q=temp->link;
        temp->link=q->link;
        q->link=temp;
        root=q;
    }
    else if(value==temp->data)
    {
        q=temp->link;
        temp->link=q->link;
        q->link=temp;
        p->link=q;
    }
    else
    {
        printf("Number not found\n");
    }
}

void search()
{
    int value,count=0;
    struct node* temp;
    temp=root;
    printf("Enter data to be searched\n");
    scanf("%d",&value);
    while(temp!=NULL)
    {
        if(value==temp->data)
        {
            count++;
            printf("%d . %d\n",count,temp->data);
        }
        temp=temp->link;
    }
    if(count==0)
    {
        printf("Given data not found");
    }
    else
    {
        printf("Total %d result found.\n",count);
    }
}
int main()
{
    int ch;
    int len;
    while(1)
    {
        printf("Single Linked List Implementation:\n\n\n");
        printf("1.append(add at the last)\n");
        printf("2.addatbegin\n");
        printf("3.addatafter\n");
        printf("4:length\n");
        printf("5.display\n");
        printf("6.delete\n");
        printf("7.swap\n");
        printf("8.search\n");
        printf("9:exit\n\n");

        printf("Enter your Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:append();
                    break;
            case 2:addtobegin();
                    break;
            case 3:addtoafter();
                    break;
            case 4:len=length();
                    printf("No of Node = %d\n",len);
                    break;
            case 5:display();
                    break;
            case 6:delete();
                    break;
            case 7:swap();
                    break;
            case 8:search();
                    break;                
            case 9:exit(0);
            default:printf("Invalid Input\n");

        }

    }
    return 0;
}