#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista creaLista(){
	Lista nueva;

	nueva = (Lista)malloc(sizeof(head));
	nueva->primero = NULL;
	nueva->ultimo = NULL;

	return nueva;
}

int listaVacia(Lista l){
	if(l->ultimo == NULL)
		return 1;
	else 
		return 0;
}

void enlista(Lista l, char valor, int numero){
	nodo *nueva;

	nueva = (nodo*)malloc(sizeof(nodo));
	if(listaVacia(l)){
		l->primero = nueva;
		nueva->anterior = NULL;
	} else {
	   nueva->anterior = l->ultimo;
	   l->ultimo->siguiente = nueva;
	  }

	nueva->siguiente = NULL;
	nueva->dato = valor;
	nueva->indice = numero;
	l->ultimo = nueva;   
}

int quitarNodo(Lista l,nodo *p){
	if(listaVacia(l))
		return 0;
	if(!p)
		return 0;
	if(p->siguiente)
		p->siguiente->anterior = p->anterior;
	else{
		
		l->ultimo = p->anterior;
		if(l->ultimo != NULL){
			
		l->ultimo->siguiente = NULL;}
		
		
	}
	if(p->anterior)
		p->anterior->siguiente = p->siguiente;
	else{
		l->primero = p->siguiente;
		if(l->primero != NULL){
		
		l->primero->anterior = NULL;}
		
	}
	free(p);
	return 1;	
}
	
	
