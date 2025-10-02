#include "Informacion.h"

// Implementación de la clase Informacion

Informacion::Informacion() {
	this->numAdultos = 0;
	this->numNinos = 0;
	this->numDias = 0;
	this->todoIncluido = false;
}

Informacion::Informacion(int pNumAdultos, int pNumNinos, int pNumDias, bool pTodoIncluido) {
	this->numAdultos = pNumAdultos;
	this->numNinos = pNumNinos;
	this->numDias = pNumDias;
	this->todoIncluido = pTodoIncluido;
}

Informacion::~Informacion() {}

// Gets
int Informacion::getNumAdultos() const {
	return this->numAdultos;
}

int Informacion::getNumNinos() const {
	return this->numNinos;
}

int Informacion::getNumDias() const {
	return this->numDias;
}

bool Informacion::getTodoIncluido() const {
	return this->todoIncluido;
}

// Sets
void Informacion::setNumAdultos(int pNumAdultos) {
	this->numAdultos = pNumAdultos;
}

void Informacion::setNumNinos(int pNumNinos) {
	this->numNinos = pNumNinos;
}

void Informacion::setNumDias(int pNumDias) {
	this->numDias = pNumDias;
}

void Informacion::setTodoIncluido(bool pTodoIncluido) {
	this->todoIncluido = pTodoIncluido;
}
