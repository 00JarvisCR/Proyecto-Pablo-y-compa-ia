#include "Reloj.h"
#include <ctime>
#include <cstdio>
#include <windows.h> // Sleep, SetConsoleCursorPosition, COORD

// Definición del método privado static
int Reloj::obtenerHora24() {
	std::time_t tiempoAhora = std::time(nullptr);
	std::tm* tiempoLocal = std::localtime(&tiempoAhora);
	return tiempoLocal->tm_hour;
}

int Reloj::obtenerMinuto() {
	std::time_t tiempoAhora = std::time(nullptr);
	std::tm* tiempoLocal = std::localtime(&tiempoAhora);
	return tiempoLocal->tm_min;
}

int Reloj::obtenerSegundo() {
	std::time_t tiempoAhora = std::time(nullptr);
	std::tm* tiempoLocal = std::localtime(&tiempoAhora);
	return tiempoLocal->tm_sec;
}

void Reloj::mostrarReloj(int duracionSegundos) {
	if (duracionSegundos <= 0) {
		// Bucle infinito
		for (;;) {
			int h = obtenerHora24();
			int m = obtenerMinuto();
		
			
			
			std::printf("%02d:%02d\n", h, m);			//std::printf("%02d:%02d:%02d\n", h, m, s);
			
			Sleep(1000);
		}
	} else {
		for (int i = 0; i < duracionSegundos; ++i) {
			int h = obtenerHora24();
			int m = obtenerMinuto();
		
			

			std::printf("%02d:%02d\n", h, m);					//std::printf("%02d:%02d:%02d\n", h, m, s);
			
			Sleep(1000);
		}
	}
}

