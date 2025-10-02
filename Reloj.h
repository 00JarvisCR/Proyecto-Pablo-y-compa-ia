#ifndef RELOJ_H
#define RELOJ_H

class Reloj {
public:
	static int obtenerHora24();
	static int obtenerMinuto();
	static int obtenerSegundo();
	
	// Mostrar durante N segundos (0 = infinito)
	static void mostrarReloj(int duracionSegundos = 0);
	

};
#endif // RELOJ_H
