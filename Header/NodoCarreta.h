/*
 * NodoCarreta.h
 *
 *  Created on: 15/06/2016
 *      Author: marco
 */

#ifndef NODOCARRETA_H_
#define NODOCARRETA_H_

struct NodoCarreta {
	int no_carreta;
	struct NodoCarreta* siguiente;
};
typedef struct NodoCarreta* PilaCarreta;

struct NodoContenedor {
	PilaCarreta carreta;
	struct NodoContenedor* sig;
};
typedef struct NodoContenedor* Contenedor;

/*
 * PILA
 */
PilaCarreta iniciarCarreta(void);
PilaCarreta agregarCarreta(PilaCarreta carreta, int noCarreta);
PilaCarreta removerCarreta(PilaCarreta carreta);
void verCarreta(PilaCarreta carreta);

/*
 * CONTENEDOR
 */
Contenedor iniciarContenedor(void);
Contenedor agregarContenedor(Contenedor contenedor, PilaCarreta carreta);
void mostrarContenedor(Contenedor contenedor);

#endif /* NODOCARRETA_H_ */
