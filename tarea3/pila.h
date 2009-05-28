#ifndef _PILA_H_
#define _PILA_H_

typedef tipo char;

typedef struct _nodo{
	tipo valor;
	struct _nodo *siguiente;
} nodo;

typedef nodo *pNodo;
typedef nodo *Pila;

Pila *crea_pila();

int pila_vacia(Pila p);

tipo pila_top(Pila p);

tipo pila_pop(Pila p);

void pila_push(Pila p, tipo dato);

void borra_pila(Pila p);
	
#endif