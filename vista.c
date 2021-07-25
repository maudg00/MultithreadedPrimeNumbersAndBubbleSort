// vista.c
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//
#include <stdio.h>
#include <stdlib.h>





/* Function prototypes. */

/*
* La función vistaLimpiaBuffer se encarga de limpiar el buffer de stdin.
*
*
* @params 
*   
*   
*
* @returns
*   
*
*/
void vistaLimpiaBuffer()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
/*
* La función vistaEnter se encarga de esperar a que el usuario ingrese enter.
*
*
* @params 
*   
*   
*
* @returns
*   
*
*/
void vistaEnter()
{
    char cont;
    printf("Presiona <enter> para continuar... ");
    scanf("%c", &cont);
    if(cont!='\n')
        vistaLimpiaBuffer();
}
/*
* La función vistaIntroduccion se encarga de desplegar la introducción al usuario.
*
*
* @params 
*   
*   
*
* @returns
*   
*
*/
void vistaIntroduccion()
{
    system("clear");
    
    printf("Bienvenido a la practica 1: Criba y Bubblesort.\n");
    printf("Este programa fue creado por Mauricio de Garay Hernández el 15/01/2021.\n");
    printf("El programa cuenta con 2 opciones: \n");
    printf("-------------------------------------------------------------------------------------------------\n\n");
    printf("\tEn la primera, se te solicita el tamanio de un arreglo a ordenar que se genera aleatoramiente.\n");
    printf("\tEl arreglo se ordena con 2 hilos utilizando bubblesort y se te dice el tiempo transcurrido.\n\n");
    printf("\tEn el segundo, se encontraran todos los números primos hasta un cierto valor que tú ingreses.\n");
    printf("\tSe te pediran el numero maximo hasta el cual buscar y con cuantos hilos quieres buscarlo, trata de no meter mas hilos de con los que cuenta tu ordenador.\n\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    
}
/*
* La función vistaMenu  se encarga de desplegar el menu al usuario.
*
*
* @params 
*   
*   
*
* @returns
*   char op: la opción seleccionada.
*
*/
char vistaMenu()
{
    system("clear");
    char op;
    printf("Menu:\n\n");
    printf("\t1.- Ordenar un arreglo.\n");
    printf("\t2.- Encontrar todos los numeros primos hasta cierto valor.\n");
    printf("\t3.- Salir.\n");
    printf("Ingresa tu opcion: ");
    scanf("%c", &op);
    vistaLimpiaBuffer();
    return op;
}
/*
* La función vistaPedirNumPositivo se encarga de pedir un número positivo acotado.
*
*
* @params 
*      int max: el máximo número que se puede ingresar.
*      char *string: el mensaje de error si se ingresa un número mayor.
*
* @returns
*   int num: el número leído.
*
*/
int vistaPedirNumPositivo(int max, char * string)
{
    
    int num;
    do
    {
        printf("Dame un numero positivo menor o igual a %d: ", max);
        scanf("%d", &num);
        vistaLimpiaBuffer();
        if(!(num>0 && num<=max))
        {
            if(num<=0)
            {
                printf("El numero debe de ser mayor a 0. Vuelve a intentar.\n\t");
            }
            else
            {
                printf("%s. El maximo numero permito es %d.\n\t", string, max);
            }
        }
    } while (!(num>0 && num<=max));
    system("clear");
    return num;
}