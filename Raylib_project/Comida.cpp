#include "Comida.h"
#include <raylib.h>

void Comida::gerarComida(int alturaJanela, int larguraJanela)
{
	int num1 = GetRandomValue(0, larguraJanela - 20);
	int num2 = GetRandomValue(0, larguraJanela - 20);
	
	x = num1 - (num1 % 20); // Ajusta para o múltiplo mais próximo de 20
	y = num2 - (num2 % 20); // Ajusta para o múltiplo mais próximo de 20
}

void Comida::draw() {
	// Desenhar a comida na posição gerada
	DrawRectangle(x, y, 20, 20, RED); // Desenha um quadrado vermelho representando a comida
}