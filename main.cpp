#include <iostream>

#include "contenedora.h"

using namespace std;

/// DECLARACION DE FUNCIONES:
Contenedora menuInicial(); // esta funcion es para pedir inicialmente a el usuario que ingrese el tamanio de el hotel y luego se retorna la contenedora
void menuHotel(Contenedora& hotel); // esta funcion es donde estaran todas las funcionalidades de reportes (funcionalidades de la contenedora)
void menuRecaudacion(Contenedora& hotel); // esta funcion es donde se vera el dinero recuadado por diferentes clasificaciones
void reservar(Contenedora& hotel); // esta fucion es donde se pediran todos los datos necesarios para poder relializar una ocupacion (crear un habitacion y insertarla en la matriz)
void desocupar(Contenedora& hotel); // esta funcion es donde pedira el id de un usuario para que este mismo desocupe la habitacion

/// VARIABLES GLOBALES:
int opcion; // variable para ingresar las opcinoes del menu

/// MAIN
int main() {
	Contenedora hotel = menuInicial(); // hotel seria una Contenedora que toma el tamanno del que fue ingresado en el menu inicial
	menuHotel(hotel);
	return 0;
}

/// FUNCIONES:
Contenedora menuInicial() { // se crea un menu inicial en el cual se pide el tamanno del "hotel"
	system("cls"); // para eliminar la pantalla
	int pisos; //filas
	int habitaciones; //columnas

	cout << "                    MENU PRINCIPAL\n";
	cout << "==========================================================\n";
	cout << "Ingrese el tamanno de el edificio que deseas:\n";
	cout << "\nNumero de pisos: ";
	cin >> pisos;
	cout << "Numero de Habitaciones por piso: ";
	cin >>habitaciones;
	
	return Contenedora(pisos, habitaciones); // se crea y se retorna la Contenedora "hotel"
}

void menuHotel(Contenedora& hotel) {
	do {
		system("cls"); // para eliminar pantalla

		cout << "                     MENU DEL HOTEL\n";
		cout << "==========================================================\n";
		cout << "1) Ver numero de habitaciones Libres\n";
		cout << "2) Ver numero de habitaciones en Mantenimiento\n";
		cout << "3) Ver numero de habitaciones Ocupadas\n";
		cout << "4) Realizar Ocupacion/Ingresar a una habitacion\n";
		cout << "5) Liberar la Habitacion/Dejar la habitacion\n";
		cout << "6) Numero de personas adultas en el hotel\n";
		cout << "7) Numero de ninnos en el hotel\n";
		cout << "8) Dinero recaudado por clasificacion\n";
		cout << "\n0) salir\n";
		cout << "==========================================================\n";
		cout << "\nIngrese una opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1:
				cout << "Numero de Habitacion Libres: " << hotel.cant_habits_libres() << endl << endl;
				system("pause"); // para pausar la pantalla
				break;
			
			case 2:
				cout << "Numero de Habitacion en Mantenimiento: " << hotel.cant_habits_mantenimiento() << endl << endl;
				system("pause"); // para limpiar pantalla
				break;
			
			case 3:
				cout << "Numero de Habitaciones Ocupadas: " << hotel.cant_habits_ocupadas() << endl << endl;
				system("pause"); // para limpiar pantalla
				break;
			
			case 4:
				reservar(hotel);
				system("pause");
				break;
			
			case 5:
				desocupar(hotel);
				system("pause");
				break;
			
			case 6:
				cout << "Numero de persona adultas en el Hotel: " << hotel.cant_personas_adultas() << endl << endl;
				system("pause");
				break;
			
			case 7:
				cout << "Numero de ninnos en el Hotel: " << hotel.cant_ninnos() << endl << endl;
				system("pause");
				break;
			
			case 8:
				menuRecaudacion(hotel);
				opcion = 1; // para que no se salga de bucle debido a que en la funcion anterior para salir se usa 0
				system("pause");
				break;
			
			case 0:
				cout << "saliendo...\n";
				break;
			
			default:
				break;
		}
	}while(opcion != 0);
}

void menuRecaudacion(Contenedora& hotel) {
	do {
		system("cls");
		
		cout << "                     DINERO RECAUDADO\n";
		cout << "==========================================================\n";
		cout << "1) Recaudacion de clientes con Todo Incluido\n";
		cout << "2) Recaudacion de clientes Sin Todo Incluido\n";
		cout << "3) Recaudacion de todos los Clientes\n";
		cout << "\n0) regresar el menu del hotel\n";
		cout << "==========================================================\n";
		cout << "\nIngrese una opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1:
				cout << "Dinero recaudado de los clientes Todo Incluido: " << hotel.dinero_todoIncluido() << endl << endl;
				system("pause");
				break;
			case 2:
			cout << "Dinero recaudado de los clientes Sin Todo Incluido: " << hotel.dinero_sinTodoIncluido() << endl << endl;
				system("pause");
				break;
			case 3:
			cout << "Dinero recaudado de los Todos los Clientes: " << hotel.dinero_clientes() << endl << endl;
				system("pause");
				break;
			case 0:
				cout << "volviendo al menu del hotel...\n\n";
				break;
			default:
				cout << "ingrese una opcion que sea valida...\n\n";
				system("pause");
				break;
		}
	}while(opcion != 0);
}

void reservar(Contenedora& hotel) {
	system("cls"); // para limpiar pantalla
	
	// variable de cliete
	string nombre;
	string identificacion;
	string formaPago;
	string telefono;
	string numeroCuenta; 
	
	string formasDePago[] = {"Efectivo", "Tarjeta de Debito", "Tarjeta de Credito"}; // para que se seleccione una opcion
	
	cout << "Ingrese su nombre: "; cin >> nombre;
	cout << "Ingrese su identificacion: "; cin >> identificacion;
	cout << "Ingrese su numero telefonico: "; cin >> telefono;
	cout << "Ingrese su numero de cuenta: "; cin >> numeroCuenta;
	
	cout << "Seleccione su forma de pago:\n";
	cout << "1) Efectivo\n";
	cout << "2) Tarjeta de Debito\n";
	cout << "3) Tarjeta de Credito\n";
	
	bool bucle = true; // para hacer un bucle 
	
	do {
		cout << "\nOpcion: ";
		cin >> opcion;
		
		switch(opcion) {
			case 1:
				formaPago = formasDePago[0];
				bucle = false; // termina bucle
				break;
			case 2:
				formaPago = formasDePago[1];
				bucle = false; // termina bucle
				break;
			case 3:
				formaPago = formasDePago[2];
				bucle = false; // termina bucle
				break;
			default:
				cout << "...INGRESE UN OPCION CORRECTA...\n\n";
				break;
		}
	}while(bucle);
	cout << endl; // hacer campo en la pantalla (un enter)
	system("pause"); // pausar pantalla
	system("cls"); // limpiar pantalla
	
	/// ============================ SE CREA UN NUEVO CLIENTE =================================
	Cliente* cliente = new Cliente(nombre, identificacion, formaPago, telefono, numeroCuenta);
	///========================================================================================
	
	
	const int MAX_CAPACIDAD = 4;// maxima capacidad por habitacion
	int cantidadPersonas = 1; // la cantidad de personas actual que tiene la habitacion (1 porque minimo tiene al cliente)
	
	//varibles para Informacion
	int numAdultos;
	int numNinos;
	int numDias;
	bool todoIncluido;
	
	do {
		if(cantidadPersonas > MAX_CAPACIDAD) {
			cout << "No se puede pasar el limite de la capacidad de la habitacion\n";
			cout << "Vuelve a intentarlo...\n";
			system("pause");
			system("cls");
		}
		cantidadPersonas = 1; // se reinicia el valor  si se repite el bucle
		
		cout << "Tienes espacio para " << MAX_CAPACIDAD - cantidadPersonas << " personas mas en la habitacion\n";
		cout << "Ingrese la cantidad de adultos que lo acompannan: "; cin >> numAdultos;
		cantidadPersonas += numAdultos;
		
		if(cantidadPersonas > MAX_CAPACIDAD) {
			continue; // se salta todo el codigo siguiente y va directo al condicional
		}
		
		cout << "\nTienes espacio para " << MAX_CAPACIDAD - cantidadPersonas << " personas mas en la habitacion\n";
		cout << "Ingrese la cantidad de ninnos que lo acompannan: "; cin >>numNinos;
		cantidadPersonas += numNinos;
		
	}while (cantidadPersonas > MAX_CAPACIDAD); // Vueve a iterar si se supera la cantidad maxima de personas por habitacion
	
	bucle = true;
	do {
		cout << "Ingrese la cantidad de dias que se va a quedar: "; cin >>numDias;
		cout << "Quieres todo incluido?\n";
		cout << "1) si\n";
		cout << "2) no\n";
		cout << "opcion: "; cin >> opcion;
		
		switch(opcion) {
			case 1:
				todoIncluido = true;
				bucle = false; // termina el bucle
				break;
			case 2:
				todoIncluido = false;
				bucle = false; // termina el bucle
				break;
			default:
				cout << "ingrese una opcion valida...";
				break;
		}
	}while(bucle); // solo sale si se ingresa un opcion correcta
	
	/// ========================= SE CREA UNA NUEVA INFORMACION ===============================
	Informacion* informacion = new Informacion(numAdultos, numNinos, numDias, todoIncluido);
	///========================================================================================
	
	/// =========================================== SE CREA LA HABITACION =====================================================
	//el ID de la habitacoin se pone automatico en el momento que se haga el metodo realizarOcupacion de la clase Contenedora
	Habitacion habitacion("", 'O', cantidadPersonas);
	habitacion.setCliente(cliente);
	habitacion.setInformacion(informacion);
	///========================================================================================================================
	
	hotel.realizar_ocupacion(habitacion); // ingresa la habitacion a la matriz (hotel)
}

void desocupar(Contenedora& hotel) {
	string id;
	cout << "ingrese su Identificacion para desocupar la habitacion: "; cin >> id;
	
	if(!hotel.liberar_habitacion(id)) {
		cout << "No se pudo desocupar, revise que id este correcto o que hayan habitacion registradas para este cliente\n\n";
	}
	else{
		cout << "Se desocupo correctamente la habitacion\n\n";
	}
}
