#ifndef _COLA_H_
#define _COLA_H_

typedef struct _nodo{
	char dato;
	char indice;
	struct _nodo *siguiente;
}nodo;

typedef struct{
	nodo *primero;
	nodo *ultimo;
}head;

typedef head *lista;

Lista creaLista();

int listaVacia(Lista l);

void enlista(Lista l, char valor, int numero);

#endif