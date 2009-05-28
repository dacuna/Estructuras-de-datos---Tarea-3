#ifndef _COLA_H_
#define _COLA_H_

typedef int cola_tipo[2];

typedef struct _cnodo{
	cola_tipo valor;
	struct _cnodo *siguiente;
}cnodo;

typedef cnodo *colaNodo;

typedef struct{
	struct colaNodo inicio;
	struct colaNodo final;
} cabecera;

typedef cabecera *Cola;

Cola crea_cola();

int cola_vacia(Cola c);

void cola_push(Cola c, tipo valor);

cola_tipo cola_top(Cola c);

cola_tipo cola_pop(Cola c);

void borra_cola(Cola c);

#endif