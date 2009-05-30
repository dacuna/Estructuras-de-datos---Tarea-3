#include <stdio.h>
#include <stdlib.h>
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
		enlista(nueva,letra,0);
	}
	
	nueva->ultimo->siguiente = nueva->primero;
	
	return nueva;
}

Lista creaCargas(int total){
	Lista nueva;
	int i;

	nueva = creaLista();
	for(i=0;i<total;i++)
		enlista(nueva,'0',i);

	return nueva;
}

/* Pila *creaPilas: devuelve un array de pilas con total elementos*/
Pila *creaPilas(int total){  
	Pila *pilas;
	int i;

	pilas = (Pila*)malloc(sizeof(Pila)*total);
	for(i=0;i<total;i++)
		pilas[i] = crea_pila();

	return pilas;
}

Lista creaRobots(){
	Lista nueva;
	int i;

	nueva = creaLista();
	for(i=0;i<20;i++)
		enlista(nueva,'0',i);

	return nueva;
}

int main(){
	Lista *cargas,circuito,robots;
	Pila **pilas,*pilaRobots;
	char estacion;
	char cantCarga[10];
	int cantidadCarga,elementosPila;
	int a,i,j;

	/* (1) Se crea el circuito , se lee el input y se guardan las cargas*/
	circuito = creaCircuito();
	
	/* cargas[0] para A ; cargas[1] para K*/
	cargas = (Lista*)malloc(sizeof(Lista)*2);  
	/* pilas[0] para A ; pilas[1] para K*/
	pilas = (Pila**)malloc(sizeof(Pila*)*2);
	
	for(a=0;a<2;a++){
	estacion = fgetc(stdin);

	fgetc(stdin); /*Leer salto de linea*/
	
	fgets(cantCarga,10,stdin);
	
	cantidadCarga = atoi(cantCarga);
	
	cargas[a] = creaCargas(cantidadCarga);
	
	pilas[a] = creaPilas(cantidadCarga);
	
	for(i=0;i<cantidadCarga;i++){
		elementosPila = (int)fgetc(stdin)-48;
		printf("el elemento vale %d\n",elementosPila);
		for(j=0;j<elementosPila;j++){
			fgetc(stdin);
			pila_push(pilas[a][i],fgetc(stdin));			
		}
		fgetc(stdin);
	}
	
	for(i=0;i<cantidadCarga;i++){
		while(!pila_vacia(pilas[a][i]))
			printf("El elemento de la pila %d es %c\n",i,pila_pop(pilas[a][i]));
	}
	
	
	
	printf("estacion es: %c\nla carga es %d\n",estacion,cantidadCarga);
	}
	/* fin de (1) */
	
	/*Creo los robots*/
	robots = creaRobots();
	pilaRobots = creaPilas(20);

	return (0);
}
