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

Object CreateObject(int itemID, char* itemName, float price)
{
	Object NewObject = { itemID, itemName, price };

	return NewObject;
}


int Insert(List* header ,void* data, int itemID)
{
	Node* NewData = malloc(sizeof(Node));
	if (header->next == NULL)
	{
		header->next = NewData;
		header->prev = NewData;
		NewData->prev = header;
		NewData->next = NULL;

		NewData->data = data;

		int top = itemID +1;
		return top;
	}
	else
	{
		NewData->next = header->next;
		NewData->prev = header;
		header->next = NewData;

		NewData->data = data;

		int top = itemID + 1;
		return top;
	}
}

Node* PosFind(List* header, char* pos) // À compléter
{
	if (header->next == NULL)
	{
		printf("List vide\n");
		return;
	}

	Node* temp = header->next;
	Object* recherche = temp->data;

	while (temp->data)
	{

	}

}


Object NameFind(List* header, char* name) // Fonctionnel
{
	if (header->next == NULL)
	{
		printf("List vide\n");
		return;
	}

	Node* temp = header->next;
	Object* recherche = temp->data;
	

	while (temp != NULL && recherche->name != name)
	{
		temp = temp->next;
		if (temp != NULL)
		{
			recherche = temp->data;
		}
	}
	Object item = *recherche;

	return item;
}

void RemoveByName(List* header, char* name)
{

}

void BubbleSort(List* header)
{

}

/*
- trier
- avoir la quantité d'items dans la structure
*/