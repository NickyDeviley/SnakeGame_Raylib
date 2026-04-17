#pragma once

class Comida {

public:
	Comida() = default;
	~Comida() = default;
	
	void gerarComida(int alturaJanela, int larguraJanela);
	void draw();


	int x, y; // Variáveis para armazenar a posição da comida
};

