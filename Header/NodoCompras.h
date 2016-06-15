/*
 * NodoCompras.h
 *
 *  Created on: 15/06/2016
 *      Author: marco
 */

#ifndef NODOCOMPRAS_H_
#define NODOCOMPRAS_H_

struct NodoCompras {
	struct NodoCliente* cliente;
	int noCarreta;
	struct NodoCompras* siguiente;
};
typedef struct NodoCompras* ListaCompras;

ListaCompras iniciarListaCompras(void);
ListaCompras agregarCompradores(ListaCompras lista_compras, struct NodoCliente* cliente, int noCarreta);
ListaCompras removerCompradores(ListaCompras lista_compras);
void mostrarListaCompras(ListaCompras lista_compras);

#endif /* NODOCOMPRAS_H_ */
