#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;
struct Node
{
	Node* prev;
	void* data;
	Node* next;
};
typedef Node List;

typedef struct Object Object;
struct Object
{
	char *name;
	float price;
};



List* CreateList();

Object CreateObject(char* itemName, float price);

void Insert(List* header, void* data);

Object PosFind(List* header, char* pos);

Object NameFind(List* header, char* name);

void RemoveByName(List* header, char* name);

void BubbleSort(List* header);

void ShowList(List* header);

int ListSize(List* header);

char* FileReader(List* inventaire, int* size);

int ItemCreator(List* inventaire, char* filecpy, int i);

Object RandomAdd(List* inventaire, int choice);
