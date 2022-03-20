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
		header->next->prev = NewData;
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
	if (header->next == NULL)
	{
		printf("List vide\n");
		return;
	}
	
	Node* temp = header->next;
	Object* objTemp = temp->data;

	while (temp != NULL)
	{
		if (objTemp->name == name) // Condition de sortie
		{
			if (temp == header->prev) // Si temp est le dernier elem de la liste
			{
				temp->prev->next = NULL;
				header->prev = temp->prev;
				temp->data = NULL;
			}
			else
			{
				Node* prev = temp->prev;
				prev->next = temp->next;

				Object* Halla = temp->prev->data;

				Node* next = temp->next;
				next->prev = temp->prev;

				temp->data = NULL;
				temp->prev = NULL;
				temp->next = NULL;
			}
			free(temp);
			return;
		}

		temp = temp->next;
		objTemp = temp->data;
	}
}

void BubbleSort(List* header)
{
	int switched = 0;
	int count = 0;

	Node* temp = header->next;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	// Si le count est Nul OU a un seul element
	if (count == 0)
	{
		printf("La liste est vide\n");
		return;
	}
	else if (count == 1)
	{
		printf("La liste n'a qu'un seul elem\n");
		return;
	}

	temp = header->next; // Reset de temp au premier elem

	for (int i = 0; i < count - 1; i++)
	{
		Object* firstdata = temp->data;
		Object* seconddata = temp->next->data;


		if (firstdata->price > seconddata->price)
		{
			Object* objtemp = firstdata;
			firstdata = seconddata;
			seconddata = objtemp;
			switched = 1;

			temp->data = firstdata;
			temp->next->data = seconddata;
		}

		if (switched == 1)
		{
			switched = 0;
			temp = header->next;
			i = -1;
		}
		else
		{
			temp = temp->next;
		}
	}



}

void ShowList(List* header)
{
	Node* temp = header->next;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}

	Object* objP = temp->data;

	
	while (temp != NULL)
	{
		if (temp != NULL)
		{
			printf("Nom item : %s   Prix item : %f\n", objP->name, objP->price);
		}
		
		temp = temp->next;
		if (temp != NULL)
		{
			objP = temp->data;
		}
	}
}

int ListSize(List* header)
{

}
