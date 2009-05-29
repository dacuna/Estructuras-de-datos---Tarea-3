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
	if(l->ultima = NULL)
		return 1;
	else 
		return 0;
}

void enlista(Lista l, char valor, int numero=0){
	nueva *nodo;

	nueva = (*nodo)malloc(sizeof(nodo));
	if(listaVacia(l)
		l->primero = nueva;
	else 
	   l>ultimo->siguiente = nuevo;

	nuevo->siguiente = NULL;
	nuevo->dato = valor;
	nuevo->indice = numero;
	l->ultimo = nuevo;   
}
	