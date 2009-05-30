#include <stdlib.h>
#include "pila.h"
#include "error.h"

Pila crea_pila(){
   pNodo nuevo;
	
   nuevo = (pNodo) malloc(sizeof(pnodo));
   nuevo->siguiente = NULL;
	
   return (nuevo);
}

int pila_vacia(Pila p){
	if(p->siguiente == NULL)
		return 1;
	else 
		return 0;
}

tipo pila_top(Pila p){
	if(!pila_vacia(p))
		return p->siguiente->valor;
	else
		error(EMPTY_STACK); /*hola*/
}

tipo pila_pop(Pila p){
	tipo resultado;
	pNodo aux;

	if(pila_vacia(p))
		error(EMPTY_STACK);

	aux = p->siguiente;
	resultado = aux->valor;
	p->siguiente = aux->siguiente;
	free(aux);
   
	return (resultado);
}

void pila_push(Pila p, tipo dato){
	pNodo nuevo;

	nuevo = (pNodo)malloc(sizeof(pnodo));
	nuevo->valor = dato;
	nuevo->siguiente = p->siguiente;
	p->siguiente = nuevo;
}

void borra_pila(Pila p){
	while(p->siguiente)
		pila_pop(p);
	free(p);
}
