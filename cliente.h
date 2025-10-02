#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>


class Cliente {
private:
	std::string nombre;
	std::string identificacion;
	std::string formaPago;
	std::string telefono;
	std::string numeroCuenta;
	
public:
	// Constructor por defecto
	Cliente();
	
	
	Cliente(const std::string& pNombre, const std::string& pIdentificacion, const std::string& pFormaPago, const std::string& pTelefono, const std::string& pNumeroCuenta);
	
	
	~Cliente();
	
	// getters
	std::string getNombre() const;
	std::string getIdentificacion() const; 
	std::string getFormaPago() const;
	std::string getTelefono() const;       
	std::string getNumeroCuenta() const;
	
	// setters
	void setNombre(const std::string& pNombre);
	void setIdentificacion(const std::string& pIdentificacion);
	void setFormaPago(const std::string& pFormaPago);
	void setTelefono(const std::string& pTelefono);
	void setNumeroCuenta(const std::string& pNumeroCuenta);
};

#endif 
