#include <stdint.h>
#include <assert.h>

#define HEAP_SIZE 1024 * 1024
extern uint8_t* heap;
extern size_t heap_top;

static void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

/*
* D�clarer une structure de donn�e appeler Stack qui contient une propri�t�, max_size de type size_t,top de type size_t et un tableau de type void**.
*/
typedef struct Stack Stack;
struct Stack
{
	void** data;//32
	size_t max_size;//64
	size_t top;//64
};


typedef struct person_t {
	char name[256];
	size_t age;
} Person;

/*
* Cr�er la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size);

/*
* Ajouter l'�l�ment sur la stack. Pr�vener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData);

/*
* Enlever l'�l�ment de la stack et retourner l'information. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
void* pop(Stack* s);

/*
* Retourner l'�l�ment du top sans l'enlever de la stack. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
void* peek(Stack* s);

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilis� la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s);

/*
* Tri�e la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propri�t� data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s);


void bubbleSort(int elements[], int n);
