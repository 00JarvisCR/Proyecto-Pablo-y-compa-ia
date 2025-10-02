#include "Contenedora.h"

Contenedora::Contenedora(int filas, int columnas) {
	this->filas = filas;
	this->columnas = columnas;
	
	// crea la matriz a partir de su tamanio
	habitaciones = new Habitacion*[filas];
        for (int i = 0; i < filas; i++) {
            habitaciones[i] = new Habitacion[columnas];
        }
}

Contenedora::~Contenedora() { // Elimina la matriz por filas y por columnas
	for (int i = 0; i < filas; i++) {
            delete[] habitaciones[i];
        }
        delete[] habitaciones;
}

Habitacion Contenedora::buscar(string id_habitacion) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			//se buscar por ID de habitacion
			if(habitaciones[i][j].getIdHabitacion() == id_habitacion) {
				return habitaciones[i][j]; // retorna la habitacion si la encontro
			}
		}
	}
	return Habitacion(); // retorna una habitacion vacia si no encontro nada
}

bool Contenedora::eliminar(string id_habitacion) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			//se buscar por ID de habitacion
			if(habitaciones[i][j].getIdHabitacion() == id_habitacion) {
				habitaciones[i][j] = Habitacion(); // el espacio de la matriz que tenia la habitacion que se buscaba pasa a estar vacio
				return true; // retorna true para confirmar que se elimino de la matriz
			}
		}
	}
	return false; // retorano false si no se elimino de la matriz
}

int Contenedora::cant_habits_libres() {
	int contador = 0; // se inicializa un contador en 0
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if(habitaciones[i][j].getEstado() == 'L'){
				contador++;
			}
		}
	}
	return contador;
}

int Contenedora::cant_habits_mantenimiento() {
	int contador = 0; // se inicializa un contador en 0
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if(habitaciones[i][j].getEstado() == 'M'){
				contador++;
			}
		}
	}
	return contador;
}

int Contenedora::cant_habits_ocupadas() {
	int contador = 0; // se inicializa un contador en 0
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if(habitaciones[i][j].getEstado() == 'O'){
				contador++;
			}
		}
	}
	return contador;
}

bool Contenedora::realizar_ocupacion(Habitacion habitacion) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			// busca el primer campo de la matriz donde no haya habitacion
			if(habitaciones[i][j].getIdHabitacion() == ""){
				// Se inserta la habitacion en ese campo
				habitaciones[i][j] = habitacion;
				return true; // retorna true una vez se haya insertado la Habitacion al registro
			}
		}
	}
	return false; //retorna false si no se pudo insertar la habitacion
}

bool Contenedora::liberar_habitacion(string identificacion) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			// buscar la habitacion por el id del usuario
			if(habitaciones[i][j].getCliente()->getIdentificacion() == identificacion) {
				habitaciones[i][j] = Habitacion(); // toda la habiatacion pasa a no tener nada de informacion
				return true; // retorna true para verificar que se puedo liberar la habitacion
			}
		}
	}
	return false; // retorana false si no se libera la habitacion
}

int Contenedora::cant_personas_adultas() {
	int contador = 0; // se inicializa un contador en 0
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			// se evaluan solo las habitaciones registradas para que no se use un metodo de informacin siendo esta misma un nullptr (daria error)
			if(habitaciones[i][j].getIdHabitacion() != ""){
				//se le agreaga la cantidad de adulos de cada habitacion al contador
				contador += habitaciones[i][j].getInformacion()->getNumAdultos();
			}
		}
	}
	return contador; // retorna la cantidad total de adultos
}

int Contenedora::cant_ninnos() {
	int contador = 0; // se inicializa un contador en 0
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			// se evaluan solo las habitaciones registradas para que no se use un metodo de informacin siendo esta misma un nullptr (daria error)
			if(habitaciones[i][j].getIdHabitacion() != ""){
				//se le agreaga la cantidad de ninnos de cada habitacion al contador
				contador += habitaciones[i][j].getInformacion()->getNumNinos();
			}
		}
	}
	return contador; // retorna la cantidad total de ninnos
}

double Contenedora::dinero_todoIncluido() {
	double dinero_recaudado = 0.0; // se inicializa la recaudacion en 0
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			// se evaluan las habitaciones todo incluido
			if(habitaciones[i][j].getInformacion()->getTodoIncluido()) {
				// se le suma el precio de la habitacion al dinero recaudado
				dinero_recaudado += habitaciones[i][j].calcularPrecioFinal();
			}
		}
	}
	
	return dinero_recaudado; // retorna el total del dinero recuadado
}

double Contenedora::dinero_sinTodoIncluido() {
	double dinero_recaudado = 0.0; // se inicializa la recaudacion en 0
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			// se evaluan las habitaciones sin todo incluido
			if(!habitaciones[i][j].getInformacion()->getTodoIncluido()) {
				// se le suma el precio de la habitacion al dinero recaudado
				dinero_recaudado += habitaciones[i][j].calcularPrecioFinal();
			}
		}
	}
	
	return dinero_recaudado; // retorna el total del dinero recuadado
}

double Contenedora::dinero_clientes() {
	double dinero_recaudado = 0.0; // se inicializa la recaudacion en 0
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			// se le suma el precio de todas las habitaciones al dinero recaudado
			dinero_recaudado += habitaciones[i][j].calcularPrecioFinal();
		}
	}
	
	return dinero_recaudado; // retorna el total del dinero recuadado
}
