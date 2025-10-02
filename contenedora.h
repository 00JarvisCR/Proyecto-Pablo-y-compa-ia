#ifndef CONTENEDORA_H
#define CONTENEDORA_H

#include <iostream>

#include "habitacion.h"

using namespace std;

// Clase Hotel: gestiona la matriz dinámica de habitaciones del hotel.
class Contenedora {
private:
	int filas, columnas;
	Habitacion** matriz = nullptr; // la matriz de habitaciones (basicamente simula un edificio que son literalmente una estructura de habitacinoes)
public:
	Contenedora(int filas, int columnas); // constructor
	~Contenedora(); // destructor
	
	// Metodo CRUD (create, read, update, delete) basicamente es funcionamiento minimo de un contenedor
	bool insertar(Habitacion); // para que a la hora de crear un habitacion se inserte dentro de la matriz
	Habitacion buscar(string id_habitacion); //seria el "puede ver" que se solicita simplemente se retornaria una habitacion para luego imprimirla
	bool eliminar(string id_habitacion); // para eliminar una habitacion de la matriz
};

#endif // CONTENEDORA_H
