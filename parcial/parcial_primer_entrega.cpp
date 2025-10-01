#include <iostream>
#include <vector>

// Pasa una copia de a y sobre esa copia trabaja
// pos 5
// coord_x[pos-1] = 1
// coord_y[pos-1] = 1
// {3, 4, 1, 2, 5};
// a[k-1];

void inicializar(std::vector<std::vector<char>> &a){
	// a.assign(3, std::vector(3, ' '));
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

// a es el tablero
// pos es la posición que va entre 1 y 9

bool validacion_movimiento(std::vector < std::vector<char>> a, int pos){
	int x_pos = (pos-1) / 3;	
	int y_pos = (pos-1) % 3;

	// Si pos = 5, a[1][1]
	if ((a[x_pos][y_pos] != 'X') && (a[x_pos][y_pos] != 'O')){
		return true;
	}
	else{
		return false;
	}
}

// tablero, 1<=posicion<=9, jugador='X' u 'O'
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

// Si un jugador ganó
// tablero, jugador='X' u 'O'
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
	std::cout << "Las posiciones son:" << std::endl;
	std::vector<std::vector<char>> a{
			{'1', '2', '3'},
			{'4', '5', '6'},
			{'7', '8', '9'}
		};
	tablero(a);

	bool continua = true;
	while(continua){
		inicializar(a);
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
				    
				    
				    
				    
				    
