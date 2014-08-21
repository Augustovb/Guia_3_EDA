#include <stdio.h>
#include <stdlib.h>

#ifndef ListManagement__H
#define ListManagement__H

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





#endif