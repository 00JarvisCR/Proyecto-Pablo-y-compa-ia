#ifndef CONTENEDORA_H
#define CONTENEDORA_H

#include <iostream>

#include "habitacion.h"

using namespace std;

// Clase Hotel: gestiona la matriz dinámica de habitaciones del hotel.
class Contenedora {
private:
	int filas, columnas;
	Habitacion** habitaciones; // la matriz de habitaciones (basicamente simula un edificio que son literalmente una estructura de habitacinoes)
public:
	Contenedora(int filas, int columnas); // constructor
	~Contenedora(); // destructor
	
	Habitacion buscar(string id_habitacion); //se retornaria una habitacion para que luego se pueda usar
	bool eliminar(string id_habitacion); // para eliminar una habitacion de la matriz
	
	int cant_habits_libres(); // para ver cuantas habitaciones estan libres
	int cant_habits_mantenimiento(); //para ver cuantas habitaciones estan en mantenimiento
	int cant_habits_ocupadas(); // para ver cuantas habitaciones estan ocupadas
	
	bool realizar_ocupacion(Habitacion); // para crear una reservacion con un usuario 
	bool liberar_habitacion(string identificacion); // para terminar la reservacion de un usuario
	
	int cant_personas_adultas(); // cantidad de personas adultas en el hotel
	int cant_ninnos(); // cantidad de ninnos en el hotel
	
	double dinero_todoIncluido(); // dinero recaudado con los clientes que pagaron todo incluido
	double dinero_sinTodoIncluido(); // dinero recaudado con lo clientes que no pagaron todo incluido
	double dinero_clientes(); // dinero recuadado con todos los clientes
};

#endif // CONTENEDORA_H
