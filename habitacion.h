#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include "cliente.h"
#include "informacion.h"
#include "Reloj.h" // Incluimos Reloj para usar el m�todo static
using namespace std;


class Habitacion {
private:
	string idHabitacion;
	char estado; // 'O' Ocupada, 'M' Mantenimiento, 'L' Libre
	int capacidad; // Cantidad de personas (1-4)
	Cliente* cliente;
	Informacion* info;
	double precioBase;
	
public:
	// Constructor por defecto
	Habitacion();
	
	// Constructor parametrizado
	Habitacion(const string& pIdHabitacion, char pEstado, int pCapacidad);
	
	// Destructor
	~Habitacion();
	
	// M�todos de acceso (getters)
	string getIdHabitacion() const;
	char getEstado() const;
	int getCapacidad() const;
	Cliente* getCliente() const;
	Informacion* getInformacion() const;
	double getPrecioBase() const;
	
	// Metodo de c�lculo
	double calcularPrecioFinal() const;
	
	// M�todos de modificaci�n (setters)
	void setEstado(char pEstado);
	void setCliente(Cliente* pCliente);
	void setInformacion(Informacion* pInfo);
	void setPrecioBase(double pPrecio);
};
#endif // HABITACION_H
