#include <raylib.h>
#include <iostream>

#include "GameLoop.h"
#include "Colisao.h"

void GameLoop::run()
{
	// Criando uma janela
	InitWindow(larguraJanela, alturaJanela, "Snake Game! Raylib");

	// Definindo a taxa de quadros por segundo
	SetTargetFPS(fps);

	comida.gerarComida(alturaJanela, larguraJanela);

	// Loop principal do jogo
	while (!WindowShouldClose() && colisao != Colisao::CORPO) {

		if (this->colisao == Colisao::COMIDA) {
			// Gerar a comida
			comida.gerarComida(alturaJanela, larguraJanela);
		}

		// Atualizando a lógica do jogo
		colisao = snake.update(comida.x, comida.y);	// Atualizando a lógica da cobra

		//std::cout << (int) this->colisao << std::endl;

		// Método que desenha no canvas
		draw();

	}

	CloseWindow();
}

void GameLoop::draw()
{
	BeginDrawing();			// Começando a desenhar
	ClearBackground(BLACK);	// Limpando o fundo da janela com a cor preta
	
	snake.draw();			// Desenhando a cobra na janela
	comida.draw();			// Desenhando a comida na janela
	
	EndDrawing();			// Finalizando o desenho e apresentando o resultado na janela
}