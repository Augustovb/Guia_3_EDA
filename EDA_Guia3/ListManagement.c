#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListManagement.h"


/*DEFS*/


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



int addElement (LIST l, void* elemento){

	void* newElement=NULL;
	nodo* newNode=NULL;
	
	newNode=(nodo*) malloc (sizeof (nodo));
	newElement=(void *) malloc(l->elementSize);		//yo quiero que estas cosas "vivan hasta qe las libere", por eso hago el malloc para que no mueran con la funcion

	if(newElement!=NULL && newNode!=NULL){
		if(l->firstNode==NULL){			//significa que estamos agregando al primer elemento recien
			l->firstNode=newNode;
			l->lastNode=newNode;
		} else {
			l->lastNode->next=newNode;			//al ultimo elemento hago que apunte al nuevo nodo
			l->lastNode=newNode;				//seteo como el ultimo eleento el nuevo nodo
		}
		newNode->next=NULL;						//el nuevo nodo apuntara a null
		newNode->elemento=memcpy(newElement,elemento,l->elementSize);		//copio la data y el puntero

		++(l->nodeCount);

		return 0;

	} else if(newElement==NULL && newNode==NULL){		//si fallaron los dos no hay problema
		return ERROR;

	} else if(newElement==NULL){
		free(newNode);									//si aloque uno solo, el otro lo libero
		return ERROR;

	} else if(newNode==NULL){
		free(newElement);
		return ERROR;
	}



}



int isListEmpty(LIST l){
	if(l->firstNode==NULL){		//significa ue esta vacia
		return EMPTY;
	} else {
		return NOT_EMPTY;
	}
}


//elimina el primer elemento

int removeFirstElement (LIST l){
	unsigned int estadoLocal=0;
	nodo* tempNodo;
	
	
	estadoLocal=isListEmpty(l);

	if(estadoLocal){
		if((l->nodeCount)>1){
		tempNodo=l->firstNode;		//en temp nodo almaceno el puntero al primer nodo
		l->firstNode=l->firstNode->next; //pongo omo nuevo primero, al segundo
		--(l->nodeCount);
		free(tempNodo->elemento);	//libero los espacios asignados
		free(tempNodo);
		return 0;
		} else {
			tempNodo=l->firstNode;		//como esta solo el primero tengo que eliminarlo y poner en null a l
			l->firstNode=NULL;
			l->lastNode=NULL;
			l->nodeCount=0;
			free(tempNodo->elemento);
			free(tempNodo);
			
			return 0;
		}


	}else {return ERROR;}	//la lista estaba vacia 

}




int removeLastElement (LIST l){
	unsigned int i=0;
	unsigned int estadoLocal=0;
	nodo* tempNodo;
	nodo* eraseNodo;

	//chequeo que la lista no este vacia

	estadoLocal=isListEmpty(l);		//si esta vacia directamente vuelvo porque no hay nada que devolver

	if(estadoLocal){
		if((l->nodeCount)>1){
			//debo "buscar el anteultimo", luego eliminarle el puntero al ultimo y ponerlo en NULL
			// y finalmente hacer que lastelement deje de apuntar alli sino al anteultimo y freear el ultimo
			// y bajar el nodecount

			tempNodo=l->firstNode;
			while (i<((l->nodeCount)-2)){
				tempNodo=tempNodo->next;

				++i;
			}		//tempNodo me apunta al anteultimo

			eraseNodo=l->lastNode;
			l->lastNode=tempNodo;
			tempNodo->next=NULL;
			free(eraseNodo->elemento);
			free(eraseNodo);
			--(l->nodeCount);


		} else {
			tempNodo=l->lastNode;		//como esta solo elultimo (que es lo mismo que este solo el 1) tengo que eliminarlo y poner en null a l
			l->firstNode=NULL;
			l->lastNode=NULL;
			l->nodeCount=0;
			free(tempNodo->elemento);
			free(tempNodo);
			return 0;

		}


	} else {return ERROR;} //la lista estaba vacia

}


void* getFirstElement (LIST l){
	unsigned int estado=0;

	estado=isListEmpty(l);

	if(estado){
		return (l->firstNode->elemento);
	} else {return NULL;}


}


void* getLastElement (LIST l){

	unsigned int estado=0;

	estado=isListEmpty(l);

	if(estado){
		return (l->lastNode->elemento);
	} else {return NULL;}


}




void * getThisElement(LIST l, unsigned int numeroDeElemento){
	unsigned int i=0;
	unsigned int estado=0;
	nodo* tempNodo=l->firstNode;
	estado=isListEmpty(l);

	if(estado){		//si no esta vacia...
		if(numeroDeElemento<=((l->nodeCount)-1)){	//si el numero elemento mandado es menor o igual n-1

			for(i=0; i<numeroDeElemento; ++i){
				tempNodo=tempNodo->next;
			}
			return (tempNodo->elemento);



		}else {return NULL;};		//valor mas alto que el posible
	} else {return NULL;}		//la lista estaba vacia
	

}



