#include<stdio.h>

int main()
{
    char string[20];
    printf("Enter name of book to be searched\n");
    scanf("%[^\n]",string);
    printf("%s",string);
    return 0;
}