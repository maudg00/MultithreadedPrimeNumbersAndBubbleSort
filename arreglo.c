// arreglo.c
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//
#include "arreglo.h"

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
void arregloLlenarArreglo(int *arr, int tam)
{
    for(int i=0; i<tam; i++)
    {
            arr[i]=rand()%tam;
    }
}
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
void arregloImprimirArreglo(int *arr, int tam)
{
    int i;
    for(i=0; i<tam; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
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
void * arregloBubbleSort(void *Arreglo)
{
    int i, j, temp;
    Array *arreglo;
    arreglo=(Array*)Arreglo;
    
    sem_wait(&s);
    for(i=0; i<arreglo->tam; i++){
        for(j=0; j<((arreglo->tam)-1); j++){
            if(arreglo->arr[j]>arreglo->arr[j+1]){
                temp=arreglo->arr[j];
                arreglo->arr[j]=arreglo->arr[j+1];
                arreglo->arr[j+1]=temp;
            }
        }
    }
    sem_post(&s);;
}
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
int arregloMezcla(int arr[], int ini, int med, int fin)
{
    int *aux=malloc(sizeof(int)*(fin-ini+1));
    int finIni = med-1;
    int s=ini;
    int tam=fin-ini+1;
    int t=0;
    while((ini<=finIni)&&(med<=fin)){
        if(arr[ini]<=arr[med]){
            aux[t]=arr[ini];
            ini++;
            t++;
        }
        else{
            aux[t]=arr[med];
            med++;
            t++;
        }
    }
    while(ini<=finIni){
        aux[t++]=arr[ini++];
    }
    while(med<=fin){
        aux[t++]=arr[med++];
    }
    for(int i=0; i<tam; i++){
        arr[s+i]=aux[i];
    }
}