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

Object CreateObject(char* itemName, float price)
{
	Object NewObject = {itemName, price };

	return NewObject;
}

void Insert(List* header ,void* data)
{
	Node* NewData = malloc(sizeof(Node));
	
	if (header->next == NULL)
	{
		header->next = NewData;
		header->prev = NewData;
		NewData->prev = header;
		NewData->next = NULL;

		NewData->data = data;
		Object* a = NewData->data;

		return;
	}
	else
	{
		NewData->next = header->next;
		NewData->prev = header;
		header->next->prev = NewData;
		header->next = NewData;


		NewData->data = data;

		
		return;
	}
}

Object PosFind(List* header, int pos) // pos 1 = data 1
{
	if (header->next == NULL)
	{
		printf("List vide\n");
		return;
	}

	Node* temp = header->next;
	Object* recherche = temp->data;

	for (int i = 0; i < pos - 1; i++)
	{
		if (temp == NULL)
		{
			break;
		}
		temp = temp->next;
		recherche = temp->data;
	}


	Object found = *recherche;
	return found;
}

Object NameFind(List* header, char* name) // Fonctionnel
{
	// Si header vide
	if (header->next == NULL)
	{
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
				Node* prev = temp->prev;
				prev->next = NULL;

				header->prev = temp->prev;

				temp->data = NULL;
				temp->prev = NULL;
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
	if (header->next == NULL)
	{
		return 0;
	}

	Node* temp = header->next;
	int size = 1;
	while (temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

char* FileReader(List* inventaire, int *size)
{
	FILE* fichier;
	fichier = fopen("data.csv", "r"); // Regarder le path
	
	char* contenuFichier;

	// Get file length
	fseek(fichier, 0, SEEK_END);
	int fileSize = ftell(fichier);
	fseek(fichier, 0, SEEK_SET);
	
	contenuFichier = malloc(fileSize);

	fread(contenuFichier, fileSize, 1, fichier);

	fclose(fichier);

	*size = fileSize;
	return contenuFichier;

}

int ItemCreator(List* inventaire, char* filecpy, int filePos)
{
	Object* NewObject = malloc(sizeof(NewObject));
	NewObject->name = malloc(sizeof(char) * 35);
	for (int i = 0; i < 35; i++)
	{
		NewObject->name[i] = 0;
	}

	char tempNumb[5] = { 0 };

	int counter = 0;
	int i = filePos;
	int tempW = 0;

	while (filecpy[i] != ',') // Skip Name
	{
		i++;
	}
	counter++;
	i += 2;

	while (filecpy[i] != ',') // Write what name is
	{
		NewObject->name[tempW] = filecpy[i];
		tempW++;
		i++;
	}

	counter++;
	i += 2;
	tempW = 0;

	while (filecpy[i] != ',') // Skip value
	{
		i++;
	}

	counter++;
	i += 2;

	while (filecpy[i] != '\n' && filecpy[i] != ' ' && filecpy[i] != 0) // Write what number is
	{
		tempNumb[tempW] = filecpy[i];
		tempW++;
		i++;
	}

	NewObject->price = atoi(tempNumb);
	Insert(inventaire, NewObject);

	// Si on est a la fin du fichier
	if (filecpy[i + 1] == 0 && filecpy[i + 2] == 0)
	{
		
		return 713705; 
	}
	else
	{
		return i;
	}
}

Object RandomAdd(List* inventaire, int choice)
{
	// Si l'inventaire est vide
	if (inventaire->next == NULL)
	{
		return;
	}

	Node* temp = inventaire->next;


	for (int i = 0; i < choice; i++)
	{
		temp = temp->next;
	}


	if (temp != NULL)
	{
		Object* item = temp->data;
		Object retour = *item;
		return retour;
	}
	
}