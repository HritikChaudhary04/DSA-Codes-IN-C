#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


char password[20]="00000";


struct node
{
    int data;
    int studentid;
    char bookname[50],author[20];
    struct node* link;    //points to another node
};

struct node* root=NULL;
struct node* issue=NULL;

void append()
{
    system("cls");
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node)); //new node create gareko
    printf("Enter book id,name and author : \n");
    scanf("%d \n",&temp->data);
    scanf("%[^\n]\n",&temp->bookname);
    scanf("%[^\n]",&temp->author);
    temp->studentid=0;
    temp->link=NULL;
    if(root==NULL) //list is empty
    {
        root=temp;
        printf("\tBook added successfully\n");
        printf("\n");
    }
    else //list is not empty
    {
        struct node* p;
        p=root;
        while(p->link != NULL)   //p ko link bhanna ley
        {
            p=p->link;
        }
        p->link=temp;

        printf("\tBook added successfully\n");
        printf("\n");
    }
}

int length()   //library ma kati ota book xa
{
    system("cls");
    struct node* temp;
    temp=root;
    int count=0;
    while(temp !=NULL)
    {
        count++;   // suru ma leko because temp le first node lai pahilai point garisakeko cha
        temp=temp->link;

    }
    return count;
}

void display()  //info primt garne
{
    system("cls");
    struct node* temp;
    int count=0;
    temp=root;
    if(temp==NULL)
    {
        printf("\tList is empty\n");
        printf("\n");
    }
    else
    {
        while(temp !=NULL)
        {
            count++;                                                // suru ma leko because temp le first node lai pahilai point garisakeko cha
            printf("\tbook id = %d-->\n",temp->data);               //printing node ko value
            printf("\tbook name = %s-->\n",temp->bookname);
            printf("\tAuthor = %s-->\n",temp->author);
            printf("\n");
            printf("\n");
            temp=temp->link;
        }  
        printf("\t%d results found.\n",count);  
    }
    printf("\n");
}

void displayAvailable()
{
    system("cls");
    struct node* temp;
    int count=0;
    temp=root;
    if(temp==NULL)
    {
        printf("\tList is empty\n");
        printf("\n");
        printf("\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->studentid==0)      
            {
                count++;
                printf("\tbook id = %d-->\n",temp->data);
                printf("\tbook name = %s-->\n",temp->bookname);
                printf("\tAuthor = %s-->\n",temp->author);
                printf("\n");
                printf("\n");
                
            }
            temp=temp->link;
        } 
        if(count==0)
        {
            printf("\tAll Books are Issued. None books Availabel\n");
            printf("\n");
            printf("\n");
        }
        else
        {
            printf("\t%d books available\n",count);
            printf("\n");
            printf("\n");
        } 
    }
    printf("\n");
}

void delete()
{
    system("cls");
    struct node* temp,*p,*q;
    temp=root;
    int value,len;
    
    len=length();
    if(len==0)
    {
        printf("\tThe list is empty\n");
        printf("\n");
    }
    else
    {
        printf("\tEnter the id to be deleted: ");
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
                printf("\tBook Deleted Successfully\n");
                printf("\n");
                printf("\n");
            }
            else if(value == temp->data)
            {
                p->link=temp->link; 
                temp->link=NULL;
                free(temp);
                printf("\tBook Deleted Successfully\n");
                printf("\n");
                printf("\n");
            } 
            else
            {
                printf("\tID not found\n");
                printf("\n");
                printf("\n");
            } 
    }
    
}
void returnbook()
{
    system("cls");
    struct node* temp,*p,*q,*ret;
    temp=issue;
    ret=root;
    int value,len;
    printf("\tEnter the book id to be retured: \n");
    scanf("%d",&value);
        while(value != temp->data && temp->link!=NULL)
        {
                p=temp;
                temp=temp->link;
                    
        }
        if(value ==temp->data && temp==issue)
        {
            issue=temp->link;
            temp->link=NULL;
            free(temp);
            printf("\tBook Returned Succesfully\n");
            printf("\n");
            printf("\n");
        }
        else if(value == temp->data)
        {
            p->link=temp->link; 
            temp->link=NULL;
            free(temp);
            printf("\tBook Returned Succesfully\n");
            printf("\n");
            printf("\n");
        } 
        else
        {
            printf("\tID not found\n");
            printf("\n");
            printf("\n");
        } 

            while(value!=ret->data && ret->link!=NULL)
            {
                ret=ret->link;
            }
            if(value==ret->data)
            {
                ret->studentid=0;
            }
            else
            {
                printf("\tBook Is Not In System\n");
                printf("\n");
                printf("\n");
            }
    
    
}
void addtoafter()
{
    system("cls");
    struct node* p,*temp;
    int value,len;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\tEnter book id,name and author : \n");
    scanf("%d \n",&temp->data);
    scanf("%[^\n]\n",&temp->bookname);
    scanf("%[^\n]",&temp->author);
    temp->link=NULL;
    temp->studentid=0;
    printf("\n");
    printf("\tThe value after which it should be added:\n");
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
                printf("\tBook added successfully\n");
                printf("\n");
                printf("\n");
            }
            else
            {
                printf("\tId not found.\n");
                printf("\n");
                printf("\n");
            }
    }

}
void issuebook()
{
    system("cls");
    struct node* temp,*p;
    int value,len;
    printf("\tenter the id of book to be issued\n");
    scanf("%d",&value);
    temp=root;
    len=length();
    if(len==0)
    {
       printf("\tNo books available to be issued\n");
       printf("\n");
       printf("\n");
    }
    else
    {
        while(value != temp->data && temp->link!=NULL)
            {
                    temp=temp->link;            
            }
            if(value==temp->data)
            {
                if(temp->studentid!=0)
                {
                    printf("\tBook already issued.\n");
                    printf("\n");
                    printf("\n");
                }
                else
                {
                    printf("Enter the student id:\n");
                    scanf("%d",&temp->studentid);
                    p=(struct node*)malloc(sizeof(struct node));
                    p->data=temp->data;
                    strcpy(p->bookname,temp->bookname);
                    strcpy(p->author,temp->author);
                    p->studentid=temp->studentid;
                    p->link=NULL; 
                    if(issue==NULL)
                    {
                        issue=p;
                        printf("\tBook Issued Succesfully\n");
                        temp=root;
                        printf("\n");
                        printf("\n");
                    }
                    else
                    {
                        struct node *q;
                        q=issue;
                        while(q->link!=NULL) 
                        {
                            q=q->link;
                        }
                        q->link=p;
                        temp=root;
                        printf("\tBook Issued Succesfully\n");
                        printf("\n");
                        printf("\n");
                    }
                }
                
            }
            else
            {
                printf("\tId not found.\n");
                printf("\n");
                printf("\n");
            }
    }
   
}
void searchissue()
{
    system("cls");
    struct node* temp;
    int value,count=0;
    printf("Enter student id:\n");
    scanf("%d",&value);
    temp=issue;
    while(temp!=NULL)
    {
        if(value==temp->studentid)
        {
            count++;
            printf("\tBook issued by student ID %d\n",temp->studentid);
            printf("%d \n\n",count);
            printf("\tbook id = %d-->\n",temp->data);
            printf("\tbook name = %s-->\n",temp->bookname);
            printf("\tAuthor = %s-->\n",temp->author);
            printf("\n");
            printf("\n");
        }
        temp=temp->link;
    }
    if(count==0)
    {
        printf("\tNo record found");
        printf("\n");
        printf("\n");
    }
    else
    {
        printf("\tTotal %d result found.\n",count);
        printf("\n");
        printf("\n");
    }

}
void addtobegin()
{
    system("cls");
    struct node* temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\tEnter book id,name and author : \n");
    scanf("%d \n",&temp->data);
    scanf("%[^\n]\n",&temp->bookname);
    scanf("%[^\n]",&temp->author);
    temp->link=NULL;
    temp->studentid=0;
    printf("\n");
    if(root==NULL)
    {
        root=temp;
        printf("\t Book added Successfully\n");
        printf("\n");
        printf("\n");
    }
    else
    {
        temp->link=root;
        root=temp;
        printf("\t Book added Successfully\n");
        printf("\n");
        printf("\n");
    }
}

void displayIssue()
{
    system("cls");
    struct node * temp;
    temp=issue;
    int count=0;
    if(temp==NULL)
    {
        printf("\tList is empty\n");
        printf("\n");
        printf("\n");
    }
    else
    {
        while(temp !=NULL)
        {
            if(temp->studentid!=0)
            {
                count++;
                printf("\tbook id = %d-->\n",temp->data);
                printf("\tbook name = %s-->\n",temp->bookname);
                printf("\tAuthor = %s-->\n",temp->author);
                printf("\n");
                printf("\tTotal %d books are issued\n",count);
                printf("\n");
                printf("\n");
            }
            
            temp=temp->link;
        }    
    }
    printf("\n");
}


void search()
{
    system("cls");
    int id,value,count=0;
    char string[20];
    printf("\tEnter name of book to be searched\n");
    scanf(" %[^\n]",string);
    struct node* temp;
    temp=root;
    while(temp!=NULL)
    {
        value=strcmp(string,temp->bookname);
        if(value==0)
        {
            count++;
            printf("%d \n",count);
            printf("\tbook id = %d-->\n",temp->data);
            printf("\tbook name = %s-->\n",temp->bookname);
            printf("\tAuthor = %s-->\n",temp->author);
            printf("\n");
        }
        temp=temp->link;
    }
    if(count==0)
    {
        printf("\tGiven book not found\n");
        printf("\n");
        printf("\n");
    }
    else
    {
        printf("\tTotal %d result found.\n",count);
        printf("\n");
        printf("\n");
    }
}
int main()
{
    system("cls");
    int ch;
    int len;
    int option;
    while(1)
    {
        printf("\t\tWelcome to library managenment system:\n\n\n");
        printf("\t\tCreated By:\n \t\t\tHritik Chaudhary\n \t\t\tPriya Jaiswal\n \t\t\tSabal Humagain\n\n");
        printf("\t**********************************************\n");
        printf("\t     ********************************\n");
        printf("\t          ***********************\n");
        printf("\t              *************\n");
        printf("\t                  *****\n");
        printf("\n");
        printf("\n");
        printf("\tAre you:\n");
        printf("\t1: Library Staff\n");
        printf("\t2. Student\n");
        printf("\t3.Exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: system("cls");
                    char pass[20];
                    int value;
                    printf("\tEnter your password:\n");
                    scanf("%s",&pass);
                    value=strcmp(pass,password);
                    if(value==0)
                    {
                        while(1)
                        {
                            printf("\t1.Add new book\n");
                            printf("\n");
                            printf("\t2.Add at begin of list\n");
                            printf("\n");
                            printf("\t3.Add after any specified book\n");
                            printf("\n");
                            printf("\t4:No of total Books In Library\n");
                            printf("\n");
                            printf("\t5.Display All Books\n");
                            printf("\n");
                            printf("\t6.Delete book from list\n");
                            printf("\n");
                            printf("\t7:Issue Book\n");
                            printf("\n");
                            printf("\t8.Search Book\n");
                            printf("\n");
                            printf("\t9:Search Student's Issued Book\n");
                            printf("\n");
                            printf("\t10:List Of all Issued Books\n");
                            printf("\n");
                            printf("\t11:exit\n\n");

                            printf("\tEnter your Choice: \n");
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
                                        printf("No of Books in Library = %d\n",len);
                                        printf("\n");
                                        printf("\n");
                                        break;
                                case 5:display();
                                        break;
                                case 6:delete();
                                        break;
                                case 7:issuebook();
                                        break;
                                case 8:search();
                                        break; 
                                case 9:searchissue();
                                        break;
                                case 10:displayIssue();
                                        break;
                                case 11: main();
                                default:printf("Invalid Input\n");

                            }
                        }
                    }
                else
                {
                    printf("\t\tIncorrect password\n");
                    break;
                }
            case 2:system("cls");
                    while(1)
                    {
                        int choice;
                        printf("\t1: ALL Books Available:\n");
                        printf("\n");
                        printf("\t2: Search Book\n");
                        printf("\n");
                        printf("\t3. issued book\n");
                        printf("\n");
                        printf("\t4. Return book\n");
                        printf("\n");
                        printf("\t5: exit\n");
                        printf("\n");
                        printf("\tEnter your Choice\n");
                        printf("\n");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1:displayAvailable();
                                    break;
                            case 2:search();
                                    break;
                            case 3: searchissue();
                                    break;
                            case 4: returnbook();
                                    break;
                            case 5:main();
                            default: printf("\t\tInvalid Input\n");        
                        }
                    }
            case 3:exit(0);
            default:printf("\t\tInvalid Input\n");
        }    
            
        
    }
return 0;
}