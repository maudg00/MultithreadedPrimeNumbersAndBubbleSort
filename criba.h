// criba.h
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//
#include <stdio.h>
#include <stdlib.h>
#include "constantesYGlobales.h"

#ifndef criba_h
#define criba_h
#ifndef criba_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

//Structs definitions
struct structCrib
{
    //A partir de dónde buscar
    int inicio;
    //Hasta donde buscar.
    int fin;
    //El arreglo de números que nos ayuda a determinar si hay primos.
    int *nums;
    //El máximo absoluto de números a checar.
    int max;
    
}; typedef struct structCrib Criba;
/* Function prototypes. */


/*
* La función cribaBuscarPrimos de buscar primos entre un rango determinado
*
*
* @params 
*   @param void * estruct: la estructura que contiene el inicio y fin del rango.
*   
*
* @returns
*
*
*/
EXTERN void * cribaBuscarPrimos(void * estruct);
/*
* La función cribaTotalPrimos se encarga de decir el total de primos que hay.
*
*
* @params 
*   @param int * nums: el arreglo de primos.
*
*
* @returns
*
*
*/
EXTERN void cribaTotalPrimos(int *nums, int max);


#undef criba_IMPORT
#undef EXTERN
#endif