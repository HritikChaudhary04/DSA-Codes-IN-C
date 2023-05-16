#include <stdio.h>
#include <stdlib.h> 

struct node
{
    int data;
    struct node* link;
};

struct node* root=NULL;

void swap(int loc)
{
    struct node* temp,*p,*r;
    temp=root;
}