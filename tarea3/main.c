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
		letra = (char)65+i;
		enlista(nueva,letra,0);
	}
	/* Hasta este punto, el valor que identifica a los pueblos
	es el primero en la estructura del nodo, osea el campo dato,
	el campo indice no lo ocuparemos realmente asi que se 
	inicializa a cero.*/
	
	nueva->ultimo->siguiente = nueva->primero;
	
	return nueva;
}

Lista creaCargas(int total){
	Lista nueva;
	int i;

	nueva = creaLista();
	for(i=0;i<total;i++)
		enlista(nueva,'0',i);
	/*Hasta es punto, la cantidad de elementos que contiene cada carga
	ira en el segundo campo del nodo (dato), y un identificador para 
	luego saber que a que pila corresponde la carga sera el campo indice*/

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

/*Funciones para el trabajo con las cargas*/

/* int cabeCarga: verifica que una carga (pila) cabe en la 
   		  carga (pila) del robot que la pide, 1=true - 0=false*/
int cabeCarga(Pila robot, Pila carga){
	int cuentaRobot, cuentaCarga;
	
	cuentaRobot = cuenta_pila(robot);
	cuentaCarga = cuenta_pila(carga);
	
	if((10 - cuentaRobot) >= cuentaCarga)
		return 1;    		 
	else
		return 0;
}

/* int sacaCarga: saca la pila desde la carga y la coloca en la pila del 
		  robot, 1 si tuvo éxito , 0 si falla. */
int sacaCarga(Pila robot, Pila carga){
	if(pila_vacia(carga))
		return 0;
	if(cabeCarga(robot,carga)){
		intercambia_pila(carga,robot);
		borra_pila(carga);
		return 1;
	} else
		return 0;
}

/* Fin de las funciones para el trabajo con cargas */
			 
/* Comienzo del programa principal */
int main(){
	Lista cargas[2],circuito,robots;
	Pila *pilas[2],*pilaRobots;
	char estacion,aux;
	char cantCarga[10];
	int cantidadCarga,elementosPila,primeraPasada[20];
	int a,i,j;

	/* (1) Se crea el circuito , se lee el input y se guardan las cargas*/
	circuito = creaCircuito();
	
	for(a=0;a<2;a++){
		estacion = fgetc(stdin);

		fgetc(stdin); /*Leer salto de linea*/
		
		fgets(cantCarga,10,stdin);
		
		cantidadCarga = atoi(cantCarga);
		
		cargas[a] = creaLista();
		
		pilas[a] = creaPilas(cantidadCarga);
		
		for(i=0;i<cantidadCarga;i++){
			aux = fgetc(stdin);
			elementosPila = (int)aux-48;
			enlista(cargas[a],aux,i);
			/*Hasta es punto, la cantidad de elementos que contiene cada carga
			ira en el segundo campo del nodo (dato), y un identificador para 
			luego saber que a que pila corresponde la carga sera el campo indice*/

			/* @DEBUG INFORMATION */
			/* printf("el elemento vale %d\n",elementosPila); */
			/* @END DEBUG INFORMATION */
			
			for(j=0;j<elementosPila;j++){
				fgetc(stdin);
				pila_push(pilas[a][i],fgetc(stdin));			
			}
			fgetc(stdin);
		}
	
	}
	/* fin de (1) 
	   Se termino de leer el input */
	
	/*Creo los robots*/
	robots = creaRobots();
	pilaRobots = creaPilas(20);
	for(i=0;i<20;i++){
			primeraPasada[i] = 1;
		}
	
	/*while(!listaVacia(robots)){*/
	for(j=0;j<50;j++){
		/* La gracia es partir en un pueblo, que todos los robots pasen por 
		alli y luego mover el apuntador de la lista circular de pueblos y
		que se repita el proceso hasta que no queden robot*/
		
		/*Primero compruebo si el circuito esta en alguna de las estaciones,
		si es asi pues saco carga, sino pues entonces la dejo*/
		
		for(i=0;i<20;i++){/*Bucle principal para moverme por los robots*/
		
			if(circuito->primero->dato == 'A'){
				if(primeraPasada[i]){
					/*Me encargo de que solo saquen una carga, 
					ademas esa carga es la primera que 
					encuentran */
					if(cargas[0]->primero != NULL){
						sacaCarga(pilaRobots[i],pilas[0][cargas[0]->primero->indice]);
						primeraPasada[i] = 0;
					}
					
					quitarNodo(cargas[0],cargas[0]->primero);
						/*printf("EL nodo se elimino correctamente\n");	*/
				}	
			}
			
			if(circuito->primero->dato == 'K'){
				if(primeraPasada[i]){
					if(cargas[1]->primero != NULL){
						sacaCarga(pilaRobots[i],pilas[1][cargas[1]->primero->indice]);
						primeraPasada[i] = 0;
					}
					
					quitarNodo(cargas[1],cargas[1]->primero);
						/*printf("EL nodo se elimino correctamente\n");*/
				}	
			}
		
			if(!pila_vacia(pilaRobots[i])){/*Puedo y debo dejar carga*/
				if(pila_top(pilaRobots[i]) == circuito->primero->dato){
					/* Debo dejar la carga */
					printf("el robot %d Ha dejado una carga en el pueblo %c\n",i,pila_pop(pilaRobots[i]));
				}
			}
		
			
			if(circuito->primero->dato == 'T')
				primeraPasada[i] = 0; /*Me aseguro de que por lo menos todos hallan tenido su pasada*/
		
			/*if(!primeraPasada[i] && pila_vacia(pilaRobots[i])){
				borra_pila(pilaRobots[i]);
				quitarNodo(robots,);
			}*/
		}
		
		circuito->primero = circuito->primero->siguiente;
	}
	/*}*/

	
	/* Hasta ahora funciona */
	for(i=0;i<20;i++){
		while(!pila_vacia(pilaRobots[i]))
			printf("\nen el robot %d El elemento de la pila vale %c\n",i,pila_pop(pilaRobots[i]));
		printf("\n");
	}

	return (0);
}

