#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book
{
	char* name;
	char* author;
	int id;
};

typedef struct Book book;

void print_book_detail(book localbook)
{
	printf("Book Name: %s\n",localbook.name);
	printf("Book's Author: %s\n",localbook.author);
	printf("Book id: %d\n",localbook.id);
}

int main()
{
	book localbook;
	localbook.name = malloc(sizeof(char)*50);
	localbook.author = malloc(sizeof(char)*50);
	printf("Enter book name:\n");
	scanf("%s",localbook.name);
	printf("Enter book Author\n");
	scanf("%s",localbook.author);
	printf("Enter ID: \n");
	scanf("%d",&localbook.id);
	print_book_detail(localbook);
}
