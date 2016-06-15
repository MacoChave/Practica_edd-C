/*
 * principal.c
 *
 *  Created on: 13/06/2016
 *      Author: marco
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Header/NodoEspera.h"
#include "Header/NodoCarreta.h"
#include "Header/NodoCompras.h"


Cliente nuevoCliente(int cod, int edad, int jerarquia, char genero, char embarazo) {
	Cliente cliente = iniciarCliente();
	return agregarCliente(cliente, cod, edad, jerarquia, genero, embarazo);
}

Contenedor nuevaCarreta(Contenedor contenedor, int noCarretas) {
	int n = noCarretas / 4;
	int contador = 1;
	Contenedor contenedorActual = contenedor;
	PilaCarreta pila_carreta;

//	for (int i = 0; i < 3; i ++) {//RECORRIDO DE CASILLAS DEL CONTENEDOR
//		pila_carreta = iniciarCarreta();//INICIO UNA PILA PARA CADA CASILLA
//		pilaActual = pila_carreta;
//		for (int j = 0; j <= n; j ++) {//RECORRIDO PARA PILA DE UNA CASILLA
//			pilaActual = agregarCarreta(pilaActual, contador);
//			contenedorActual = agregarContenedor(contenedorActual, pilaActual);
//			printf("contenedor %d, carreta %d\n", i, contador);
//			contador ++;
//		}
//		contenedorActual = contenedorActual -> sig;
//	}
//	pila_carreta = iniciarCarreta();
//	pilaActual = pila_carreta;
//	for (int i = 0; i <  noCarretas - (contador - 1); i ++) {
//		pilaActual = agregarCarreta(pilaActual, contador);
//		contenedorActual = agregarContenedor(contenedorActual, pilaActual);
//		contador ++;
//	}
	return contenedor;
}

/*
 * PRIMER PASO
 */
void iniciarValores(int noClientes, int noCarretas, int noCajas) {
	printf("no clientes: %d, no carretas: %d, no cajas: %d\n", noClientes, noCarretas, noCajas);
}

/*
 * PROXIMOS PASOS
 */
void siguientePaso(int clientesNuevos, int clientesPagando) {
	int salir = 0;

		do {
			printf("========================================\n");
			printf("Práctica 1: Supermercado\n");
			printf("========================================\n");
			printf("Ingresa los datos para el siguiente paso\n");
			printf("No. de clientes nuevos.\n"); scanf("%d", &clientesNuevos);
			printf("No. de clientes que pasan a pagar.\n"); scanf("%d", &clientesPagando);
			printf("----------------------------------------\n");
			printf("1. Para salir el sistema.\n"); scanf("%d", &salir);
			printf("========================================\n");
			/*
			 * APLICAR CAMBIOS
			 */
			void esperaAcompras(ClientesNuevos); //AGREGAR NUEVOS CLIENTES, REMOVER DE ESPERA Y CARRETA PARA COMPRAS
			//void comprasApagos(clientesPagando); //REMOVER DE COMPRAS A PAGOS, LLENAR LAS DOS COLAS SEGÚN JERARQUIA
			//void pagosAcaja();//REMOVER DE PAGOS A CAJA, REMOVER CAJA

			siguientePaso(clientesNuevos, clientesPagando);
		} while (salir != 1);
}

int main(void) {
	/*
	int noClientes, noCarretas, noCajas;

	printf("===============================\n");
	printf("Práctica 1: Supermercado\n");
	printf("===============================\n");
	printf("Ingresa los datos para comenzar\n");
	printf("No. de clientes a ingresar.\n"); scanf("%d", &noClientes);
	printf("No. de carretas iniciales.\n"); scanf("%d", &noCarretas);
	printf("No. de cajas disponibles\n"); scanf("%d", &noCajas);
	printf("===============================\n");

	iniciarValores(noClientes, noCarretas, noCajas);
	 */
	/*
	 * AGREGAR Y MOSTRAR CLIENTES ORO Y NORMAL
	 */
	ColaEspera cola_espera;
	cola_espera = iniciarCola();

	cola_espera = addEsperaNormal(cola_espera, nuevoCliente(1, 30, 0, 'f', 'n'));
	cola_espera = addEsperaOro(cola_espera, nuevoCliente(2, 60, 2, 'm', 'n'));
	cola_espera = addEsperaNormal(cola_espera, nuevoCliente(3, 20, 0, 'm', 'n'));
	cola_espera = addEsperaNormal(cola_espera, nuevoCliente(4, 50, 0, 'f', 'n'));
	cola_espera = addEsperaOro(cola_espera, nuevoCliente(5, 70, 2, 'f', 'n'));
	cola_espera = addEsperaNormal(cola_espera, nuevoCliente(6, 40, 0, 'm', 'n'));
	cola_espera = addEsperaOro(cola_espera, nuevoCliente(7, 20, 1, 'f', 's'));

	mostrarEspera(cola_espera);

	/*
	 * AGREGAR Y MOSTRAR CARRETAS DENTRO DE SUS CONTENEDORES
	 */
	Contenedor contenedor;
	contenedor = iniciarContenedor();

	PilaCarreta carreta;
	carreta = iniciarCarreta();
	carreta = agregarCarreta(carreta, 1);
	carreta = agregarCarreta(carreta, 2);
	carreta = agregarCarreta(carreta, 3);
	contenedor = agregarContenedor(contenedor, carreta);

	carreta = iniciarCarreta();
	carreta = agregarCarreta(carreta, 4);
	carreta = agregarCarreta(carreta, 5);
	carreta = agregarCarreta(carreta, 6);
	contenedor = agregarContenedor(contenedor, carreta);

	carreta = iniciarCarreta();
	carreta = agregarCarreta(carreta, 7);
	carreta = agregarCarreta(carreta, 8);
	carreta = agregarCarreta(carreta, 9);
	contenedor = agregarContenedor(contenedor, carreta);

	mostrarContenedor(contenedor);

	/*
	 * AGREGAR Y MOSTRAR CLIENTES Y CARRETAS EN LISTA DE COMPRAS
	 */
	ListaCompras lista_compras;
	lista_compras = iniciarListaCompras();

//	lista_compras = agregarCompradores(lista_compras, obtenerCliente(), );

	return 0;
}
