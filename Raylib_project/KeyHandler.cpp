#include "KeyHandler.h"
#include "Direcao.h"

#include <raylib.h>

Direcao KeyHandler::movimentacao() {

	if (IsKeyDown(KEY_UP)) {
		return Direcao::CIMA;		// Movimento para cima
	}
	if (IsKeyDown(KEY_DOWN)) {
		return Direcao::BAIXO;		// Movimento para baixo
	}
	if (IsKeyDown(KEY_RIGHT)) {
		return Direcao::DIREITA;	// Movimento para a direita
	}
	if (IsKeyDown(KEY_LEFT)) {
		return Direcao::ESQUERDA;	// Movimento para a esquerda
	}
}