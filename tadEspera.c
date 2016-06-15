/*
 * tadEspera.c
 *
 *  Created on: 14/06/2016
 *      Author: marco
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Header/NodoEspera.h"

/*
 * ESPERA
 */
ColaEspera iniciarCola(void){
	return NULL;
}

ColaEspera addEsperaNormal(ColaEspera cola_espera, Cliente cliente) {
	struct NodoEspera* nuevo = malloc(sizeof(struct NodoEspera));
	struct NodoEspera* aux = cola_espera;

	nuevo -> cliente = cliente;

	if (aux != NULL) {
		while (aux -> siguiente != NULL) {
			aux = aux -> siguiente;
		}
		aux -> siguiente = nuevo;
	} else
		cola_espera = nuevo;
	nuevo -> siguiente = NULL;
	printf("Cliente llegó\n");

	return cola_espera;
}

ColaEspera addEsperaOro(ColaEspera cola_espera, Cliente cliente) {
	struct NodoEspera* nuevo = malloc(sizeof(struct NodoEspera));
	struct NodoEspera* actual = cola_espera;
	struct NodoEspera* anterior = NULL;

	nuevo -> cliente = cliente;

	if (actual != NULL) {
		while (actual -> cliente -> jerarquia >= nuevo -> cliente -> jerarquia) {
			anterior = actual;
			actual = actual -> siguiente;
		}
		if (anterior != NULL) {
			anterior -> siguiente = nuevo;
			nuevo -> siguiente = actual;
		} else {
			nuevo -> siguiente = cola_espera;
			cola_espera = nuevo;
		}
	} else {
		cola_espera = nuevo;
		nuevo -> siguiente = NULL;
	}
	printf("Cliente oro llegó\n");

	return cola_espera;
}

void mostrarEspera(ColaEspera cola_espera) {
	struct NodoEspera* aux;

	for (aux = cola_espera; aux -> siguiente  != NULL; aux = aux -> siguiente)
		mostrarCliente(aux -> cliente);
	mostrarCliente(aux -> cliente);
}

/*
 * CLIENTE
 */
Cliente iniciarCliente(void) {
	return NULL;
}

Cliente agregarCliente(Cliente cliente, int id, int edad, int jerarquia, char genero, char embarazo) {
	struct NodoCliente* nuevo = malloc(sizeof(struct NodoCliente));
	nuevo -> id = id;
	nuevo -> edad = edad;
	nuevo -> jerarquia = jerarquia;
	nuevo -> genero = genero;
	nuevo -> embarazo = embarazo;

	return nuevo;
}
/*
Cliente removerCliente(Cliente cliente) {

}
*/
void mostrarCliente(Cliente cliente) {
	printf("Cliente : %d, edad: %d, genero: %c, embarazo: %c\n", cliente -> id, cliente -> edad, cliente -> genero, cliente -> embarazo);
}
