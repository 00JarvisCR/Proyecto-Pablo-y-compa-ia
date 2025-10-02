#include "habitacion.h"
#include <iostream>

// Implementación de la clase Habitacion

Habitacion::Habitacion() {
	this->idHabitacion = "";
	this->estado = 'L';
	this->capacidad = 0;
	this->cliente = nullptr;
	this->info = nullptr;
	this->precioBase = 0.0;
}

Habitacion::Habitacion(const string& pIdHabitacion, char pEstado, int pCapacidad) {
	this->idHabitacion = pIdHabitacion;
	this->estado = pEstado;
	this->capacidad = pCapacidad;
	this->cliente = nullptr;
	this->info = nullptr;
	
	// Definición del precio base según la capacidad
	switch (pCapacidad) {
	case 1:
		this->precioBase = 150.00;
		break;
	case 2:
		this->precioBase = 250.00;
		break;
	case 3:
		this->precioBase = 350.00;
		break;
	default: // Más de tres personas
		this->precioBase = 400.00;
		break;
	}
}

Habitacion::~Habitacion() {
	// Liberar memoria dinámica de los punteros
	if (cliente != nullptr) {
		delete cliente;
		cliente = nullptr;
	}
	if (info != nullptr) {
		delete info;
		info = nullptr;
	}
}

// Gets
string Habitacion::getIdHabitacion() const { return this->idHabitacion; }
char Habitacion::getEstado() const { return this->estado; }
int Habitacion::getCapacidad() const { return this->capacidad; }
Cliente* Habitacion::getCliente() const { return this->cliente; }
Informacion* Habitacion::getInformacion() const { return this->info; }
double Habitacion::getPrecioBase() const { return this->precioBase; }

// Sets
void Habitacion::setEstado(char pEstado) { this->estado = pEstado; }
void Habitacion::setCliente(Cliente* pCliente) { this->cliente = pCliente; }
void Habitacion::setInformacion(Informacion* pInfo) { this->info = pInfo; }
void Habitacion::setPrecioBase(double pPrecio) { this->precioBase = pPrecio; }


// Calcular el precio final de la habitación (Lógica de la hora corregida)
double Habitacion::calcularPrecioFinal() const {
	if (info == nullptr) {
		return 0; // No hay información de estadía, precio es 0.
	}
	
	double precioFinal = 0.0;
	
	// Condición 1: Todo Incluido
	if (info->getTodoIncluido()) {
		precioFinal = (info->getNumAdultos() * 300.00 + info->getNumNinos() * 200.00) * info->getNumDias();
	} else {
		// Obtenemos la hora actual para la condición de descuento
		int horaDelCalculo = Reloj::obtenerHora24(); 
		
		// Condición 2 (Diurna): Descuento NO aplica. Asumimos 3 AM a 6 PM (hora 3 a hora 18)
		if (horaDelCalculo >= 3 && horaDelCalculo <= 18) { 
			precioFinal = this->precioBase * info->getNumDias();
		} 
		// Condición 3 (Nocturna): Descuento aplica (antes de las 3 AM o después de las 6 PM)
		else {
			precioFinal = this->precioBase * info->getNumDias();
			
			double descuento = 0.0;
			int totalPersonas = info->getNumAdultos() + info->getNumNinos();
			
			if (totalPersonas == 1) {
				descuento = 0.25;
			} else if (totalPersonas == 2) {
				descuento = 0.20;
			} else if (totalPersonas == 3) {
				descuento = 0.15;
			} else { // 4 o más personas
				descuento = 0.10;
			}
			
			precioFinal = precioFinal * (1.0 - descuento); // Aplicar descuento
		}
	}
	return precioFinal;
}

string Habitacion::to_string() {
	stringstream oss;
	
	oss << "ID: " << idHabitacion <<endl;
	oss << "Estado: " << estado << endl;
	oss << "Capacidad: " << capacidad << endl;
	oss << "Cliente: " << cliente->getNombre() << endl;
	oss << "Precio base: " << precioBase << endl;
	oss << "\nInformacion de la habitacion:\n\n";
	oss << info->to_string();
	
	return oss.str();
}
