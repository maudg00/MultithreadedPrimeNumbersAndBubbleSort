#include "vista.h"
#include "hilos.h"
#include "arreglo.h"
#include "criba.h"
void modoArreglos();
void modoCriba();
int main()
{
    char opcion;
    sem_init(&s,0,6);
    vistaIntroduccion();
    vistaEnter();
    do
    {
        opcion=vistaMenu();
        switch(opcion)
        {
            case '1':
            system("clear");
            modoArreglos();
            break;
            case '2':
            system("clear");
            modoCriba();
            break;
            case '3':
            printf("Gracias por usar el programa.\n");
            break;
            default:
            printf("ERROR: opcion invalida.\n");
            break;
        }
        vistaEnter();
        //system("clear");
    } while (opcion!='3');
    sem_destroy(&s);
}
void modoArreglos()
{
    //Arreglo de hilos sin alocar.
    thread* hilos;
    pthread_t tids[2];
    //Mitades de arreglos a ordenar
    Array *arr1;
    Array *arr2;
    //Atributos threads
    pthread_attr_t attr;
    //Apuntador a funcion bubblesort
    void *(*funcion)(void*);
    //Tamaño arreglo y arreglo
    int tam;
    int *arr;
    //Variables para medir tiempo
    struct timeval start, end;
    double clocktime;
    //Pido datos
    printf("Tamanio de arreglo: \n\t");
    tam=vistaPedirNumPositivo(MAX, "El tamaño esta por encima del maximo.");
    //Allocate arreglos
    arr=malloc(tam*sizeof(int));
    arr1=malloc(sizeof(Array));
    arr2=malloc(sizeof(Array));
    hilos=malloc(sizeof(thread)*2);
    
    //Lleno arreglo
    arregloLlenarArreglo(arr, tam);
    printf("Arreglo Original: \n");
    arregloImprimirArreglo(arr, tam);
    //Asigno valor a function pointer
    funcion=arregloBubbleSort;
    
    //Lleno estructuras
    arr1->arr=arr;
    arr1->tam=tam/2;
    arr2->arr=&arr[tam/2];
        //Que el arreglo 2 tenga el tamaño correcto si es par o impar.
    if(tam%2!=0)
    {
        arr2->tam=(tam/2)+1;
    }
    else
    {
        arr2->tam=(tam/2);
    }
    
    //Inicializo hilos
    pthread_attr_init(&attr);
        
    hilos[0].tid=tids[0];
    hilos[0].attr=attr;
    hilos[0].funcion=funcion;
    hilos[0].args=(void*)arr1;

    hilos[1].tid=tids[1];
    hilos[1].attr=attr;
    hilos[1].funcion=funcion;
    hilos[1].args=(void*)arr2;
   
    //Inicio ejecución
    gettimeofday(&start, NULL);
    
    hilosGenerarHilos(hilos, 2);
    hilosEsperarHilos(hilos, 2);
    
    //Mezclo resultados de hilos
    arregloMezcla(arr,0,tam/2,tam-1);
    gettimeofday(&end, NULL);
    clocktime= end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6;
    //Imprimo resultados
    printf("Primer hilo ordeno: \n");
    arregloImprimirArreglo(arr1->arr, arr1->tam);
    printf("Segundo hilo ordeno: \n");
    arregloImprimirArreglo(arr2->arr, arr2->tam);
    printf("Arreglo final ordenado: \n");
    arregloImprimirArreglo(arr, tam);
    printf("Tardo %.8f segundos.\n", clocktime);
    //Libero
    free(hilos);
    free(arr1);
    free(arr2);
    free(arr);
}
void modoCriba()
{
    //Arreglo de hilos sin alocar.
    thread* hilos;
    pthread_t *tids;
    pthread_attr_t attr;
    int *nums;
    int numCPUs=get_nprocs();
    //Variables para medir tiempo
    struct timeval start, end;
    double clocktime;
    //Apuntador a funcion criba
    void *(*funcion)(void*);
    //Estructura Criba
    Criba **estructCriba;
    int numMax, numHilos;
    //Pido datos
    printf("Hay %d hilos disponibles.\n\n", numCPUs);
    printf("Numero maximo: \n\t");
    numMax=vistaPedirNumPositivo(MAXC, "El tamaño esta por encima del maximo");
    printf("Hay %d hilos disponibles.\n\n", numCPUs);
    printf("Numero de hilos: \n\t");
    numHilos=vistaPedirNumPositivo(numCPUs, "Este equipo no cuenta con tantos hilos");
    //Allocate memoria
    estructCriba=malloc(sizeof(Criba*)*numHilos);
    for(int i=0; i<numHilos; i++)
    {
        estructCriba[i]=malloc(sizeof(Criba));
    }
    hilos=malloc(sizeof(thread)*numHilos);
    tids=malloc(sizeof(pthread_t)*numHilos);
    nums=malloc(sizeof(int)*(numMax+1));
    for(int i=0; i<numMax; i++)
        nums[i]=0;
    //Init func pointer
    funcion=cribaBuscarPrimos;
    //Inicializar hilos
    pthread_attr_init(&attr);
    for(int i=0; i<numHilos; i++)
    {
        if(i==0)
        {
            estructCriba[i]->inicio=2;
        }
        else
        {
            estructCriba[i]->inicio=((i*numMax)/numHilos)+1;
        }
        estructCriba[i]->fin=((i+1)*numMax)/numHilos;
        estructCriba[i]->nums=nums;
        estructCriba[i]->max=numMax;
        hilos[i].tid=tids[i];
        hilos[i].args=(void*)estructCriba[i];
        hilos[i].attr=attr;
        hilos[i].funcion=funcion;
    }
    gettimeofday(&start, NULL);
    hilosGenerarHilos(hilos, numHilos);
    hilosEsperarHilos(hilos, numHilos);
    //Enseñar resultados
    gettimeofday(&end, NULL);
    
    cribaTotalPrimos(nums, numMax);
    clocktime= end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6;
    printf("Tardo %.8f segundos.\n", clocktime);
    //Free
    for(int i=0; i<numHilos; i++)
    {
        free(estructCriba[i]);
    }
    free(estructCriba);
    free(hilos);
    free(tids);
    free(nums);
}