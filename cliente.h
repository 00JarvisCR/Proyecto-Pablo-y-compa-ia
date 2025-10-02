#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

using namespace std;

class Cliente {
private:
	string nombre;
	string identificacion;
	string formaPago;
	string telefono;
	string numeroCuenta;
	
public:
	// Constructor por defecto
	Cliente();
	
	
	Cliente(const string& pNombre, const string& pIdentificacion, const string& pFormaPago, const string& pTelefono, const string& pNumeroCuenta);
	
	
	~Cliente();
	
	// getters
	string getNombre() const;
	string getIdentificacion() const; 
	string getFormaPago() const;
	string getTelefono() const;       
	string getNumeroCuenta() const;
	
	// setters
	void setNombre(const std::string& pNombre);
	void setIdentificacion(const std::string& pIdentificacion);
	void setFormaPago(const std::string& pFormaPago);
	void setTelefono(const std::string& pTelefono);
	void setNumeroCuenta(const std::string& pNumeroCuenta);
};

#endif 
