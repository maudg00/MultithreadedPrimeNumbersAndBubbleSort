default: arreglo.o controlador.o criba.o hilos.o vista.o
	gcc -lpthread controlador.o criba.o vista.o hilos.o arreglo.o -oPractica1
arreglo.o : arreglo.c
	gcc -c arreglo.c
controlador.o: controlador.c
	gcc -c controlador.c
criba.o: criba.c
	gcc -c criba.c
hilos.o: hilos.c
	gcc -c hilos.c
vista.o: vista.c
	gcc -c vista.c
limpia:
	rm *.o
