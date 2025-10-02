#include "cliente.h"
#include <iostream> 



Cliente::Cliente(){ // Constructor sin parametros
	this->nombre = "";
	this->identificacion = ""; 
	this->formaPago = "";
	this->telefono = "";       
	this->numeroCuenta = "";
}

// Constructor con parametros
Cliente::Cliente(const std::string& pNombre, const std::string& pIdentificacion, const std::string& pFormaPago, const std::string& pTelefono, const std::string& pNumeroCuenta) {
	this->nombre = pNombre;
	this->identificacion = pIdentificacion;
	this->formaPago = pFormaPago;
	this->telefono = pTelefono;
	this->numeroCuenta = pNumeroCuenta;
}

Cliente::~Cliente() {}

// Gets
std::string Cliente::getNombre() const {
	return nombre;
}

std::string Cliente::getIdentificacion() const { // CAMBIO de int a std::string
	return identificacion;
}

std::string Cliente::getFormaPago() const {
	return formaPago;
}

std::string Cliente::getTelefono() const { // CAMBIO de int a std::string
	return telefono;
}

std::string Cliente::getNumeroCuenta() const {
	return numeroCuenta;
}

// Sets
void Cliente::setNombre(const std::string& pNombre) {
	this->nombre = pNombre;
}

void Cliente::setIdentificacion(const std::string& pIdentificacion) {
	this->identificacion = pIdentificacion;
}

void Cliente::setFormaPago(const std::string& pFormaPago) {
	this->formaPago = pFormaPago;
}

void Cliente::setTelefono(const std::string& pTelefono) {
	this->telefono = pTelefono;
}

void Cliente::setNumeroCuenta(const std::string& pNumeroCuenta) {
	this->numeroCuenta = pNumeroCuenta;
}
