#include "Contenedora.h"

Contenedora::Contenedora(int filas, int columnas) {
	this->filas = filas;
	this->columnas = columnas;
	
	// crea la matriz a partir de su tamanio
	matriz = new Habitacion*[filas];
        for (int i = 0; i < filas; i++) {
            matriz[i] = new Habitacion[columnas];
        }
}

Contenedora::~Contenedora() { // Elimina la matriz por filas y por columnas
	for (int i = 0; i < filas; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
}

bool Contenedora::insertar(Habitacion habitacion) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			// busca el primer campo de la matriz donde no haya habitacion
			if(matriz[i][j].getIdHabitacion() == ""){
				// Se inserta la habitacion en ese campo
				matriz[i][j] = habitacion;
				return true; // retorna true una vez se haya insertado la Habitacion al registro
			}
		}
	}
	return false; //retorna false si no se pudo insertar la habitacion
}

Habitacion Contenedora::buscar(string id_habitacion) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			//se buscar por ID de habitacion
			if(matriz[i][j].getIdHabitacion() == id_habitacion) {
				return matriz[i][j]; // retorna la habitacion si la encontro
			}
		}
	}
	return Habitacion(); // retorna una habitacion vacia si no encontro nada
}

bool Contenedora::eliminar(string id_habitacion) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			//se buscar por ID de habitacion
			if(matriz[i][j].getIdHabitacion() == id_habitacion) {
				matriz[i][j] = Habitacion(); // el espacio de la matriz que tenia la habitacion que se buscaba pasa a estar vacio
				return true; // retorna true para confirmar que se elimino de la matriz
			}
		}
	}
	return false; // retorano false si no se elimino de la matriz
}
