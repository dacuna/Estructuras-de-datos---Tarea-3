#include <stdlib.h>
#include "cola.h"
#include "error.h"

Cola crea_cola(){
	Cola nuevo;

	nuevo = (Cola)malloc(sizeof(cabecera));
	nuevo->inicio = NULL;
	nuevo->final = NULL;

	return nuevo;
}

int cola_vacia(Cola c){
	if(c->inicio == NULL)
		return 1;
	else
		return 0;
}

void cola_push(Cola c, cola_tipo valor){
   colaNodo nuevo;
   nuevo = (colaNodo)malloc(sizeof(cnodo));
   nuevo->dato = valor;
   nuevo->siguiente = NULL;

   if (!cola_vacia(c))
      c->final->siguiente = nuevo;
   else
      c->inicio = nuevo;
	
   c->final = nuevo;
}

cola_tipo cola_top(Cola c){
	if(!cola_vacia(c))
		return c->inicio->valor;
	else
		error(EMPTY_QUEUE);
}

cola_tipo cola_pop(Cola c){
	cola_tipo resultado;
	colaNodo aux;

	if(cola_vacia(c))
		error(EMPTY_QUEUE);

	aux = c->inicio;
	resultado = aux->valor;
	c->inicio = aux->siguiente;
	free(aux);
   
	return (resultado);
}

void borra_cola(Cola c){
	while(c->inicio)
		cola_pop(c);
	free(c);
}
