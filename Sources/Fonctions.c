#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

List* CreateList()
{
	List* header = malloc(sizeof(List));
	header->prev = NULL;
	header->next = NULL;
	header->data = NULL;

	return header;
}


int Insert(List* header ,void* data, int top)
{
	Node* NewData = malloc(sizeof(Node));



}