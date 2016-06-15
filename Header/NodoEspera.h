/*
 * NodoEspera.h
 *
 *  Created on: 13/06/2016
 *      Author: marco
 */

#ifndef NODOESPERA_H_
#define NODOESPERA_H_

struct NodoCliente {
	int id, edad;
	int jerarquia; //0:NORMAL, 1:3RA EDAD, 2:EMBARAZADA
	char genero; //f:femenino, m:masculino
	char embarazo; //s:si, n:no
};
typedef struct NodoCliente* Cliente;

struct NodoEspera {
	Cliente cliente;
	struct NodoEspera* siguiente;
};

typedef struct NodoEspera* ColaEspera;


Cliente iniciarCliente(void);
Cliente agregarCliente(Cliente cliente, int id, int edad, int jerarquia, char genero, char embarazo);
Cliente removerCliente(Cliente cliente);
void mostrarCliente(Cliente cliente);

ColaEspera iniciarCola(void);
ColaEspera addEsperaNormal(ColaEspera cola_espera, Cliente cliente);
ColaEspera addEsperaOro(ColaEspera cola_espera, Cliente cliente);
void mostrarEspera(ColaEspera cola_espera);

#endif /* NODOESPERA_H_ */
