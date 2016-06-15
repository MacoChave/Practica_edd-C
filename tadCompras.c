/*
 * tadCompras.c
 *
 *  Created on: 15/06/2016
 *      Author: marco
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Header/NodoEspera.h"
#include "Header/NodoCarreta.h"
#include "Header/NodoCompras.h"

ListaCompras iniciarListaCompras(void) {
	return NULL;
}

ListaCompras agregarCompradores(ListaCompras lista_compras, struct NodoCliente* cliente, int noCarreta) {
	ListaCompras nuevo = malloc(sizeof(ListaCompras));
	ListaCompras actual = lista_compras;

	nuevo -> cliente = cliente;
	nuevo -> noCarreta = noCarreta;

	if (actual != NULL) {
		while (actual -> siguiente != lista_compras) {
			actual = actual -> siguiente;
		}
		nuevo -> siguiente = actual -> siguiente;
		actual -> siguiente = nuevo;
	} else {
		lista_compras = nuevo;
		nuevo -> siguiente = nuevo;
	}

	return lista_compras;
}

ListaCompras removerCompradores(ListaCompras lista_compras) {

}

void mostrarListaCompras(ListaCompras lista_compras) {
	ListaCompras aux = lista_compras;
	while (aux -> siguiente != lista_compras) {
		printf("====================");
		mostrarCliente(lista_compras -> cliente);
		printf("Carreta no: %d", aux -> noCarreta);
		printf("====================");
	}
}
