// arreglo.h
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//
#include <stdio.h>
#include <stdlib.h>
#include "constantesYGlobales.h"

#ifndef arreglo_h
#define arreglo_h
#ifndef arreglo_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

//Structs definitions
struct struct1
{
    //La dirección de memoria al primer elemento del arreglo.
    int *arr;
    //El tamaño del arreglo.
    int tam;
    
}; typedef struct struct1 Array;
/* Function prototypes. */


/*
* La función arregloLlenarArreglo  se encarga de llenar un arreglo aleatoriamente
*
*
* @params 
*   @param int * arr: la direccion de memoria del primer elemento del arreglo.
*   @param int tam: el tamaño total del arreglo.
*
* @returns
*
*
*/
EXTERN void arregloLlenarArreglo(int *arr, int tam);
/*
* La función arregloImprimirArreglo  se encarga de imprimir un arreglo.
*
*
* @params 
*   @param int * arr: la direccion de memoria del primer elemento del arreglo.
*   @param int tam: el tamaño total del arreglo.
*
* @returns
*
*
*/
EXTERN void arregloImprimirArreglo(int *arr, int tam);
/*
* La función arregloBubbleSort  se encarga de ordenar un arreglo con el algoritmo de bubble sort.
*
*
* @params 
*   @param void * arr: la direccion de memoria del primer elemento del arreglo.
*   
* @returns
*
*
*/
EXTERN void * arregloBubbleSort(void *Arreglo);
/*
* La función arregloMezcla  se encarga de validar que un numero entero sea positivo mayor a 0.
*
*
* @params 
*   @param int  arr[]: el arreglo.
*   @param int  ini: el inicio del arreglo.
*   @param int  med: la mitad del arreglo.
*   @param int  fin: el final del arreglo.
* 
*
* @return 
*
*
*/
EXTERN int arregloMezcla(int arr[], int ini, int med, int fin);

#undef arreglo_IMPORT
#undef EXTERN
#endif