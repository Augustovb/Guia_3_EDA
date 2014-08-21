#include <stdio.h>
#include <stdlib.h>


#include "ListManagement.h"


/*DEFS*/



/*		La siguiente funcion, crea una lista vacia.
*	El tamaño en bytes de los elementos en los nodos debe ser pasado como parametro.
*	DEVUELVE: sin error: La lista (header*)
*				
*			  hubo error: puntero a NULL
*/

LIST createList(unsigned int size);	//devuelve NULL cuando se produjo un error recordar que se aloca memoria dinamica

/*ENDDEFS*/


LIST createList(unsigned int size){
	LIST newList=NULL;

	newList=(header*)malloc(sizeof(header));

	if(newList!=NULL){
		newList->firstNode=NULL;
		newList->lastNode=NULL;		//como es una lista vacia, el primer y ultimo elemento son null

		newList->elementSize=size;	//lo que me paso el usuario

		newList->nodeCount=0;		//comienzo en 0
	}
	return newList;		//si era NULL, lo devuelvo sin cargo de conciencia. El que debe chequear el error es el usuario de la libreria.

}