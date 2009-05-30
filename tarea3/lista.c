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
	if(listaVacia(l))
		l->primero = nueva;
	else 
	   l->ultimo->siguiente = nueva;

	nueva->siguiente = NULL;
	nueva->dato = valor;
	nueva->indice = numero;
	l->ultimo = nueva;   
}
	
