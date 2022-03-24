#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
	srand(time(0));
	int size;
	List* itemlist = CreateList();
	List* inventaire = CreateList();

	char* filecpy = FileReader(inventaire, &size);
	size += -6;

	for (int i = 144; i < 155; i++)
	{
		filecpy[i] = 0;
	}

	int filePos = 0;
	while (filePos < 713705)
	{
		filePos = ItemCreator(itemlist, filecpy, filePos);
	}
	Object fiole = CreateObject("Fiole", 15.0f);
	Insert(inventaire, &fiole);

	printf("Item List\n");
	ShowList(itemlist);


	int itemAmount = (rand() % 5) + 1;

	
	
	if (itemAmount == 1)
	{
		int choice = rand() % ListSize(itemlist);
		Object item1 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item1);
	}
	else if (itemAmount == 2)
	{
		int choice = rand() % ListSize(itemlist);
		Object item1 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item1);

		choice = rand() % ListSize(itemlist);
		Object item2 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item2);
	}
	else if (itemAmount == 3)
	{
		int choice = rand() % ListSize(itemlist);
		Object item1 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item1);

		choice = rand() % ListSize(itemlist);
		Object item2 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item2);

		choice = rand() % ListSize(itemlist);
		Object item3 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item3);
	}
	else if (itemAmount == 4)
	{
		int choice = rand() % ListSize(itemlist);
		Object item1 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item1);

		choice = rand() % ListSize(itemlist);
		Object item2 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item2);

		choice = rand() % ListSize(itemlist);
		Object item3 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item3);

		choice = rand() % ListSize(itemlist);
		Object item4 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item4);
	}
	else if (itemAmount == 5)
	{
		int choice = rand() % ListSize(itemlist);
		Object item1 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item1);

		choice = rand() % ListSize(itemlist);
		Object item2 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item2);

		choice = rand() % ListSize(itemlist);
		Object item3 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item3);

		choice = rand() % ListSize(itemlist);
		Object item4 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item4);

		choice = rand() % ListSize(itemlist);
		Object item5 = RandomAdd(itemlist, choice);
		Insert(inventaire, &item5);
	}

	printf("\nInventory\n");
	ShowList(inventaire);
	BubbleSort(inventaire);

	RemoveByName(inventaire, "Fiole");

	printf("\nInventory sorted without fiole\n");
	ShowList(inventaire);

	return 0;
}