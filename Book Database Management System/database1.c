#include "database_main.h"


/* menu_add_book():
 *
 * Add new book to database
 */
void menu_add_book(void)
{
	char title[10000], author[10000], year_str[100], *pos;
	int year;
	struct Book *book;
	
	book = (struct Book *) malloc(sizeof(struct Book));

	while(1) {
		fprintf(stderr, "Give title: ");
		fflush(stderr);
		fgets(title, 99999, stdin);
		if ((pos=strchr(title, '\n')) != NULL)
			*pos = '\0';
	
		if (title[0] != '\0')
			break;
	}

	title[101]='\0';
	strcpy(book->title, title);

	while(1) {
	 	fprintf(stderr, "Give author: ");
		fflush(stderr);
		fgets(author, 99999, stdin);
		if ((pos=strchr(author, '\n')) != NULL)
			*pos = '\0';

		if (author[0] != '\0')
			break;
	}

	author[101]='\0';
	strcpy(book->author, author);

	while(1) {
 		fprintf(stderr, "Give publication year: ");
		fflush(stderr);
		scanf("%99s", year_str);
		year=atoi(year_str);
		if(year!=0) {
			getchar();
			break;
		}
	}
	book->year=year;

	book->left=NULL;
	book->right=NULL;

	if(book_tree==NULL) {
		book_tree=book;
		return;
	}

	struct Book *current = book_tree;
	while(1) {
		if(strcmp(book->title, current->title) > 0) {
			if(current->right==NULL) {
				current->right = book;
				return;
			}

			current = current->right;
		}
		else if(strcmp(book->title, current->title) < 0) {
			if(current->left==NULL) {
				current->left = book;
				return;
			}

			current = current->left;
		}
		else {
			if(current->year==-1) {
				strcpy(current->author, book->author);
				current->year = book->year;
				return;
			}
		}
	}
}

/* Given a binary tree, print its nodes in inorder(alphabetically) */
void printInorder(struct Book *node) 
{ 
    if(node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
  	if(node->year!=-1) {
	    /* then print the data of node */
	    printf("Title: %s\n", node->title);   
	    printf("Author: %s\n", node->author);   
	    printf("Year: %d\n", node->year);
	    printf("\n");
	}
  
    /* now recur on right child */
    printInorder(node->right); 
} 

/* menu_print_database():
 *
 * Print database of books to standard output in alphabetical order of title.
 */
void menu_print_database(void)
{
	printInorder(book_tree);
   /* fill in the code here in part 1, and add any extra functions you need */
}	    

