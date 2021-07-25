// hilos.h
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include "constantesYGlobales.h"

#ifndef hilos_h
#define hilos_h
#ifndef hilos_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

//Structs definitions
struct threadStruct
{
    //El thread id
    pthread_t tid;
    //Atributos thread
    pthread_attr_t attr;
    //La funcion que hará el thread.
    void *(*funcion)(void*);
    //Los argumentos del thread.
    void * args;
    
}; typedef struct threadStruct thread;
/* Function prototypes. */


/*
* La función hilosGenerarHilos se encarga de generar y mandar a ejecutar los threads.
*
*
* @params 
*   @param thread*  threads: la dirección de memoria del primer elemento del arreglo de hilos tipo thread.
*   @param int      numeroThreads: el número de threads que tiene el arreglo.
*
* @returns
*
*
*/
EXTERN void hilosGenerarHilos(thread* threads, int numeroThreads);
/*
* La función hilosEsperarHilos se encarga de esperar a que termine la ejecución de los hilos.
*
*
* @params 
*   @param thread*   threads: la dirección de memoria del primer elemento del arreglo de hilos tipo thread.
*   @param int      numeroThreads: el número de threads que tiene el arreglo.
*
* @returns
*
*
*/
EXTERN void hilosEsperarHilos(thread* threads, int numeroThreads);


#undef hilos_IMPORT
#undef EXTERN
#endif