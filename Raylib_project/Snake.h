#pragma once

#include "Snake.h"
#include "Direcao.h"
#include "KeyHandler.h"
#include "Posicao.h"
#include "Colisao.h"
#include <vector>

class Snake {

public:
	Snake() = default;
	Snake(int alturaJanela, int larguraJanela);
	~Snake() = default;

	Colisao update(int comidaX, int comidaY);
	void draw();

private:
	
	int x, y;
	int proximoX, proximoY;
	int size;
	int speed;
	int tamanho;
	int alturaJanela, larguraJanela;
	
	bool colidiu = false;
	Colisao qualColisao = Colisao::NENHUMA;
	
	Direcao direcaoAtual;
	std::vector<Posicao> corpo;
};