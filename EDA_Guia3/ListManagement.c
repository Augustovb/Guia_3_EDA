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



int removeFirstElement (){

}
