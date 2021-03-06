#ifndef _COLA_H_
#define _COLA_H_

typedef struct _nodo{
	char dato;
	int indice;
	struct _nodo *siguiente;
	struct _nodo *anterior;
}nodo;

typedef struct{
	nodo *primero;
	nodo *ultimo;
}head;

typedef head *Lista;

Lista creaLista();

int listaVacia(Lista l);

void enlista(Lista l, char valor, int numero);

int quitarNodo(Lista l,nodo *p);

#endif
