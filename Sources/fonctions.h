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
	int itemID; // Position Item - Peut servir de Top pour savoir cb d'objets il y a
	char* name;
	float price;
};





int Insert(List* header, void* data, int top);

List CreateList();