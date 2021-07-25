// vista.h
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//
#include <stdio.h>
#include <stdlib.h>


#ifndef vista_h
#define vista_h
#ifndef vista_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


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
EXTERN void vistaLimpiaBuffer();
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
EXTERN void vistaEnter();
/*
* La función vistaIntroducción se encarga de desplegar la introducción al usuario.
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
EXTERN void vistaIntroduccion();
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
EXTERN char vistaMenu();
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
EXTERN int vistaPedirNumPositivo(int max, char * string);


#undef vista_IMPORT
#undef EXTERN
#endif