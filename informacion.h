#ifndef INFORMACION_H
#define INFORMACION_H

// Clase Informacion: detalles de la estad�a en la habitaci�n.
class Informacion {
private:
	int numAdultos;
	int numNinos;
	int numDias;
	bool todoIncluido;
	
public:
	// Constructor por defecto
	Informacion();
	
	// Constructor parametrizado
	Informacion(int pNumAdultos, int pNumNinos, int pNumDias, bool pTodoIncluido);
	
	// Destructor
	~Informacion();
	
	// M�todos de acceso (getters)
	int getNumAdultos() const;
	int getNumNinos() const;
	int getNumDias() const;
	bool getTodoIncluido() const;
	
	// M�todos de modificaci�n (setters)
	void setNumAdultos(int pNumAdultos);
	void setNumNinos(int pNumNinos);
	void setNumDias(int pNumDias);
	void setTodoIncluido(bool pTodoIncluido);
};

#endif // INFORMACION_H
