// constantesYGlobales.h
//
//
//  Created by Mauricio de Garay on 15/02/2021.
// 
//

//Este módulo tendra las variables y constantes necesarias para el funcionamiento adecuado del programa
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>

#ifndef constantesYGlobales_h
#define constantesYGlobales_h
#ifndef constantesYGlobales_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif
//Clockspeed de tu procesador. En mi caso es de 4Ghz. Necesario para medir el tiempo de cpu adecuadamente.
#define CLOCKFREQ 4E6
#define MAX 100000
#define MAXC 1000000

//Sem
sem_t s;


#undef constantesYGlobales_IMPORT
#undef EXTERN
#endif