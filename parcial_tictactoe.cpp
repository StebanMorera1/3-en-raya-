#include <iostream>
#include <vector>

void inicializar(std::vector<std::vector<char>> &table){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			table[i][j] = ' ';
		}
	}
}

void tablero(std::vector < std::vector<char>> &table){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << table[i][j];
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

bool validacion_movimiento(std::vector < std::vector<char>> table, int pos){
	if((pos < 1) || (pos > 9)) return false;

	int x_pos = (pos-1) / 3;	
	int y_pos = (pos-1) % 3;
	if ((table[x_pos][y_pos] != 'X') && (table[x_pos][y_pos] != 'O')){
		return true;
	}
	else{
		return false;
	}
}

void modificacion (std::vector < std::vector <char>> &table, int pos, char x ){
	int x_pos = (pos-1) / 3;	
	int y_pos = (pos-1) % 3;

	table[x_pos][y_pos] = x;
	tablero(table);
}

bool ganador (std::vector<std::vector<char>> table, char jugador ){
	bool respuesta = false;

	for(int i = 0; i < 3; i++){
		int contar = 0;
		for(int j = 0; j < 3; j++){
			if(table[i][j] == jugador){
				contar = contar+1;
			}
		}
		
		if(contar == 3) {
			respuesta = true;
		}

		contar = 0;
		for(int j = 0; j < 3; j++){
			if(table[j][i] == jugador){
				contar = contar+1;
			}
		}

		if(contar == 3) {
			respuesta = true;
		}
	}

	int contar = 0;
	for(int i = 0; i< 3; i++){
		if(table[i][i] == jugador){
			contar = contar+1;
		}
	}

	if (contar == 3 ){
		respuesta = true;
	}

	contar = 0;
	for(int j = 0; j< 3; j++){
		if(table[j][2-j] == jugador){
			contar = contar+1;
		}
	}

	if (contar == 3 ){
		respuesta = true;
	}

	return respuesta;
}

void entrada_entero(int &entero, std::string mensaje){
	std::cin >> entero;
	char c = std::cin.peek(); 
	while (std::cin.fail() || (c != '\n' && c != EOF && !isspace(c)))
	{
		std::cout << "La entrada no es valida\n\n";
		std::cout << mensaje << std::endl;
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cin >> entero;
		c = std::cin.peek(); 
	}
}


int main() {
	std::cout << "Bienvenido a 3 en raya" << std::endl;
	std::cout << "Seleccione una opcion:\n1: Jugar \n2: Salir" << std::endl;
	
	std::vector<std::vector<char>> a;
	
	int opcion = 0;
	while(opcion != 1 && opcion != 2){
		entrada_entero(opcion, "Seleccione una opcion:\n1: Jugar \n2: Salir");

		switch (opcion)
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
			std::cout << "Juego finalizado." << std::endl;
			return 0;
		default:
			std::cout << "Opción invalida." << std::endl;
			std::cout << "Seleccione una opcion:\n1: Jugar \n2: Salir" << std::endl;
			break;
		}
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
		int posicion; 
		while(posiciones_llenas < 9){
			std::cout << "Es el turno del jugador " << jugador << "." << std::endl;
			std::cout << "Introduzca la posición" << std::endl;

			entrada_entero(posicion, "Introduzca una posición del 1 al 9");
		
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
			else {
				std::cout << "¡Posición inválida! Intente de nuevo." << std::endl;
			}
			
		}
		if (jugador_ganador == '-'){
			std::cout << "Hubo un empate." << std::endl;
		} else {
			std::cout << "El ganador es: " << jugador_ganador << "." << std::endl;
		}
		opcion = 0;

		std::cout << "1. Jugar de nuevo\n2. Salir" << std::endl;
		while(opcion != 1 && opcion != 2){
			entrada_entero(opcion, "1. Jugar de nuevo\n2. Salir");
			switch (opcion)
			{
			case 1:
				continua = true;
				break;
			case 2:
				continua = false; 	
				std::cout << "juego finalizado" << std::endl; 
				break;
			default:
				std::cout << "Opcion Invalida." << std::endl;
				break;
			}
		}
	}

	return 0;
}
