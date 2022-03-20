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
	int itemID;
	char* name;
	float price;
};



List* CreateList();

Object CreateObject(int itemID, char* itemName, float price);

int Insert(List* header, void* data, int itemID);

Node* PosFind(List* header, char* pos);

Object NameFind(List* header, char* name);

void RemoveByName(List* header, char* name);

void BubbleSort(List* header);