#pragma once

#include "Snake.h"
#include "Comida.h"
#include "Colisao.h"

#include <vector>

class GameLoop {

public:
	GameLoop() = default;			// Construtor Padrão
	~GameLoop() = default;			// Destrutor Padrão
	void run();						// Método para iniciar o loop do jogo

private:
	void draw();					// Método para desenhar no canvas

	// Constantes
	const int larguraJanela = 800;	// Largura da janela
	const int alturaJanela = 800;	// Altura da janela
	const int fps = 24;				// Taxa de quadros por segundo

	Colisao colisao = Colisao::NENHUMA;				// Variável para armazenar o tipo de colisão

	// Objetos
	Snake snake{alturaJanela, larguraJanela};
	Comida comida;

};