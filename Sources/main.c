#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int ItemID = 0;
	List* List = CreateList();

	Object NewObject1 = CreateObject(ItemID, "Sword", 10);
	ItemID = Insert(List, &NewObject1, ItemID);

	Object NewObject2 = CreateObject(ItemID, "Axe", 20);
	ItemID = Insert(List, &NewObject2, ItemID);

	Object NewObject3 = CreateObject(ItemID, "Dagger", 2);
	ItemID = Insert(List, &NewObject3, ItemID);

	Object NewObject4 = CreateObject(ItemID, "Bat", 70);
	ItemID = Insert(List, &NewObject4, ItemID);

	Object NewObject5 = CreateObject(ItemID, "Scissors", 200);
	ItemID = Insert(List, &NewObject5, ItemID);

	Object FindObject = NameFind(List, "Bat");

	printf("%s\n", FindObject.name);

	BubbleSort(List);

	ShowList(List);

	RemoveByName(List, "Dagger");

	printf("\n");

	ShowList(List);

	return 0;
}