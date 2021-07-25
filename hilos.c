
// hilos.c
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//
#include "hilos.h"
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
void  hilosGenerarHilos(thread* threads, int numeroThreads)
{
    for(int i=0; i<numeroThreads; i++)  
    {
        pthread_create(&threads[i].tid, &threads[i].attr, threads[i].funcion, threads[i].args);
    }
    
}
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
void hilosEsperarHilos(thread* threads, int numeroThreads)
{
    for(int i=0; i<numeroThreads; i++)
    {
        pthread_join(threads[i].tid, NULL);
    }
    
}