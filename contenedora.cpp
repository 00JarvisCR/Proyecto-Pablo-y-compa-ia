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

void Contenedora::insertar(Habitacion habitacion) {
	
}
