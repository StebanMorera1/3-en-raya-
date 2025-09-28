#include <iostream>
#include <vector>

int posiciones[3][3] = {
						{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}
};

// Pasa una copia de a y sobre esa copia trabaja
// Trabajar y modificar el mismo que yo le paso

// 1 <= pos <= 9 -> x, y
//                1  2  3  4  5  6  7  8  9
int coord_x[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int coord_y[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};


// pos 5
// coord_x[pos-1] = 1
// coord_y[pos-1] = 1
// {3, 4, 1, 2, 5};
// a[k-1];

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

// a es el tablero
// pos es la posición que va entre 1 y 9
bool validacion_movimiento(std::vector < std::vector<char>> a, int pos){
	int x_pos = coord_x[pos-1];	
	int y_pos = coord_y[pos-1];

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
			int x_pos = coord_x[pos-1]; // Fila
			int y_pos = coord_y[pos-1]; // Columna

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

	int contar = 0;

	for(int j = 0; j < 3; j++){
		if(d[0][j] == jugador){
			contar = contar+1;
		}
	}
	if(contar == 3) {
		respuesta = true;
	}
	// = Darle un valor a algo
	// == comparar dos valores
	contar = 0;
	for(int j = 0; j < 3; j++ ){
		if (d[1][j] == jugador){
			contar = contar +1;
		}
	}
	if(contar == 3 ){
		respuesta = true;
	}
	contar = 0;
	for(int j = 0; j < 3; j++ ){
		if (d[2][j] == jugador){
			contar = contar +1;
		}
	}
	if(contar == 3 ){
		respuesta = true;
	}
	contar = 0;
	for(int i = 0; i < 3; i++){
		if (d [i][0] == jugador ){
			contar = contar +1;
		}
	}
	if (contar == 3 ){
		respuesta = true;
	}
	contar = 0;
	for(int i = 0; i < 3; i++){
		if (d [i][1] == jugador ){
			contar = contar +1;
		}
	}
	if (contar == 3 ){
		respuesta = true;
	}
	contar = 0;
	for(int i = 0; i < 3; i++){
		if (d [i][2] == jugador ){
			contar = contar +1;
		}
	}
	if (contar == 3 ){
		respuesta = true;
	}
	contar = 0;
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
std::cout << "Las posiciones son:" << std::endl;
for (int i = 0; i < 3; i++) {
 std::cout << " " << posiciones[i][0] << " | " << posiciones[i][1] << " | " << posiciones[i][2] << std::endl;
 if (i < 2) {
 std::cout << "---|---|---" << std::endl;
	}
	}
	std::cout << std::endl;

		std::cout << "bienvenido a 3 en raya" << std::endl;

		std::vector<std::vector<char>> a{
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
		};

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

		return 0;
}





