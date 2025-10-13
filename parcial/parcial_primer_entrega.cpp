#include <iostream>
#include <vector>

void inicializar(std::vector<std::vector<char>> &a){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			a[i][j] = ' ';
		}
	}
}

void tablero (std::vector < std::vector<char>> b){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
				std::cout << b[i][j];

				if (j < 2) {
						std::cout << " | ";
				}
		}

		if (i < 2) {
				std::cout << "\n---|---|---\n";
		} else {
				std::cout << "\n";
		}
	}
}

bool validacion_movimiento(std::vector < std::vector<char>> a, int pos){
	int x_pos = (pos-1) / 3;	
	int y_pos = (pos-1) % 3;

	if ((a[x_pos][y_pos] != 'X') && (a[x_pos][y_pos] != 'O')){
		return true;
	}
	else{
		return false;
	}
}

void modificacion (std::vector < std::vector <char>> &c, int pos, char x ){
	if(validacion_movimiento(c, pos)){
		int x_pos = (pos-1) / 3;	
		int y_pos = (pos-1) % 3;

		c[x_pos][y_pos] = x;
		tablero(c);
	}
	else{
		std::cout << "No es valido" << std::endl;
		tablero (c);
	}
}

bool ganador (std::vector<std::vector<char>> d, char jugador ){
	bool respuesta = false;

	
	for(int i = 0; i < 3; i++){
		int contar = 0;
		for(int j = 0; j < 3; j++){
			if(d[i][j] == jugador){
				contar = contar+1;
			}
		}
		
		if(contar == 3) {
			respuesta = true;
		}

		contar = 0;
		for(int j = 0; j < 3; j++){
			if(d[j][i] == jugador){
				contar = contar+1;
			}
		}

		if(contar == 3) {
			respuesta = true;
		}
	}

	int contar = 0;
	for(int i = 0; i< 3; i++){
		if(d[i][i] == jugador){
			contar = contar+1;
		}
	}

	if (contar == 3 ){
		respuesta = true;
	}

	contar = 0;
	for(int j = 0; j< 3; j++){
		if(d[j][2-j] == jugador){
			contar = contar+1;
		}
	}

	if (contar == 3 ){
		respuesta = true;
	}

	return respuesta;
}


int main() {
	
	std::cout << "Bienvenido a 3 en raya" << std::endl;
	int opciones; 
	std::cout << "seleccione una opcion 1 jugar \n 2 salir " << std::endl;
	
	std::cin >> opciones;
	
	std::vector<std::vector<char>> a;
	
	switch (opciones )
	{
	case 1:
		std::cout << "Las posiciones son:" << std::endl;
		a = {
			{'1', '2', '3'},
			{'4', '5', '6'},
			{'7', '8', '9'}
		};
		tablero(a);
		
		break;
	
	case 2:
		std::cout << "juego finalizado" << std::endl;

		return 0;

	default:
		std::cout << "respuesta inexistente " << std::endl;
		return 0;
	}

	bool continua = true;
	while(continua){
		a = {
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
		};
		
		int posiciones_llenas = 0;
		char jugador = 'X';
		char jugador_ganador = '-';
		while(posiciones_llenas < 9){
			int posicion;
			std::cout << "Introduzca la posición" << std::endl;
			std::cin >> posicion;
	
			if(validacion_movimiento(a, posicion)){
				modificacion(a, posicion, jugador);
				posiciones_llenas = posiciones_llenas+1;

				if(ganador(a, jugador)){
					jugador_ganador = jugador;
					break;
				}
				
				if (jugador == 'X') {
						jugador = 'O';
				} else {
					jugador = 'X';
				}
			} else {
				std::cout << "¡Posición inválida! Intente de nuevo." << std::endl;
			}
		} 
		if (jugador_ganador == '-'){
			std::cout << "empate" << std::endl;
		} else {
			std::cout << "El ganador es: " << jugador_ganador << std::endl;
		}
		int opcion = 0;
		std::cout << "1. Jugar de nuevo " << std::endl;
		std::cout << "2. salir" << std::endl;
		while(opcion != 1 && opcion != 2){
			std::cin >> opcion;
			switch (opcion)
			{
			case 1:
				continua = true; 
				break;
			case 2:
				continua = false; 	
				break;
			default:
				std::cout << "opcion invalida " << std::endl;
				break;
			}
		}
	}

	return 0;
}
