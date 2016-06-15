/*
 * tadCarreta.c
 *
 *  Created on: 15/06/2016
 *      Author: marco
 */
#include <stdlib.h>
#include <stdio.h>
#include "Header/NodoCarreta.h"

/*
 * CONTENEDOR
 */
Contenedor iniciarContenedor(void) {
	return NULL;
}

Contenedor agregarContenedor(Contenedor contenedor, PilaCarreta carreta) {
	struct NodoContenedor* nuevo = malloc(sizeof(struct NodoContenedor));
	struct NodoContenedor* actual = contenedor;
	nuevo -> carreta = carreta;
	nuevo -> sig = NULL;

	if (contenedor != NULL) {
		while (actual -> sig != NULL) {
			actual = actual -> sig;
		}
		actual -> sig = nuevo;
	} else{
		contenedor = nuevo;
		printf("Espacio agregado\n");
	}

	return contenedor;
}
void mostrarContenedor(Contenedor contenedor) {
	struct NodoContenedor* aux;
	for (aux = contenedor; aux -> sig != NULL; aux = aux -> sig){
		printf("===============\n");
		verCarreta(aux -> carreta);
		printf("===============\n");
	}
	printf("===============\n");
	verCarreta(aux -> carreta);
	printf("===============\n");
}

/*
 * PILA
 */
PilaCarreta iniciarCarreta(void) {
	return NULL;
}

PilaCarreta agregarCarreta(PilaCarreta carreta, int noCarreta) {
	struct NodoCarreta* nuevo = malloc(sizeof(struct NodoCarreta));
	struct NodoCarreta* actual = carreta;

	nuevo -> no_carreta = noCarreta;
	nuevo -> siguiente = NULL;

	if (carreta != NULL) {
		while (actual -> siguiente != NULL) {
			actual = actual -> siguiente;
		}
		actual -> siguiente = nuevo;
	} else
		carreta = nuevo;
	printf("Carreta %d agregada\n", nuevo -> no_carreta);

	return carreta;
}

PilaCarreta removerCarreta(PilaCarreta carreta) {

}

void verCarreta(PilaCarreta carreta) {
	struct NodoCarreta* aux;

	for (aux = carreta; aux -> siguiente != NULL; aux = aux -> siguiente)
		printf("Carreta no: %d\n", aux -> no_carreta);
	printf("Carreta no: %d\n", aux -> no_carreta);
}
