#include <stdio.h>
#include <stdlib.h>

#ifndef ListManagement__H
#define ListManagement__H

/***************
* CONSTANTES   *
***************/

#define ERROR -1

#define EMPTY			0
#define NOT_EMPTY		1



/***************
* Definiciones *
***************/
/*El tipo de dato nodo, representa una parte de la lista.
* Seria un eslabon de la lista.
* Este nodo sirve para una lista simplemente enlazada.
*/


typedef struct prov_nodo {
	struct prov_nodo * next;	//proximo nodo al que apunto

	void * elemento;			//data del nodo
} nodo;




/*	Tipo de dato header.
*	Para representar una lista, tenemos una parte que es la que la describe.
*	Particularmente se obtendra informacion de: donde comienza la lista, donde
*	termina, cuantos elementos hay en ella y el tamaño de cada uno de los datos a almacenar
*	alli (ints, chars, PEPES, nodos, lo que sea, es decir, tamaño de cualquier tipo de dato)
*/

typedef struct {

	nodo* firstNode;		
	nodo* lastNode;

	unsigned int elementSize;

	unsigned int nodeCount;

} header;

/* El tipo de dato LIST sera simplemente un puntero a header
*  donde esta la informacion sobre la lista en cuestion.
*/

typedef header* LIST;


/***************
*	Funciones  *
***************/



/*		La siguiente funcion, crea una lista vacia.
*	El tamaño en bytes de los elementos en los nodos debe ser pasado como parametro.
*	DEVUELVE: sin error: La lista (header*)
*				
*			  hubo error: puntero a NULL
*/

LIST createList(unsigned int size);	//devuelve NULL cuando se produjo un error recordar que se aloca memoria dinamica


/* Funcion Add element:
*	Agrega un nuevo nodo al final de la lista y le pone el valor al elemeno (*elemento)
*	El usuario eligira como desreferenciar este puntero segun la data que haya dado.
*
*	Devuelve 0 si esta todo ok y -1 si hubo un ERROR
*/
int addElement (LIST l, void* elemento);



/*Funcion isListEmpty
*
*	Esta funcion simplemente chequea si la lista esta vacia o no (si no hay elementos)
*	Devuelve 0 si esta EMPTY
*	Devuelve 1 si tiene algo (NOT_EMPTY)
*/
int isListEmpty(LIST l);


/*	Funciones get firrst y last element
*	devuelve el puntero a void donde se encuentra el valor del primer/ultimo elemento
*
*	devuelven NULL si la lista esta vacia
*
*/

void* getFirstElement (LIST l);
void* getLastElement(LIST l);




/*		Mas abarcativa que get first/last element
*
*		devuelve el elemento que le pidas de la lista, devuelta NULL si la lista esta vacia // se paso un numero mas grande que (l->nodeCount-1)
*
*
*		Se piden numeros de 0 a n siendo n=(l->nodeCount)-1.
*
*		Si tengo 10 nodos, el elemento 0 es el primer nodo
*
*		
*/
void * getThisElement(LIST l, unsigned int numeroDeElemento);


/*		Estas funciones se encargan de eliminar el 1er nodo o el ultimo nodo.
*
*		devuelven siempre 0 a menos que la lista este vacia, alli devuelve error
*/

int removeLastElement (LIST l);
int removeFirstElement (LIST l);


#endif