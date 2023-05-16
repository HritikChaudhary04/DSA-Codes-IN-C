#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the book structure
struct book {
    int id;
    char title[50];
    char author[50];
    int year;
    struct book *next;
};

// Function prototypes
void display_menu();
void add_book();
void display_all_books();
void search_book();
void delete_book();

int main() {
    display_menu();
    return 0;
}

// Display the main menu
void display_menu() {
    int choice;
    do {
        printf("\n\n*** Library Management System Menu ***\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("\nExiting the program...");
                break;
            case 1:
                add_book();
                break;
            case 2:
                display_all_books();
                break;
            /*case 3:
                search_book();
                break;
            case 4:
                delete_book();
                break;
            default:
                printf("\nInvalid choice. Please try again.");*/
        }
    } while (choice != 0);
}

// Add a new book to the library
void add_book() {
    struct book *new_book, *current;
    int id, year;
    char title[50], author[50];

    // Read in the book data
    printf("\nEnter the Book ID: ");
    scanf("%d", &id);
    printf("Enter the Book Title: ");
    scanf("%s", title);
    printf("Enter the Book Author: ");
    scanf("%s", author);
    printf("Enter the Year of Publication: ");
    scanf("%d", &year);

    // Allocate memory for the new book
    new_book = (struct book*) malloc(sizeof(struct book));
    new_book->id = id;
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->year = year;
    new_book->next = NULL;

    // Append the new book to the end of the linked list
    current = new_book;
    FILE *fp;
    fp = fopen("library.txt", "a");
    fprintf(fp, "%d %s %s %d\n", new_book->id, new_book->title, new_book->author, new_book->year);
    fclose(fp);
    printf("\nBook added successfully!");
}

// Display all books in the library
void display_all_books() {
    struct book *current;
    FILE *fp;
    fp = fopen("library.txt", "r");
    if(fp == NULL){
        printf("\nNo Books added to the library!");
    }
    else{
        printf("\nAll Books in the Library:\n");
        while (!feof(fp)) {
            current = (struct book*) malloc(sizeof(struct book));
            fscanf(fp, "%d %s %s %d", &current->id, current->title, current->author, &current->year);
            printf("\nID: %d\nTitle: %s\nYear of Publication: %d\n", current->id, current->title,current->year);
        }
    }
}
