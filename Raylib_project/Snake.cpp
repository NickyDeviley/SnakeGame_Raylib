#include <raylib.h>

#include "Snake.h"
#include "Direcao.h"
#include "KeyHandler.h"
#include "Posicao.h"
#include "Colisao.h"
#include <vector>

Snake::Snake(int alturaJanela, int larguraJanela)
{
	x = larguraJanela / 2;						// Inicializa a posição da cobra no centro da janela
	y = alturaJanela / 2;						// Inicializa a posição da cobra no centro da janela
	size = 20;									// Define o tamanho da cobra (20x20 pixels)
	speed = 20;									// Define a velocidade da cobra (20 pixels por atualização)
	direcaoAtual = Direcao::DIREITA;			// Começa movendo para a direita
	this->alturaJanela = alturaJanela;			// Armazena a altura da janela
	this->larguraJanela = larguraJanela;		// Armazena a largura da janela
	corpo.push_back(Posicao(x, y));				// Adiciona a posição inicial da cobra ao corpo
	corpo.push_back(Posicao(x - size, y));		// Adiciona a segunda parte do corpo da cobra
	corpo.push_back(Posicao(x - 2 * size, y));	// Adiciona a terceira parte do corpo da cobra
	
	tamanho = corpo.size();						// Define o tamanho inicial da cobra com base no número de partes do corpo

}

// Lógica de atualização da cobra (movimento, colisões, etc.)
Colisao Snake::update(int comidaX, int comidaY)
{

// MOVIMENTO 1

	// Ler a direção
	if (IsKeyDown(KEY_UP) && direcaoAtual != Direcao::BAIXO) {
		direcaoAtual = Direcao::CIMA;
	}
	else if (IsKeyDown(KEY_DOWN) && direcaoAtual != Direcao::CIMA) {
		direcaoAtual = Direcao::BAIXO;
	}
	else if (IsKeyDown(KEY_RIGHT) && direcaoAtual != Direcao::ESQUERDA) {
		direcaoAtual = Direcao::DIREITA;
	}
	else if (IsKeyDown(KEY_LEFT) && direcaoAtual != Direcao::DIREITA) {
		direcaoAtual = Direcao::ESQUERDA;
	}

	// A próxima posição começa como a posição atual da cabeça da cobra
	proximoX = corpo[0].x;
	proximoY = corpo[0].y;

	// Atualiza a próxima posição com base na direção atual
	switch (direcaoAtual) {
	case Direcao::CIMA:
		proximoY -= speed;
		break;
	case Direcao::BAIXO:
		proximoY += speed;
		break;
	case Direcao::DIREITA:
		proximoX += speed;
		break;
	case Direcao::ESQUERDA:
		proximoX -= speed;
		break;
	}


// COLISÃO

	// Colisão com as bordas da janela
	if (proximoX < 0) {
		this->proximoX = larguraJanela - size;	// Teleporta para o lado oposto da janela
	}
	else if (proximoX >= larguraJanela) {
		this->proximoX = 0;						// Teleporta para o lado oposto da janela
	}
	if (proximoY < 0) {
		this->proximoY = alturaJanela - size;	// Teleporta para o lado oposto da janela
	}
	else if (proximoY >= alturaJanela) {
		this->proximoY = 0;						// Teleporta para o lado oposto da janela
	}

	// Colisão com a comida
	if (proximoX == comidaX && proximoY == comidaY) {
		colidiu = true;
		qualColisao = Colisao::COMIDA;
	}

	// Colisão com o próprio corpo
	for (int i = 1; i < corpo.size(); i++) {
		if (proximoX == corpo[i].x && proximoY == corpo[i].y) {
			// A cobra colidiu com o próprio corpo
			qualColisao = Colisao::CORPO;
		}
	}

// MOVIMENTO 2

	// Para mover a cobra, inserimos uma nova instancia no começo
	// do vector e removemos a última instancia. Para dar a ilusão
	// de movimento. E nós atribuímos a nova posição para essa instância
	// criada no início do vector.
	corpo.insert(corpo.begin(), Posicao(proximoX, proximoY));	// Insere a nova posição da cabeça no início do vetor corpo

	// Verifica se a cobra colidiu com a comida
	if (!colidiu) {
		corpo.pop_back();
	}
	else {
		colidiu = false;
		//tamanho++;
	}

// RETORNO
	Colisao resultado = qualColisao;	// Armazena o tipo de colisão ocorrido
	qualColisao = Colisao::NENHUMA;		// Reseta o tipo de colisão para o próximo ciclo de atualização
	return resultado;
}

void Snake::draw()
{
	for (int i = 0; i < corpo.size(); i++) {
		// Desenhar a cobra na janela
		DrawRectangle(this->corpo[i].x, this->corpo[i].y, size, size, GREEN);
	}
}