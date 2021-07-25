// criba.c
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//
#include "criba.h"




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
void * cribaBuscarPrimos(void * estruct)
{
    sem_wait(&s);
    Criba* datos=(Criba*)estruct;
    int n = datos->fin; // número hasta el que se quiere buscar
    int i,prims[n],x=0,p;
    for(i=datos->inicio;i<=n;i++) {
        if(datos->nums[i] != 1 || i == 2) {
            prims[x] = i;
            
            for(p=2;(p*i)<=datos->max;p++) {
                datos->nums[(p*i)] = 1;
                
            }
            x++;
        }
    }
    
    sem_post(&s);
}
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
void cribaTotalPrimos(int *nums, int max)
{
    int contador=0;
    for(int i=2; i<max; i++)
    {
        if(nums[i]!=1)
        {
            printf("El numero %d es primo.\n", i);
            contador++;
        }
    }
    printf("Hay %d primos.\n", contador);
}

