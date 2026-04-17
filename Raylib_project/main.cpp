#include <raylib.h>

#include "GameLoop.h"

int main() {
	
	/*
		O objeto game é criado na memória
		stack. Ele é uma instância da 
		classe GameLoop, que é responsável 
		por gerenciar o loop do jogo.
	*/
	GameLoop game;	// Criando uma instância da classe GameLoop
	game.run();		// Iniciando o loop do jogo

	return 0;
}