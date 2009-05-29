#include <stdio.h>
#include "lista.h"
#include "pila.h"
#include "cola.h"

Lista creaCircuito(){
	Lista nueva;
	int i;
	char letra;

	nueva = creaLista(); 
	for(i=0;i<20;i++){
		letra = (char)96+i;
		enlista(nueva,letra);
	}
	
	nueva->ultimo->siguiente = nueva->primero;
	
	return nueva;
}

Lista creaCargas(int total){
	Lista nueva;
	int i;
	char indice;

	nueva = creaLista();
	for(i=0;i<total;i++)
		enlista(nueva,'0',i);

	return nueva;
}

/* Pila *creaPilas: devuelve un array de pilas con total elementos*/
Pila *creaPilas(int total){  
	Pila *pilas;
	int i;

	pilas = (*Pila)malloc(sizeof(Pila)*total);
	for(i=0;i<total;i++)
		pilas[i] = crea_pila();

	return pilas;
}

Lista creaRobots(){
	Lista nueva;
	int i;
	char letra;

	nueva = creaLista();
	for(i=0;i<20;i++)
		enlista(nueva,'0',i);

	return nueva;
}

int main()
{
	printf("Hello world\n");
	return (0);
}