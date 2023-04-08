#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum Celulas {
	Agua,
	Barco1,
	Barco2,
	Barco3,
	Barco4,
	Barco5,
	Barco6,
	Barco7,
	Barco8,
	Barco9,
	Barco10,
	Barco11,
	Barco12,
	Barco13,
	Barco14
};

enum Conceitos {
	Ok, Vertical, Horizontal
};

//função pra definir de a direção do barco vai ser vertical ou horizontal
void defineDirecao(int *direcao) {
	int X, Y;

	X = rand() % 10;
	Y = rand() % 10;

	if (X == 9) {
		*direcao = Vertical;
	} else if (Y == 9) {
		*direcao = Horizontal;
	} else {
		*direcao = 1 + (rand() % 2);
	}
}

int desenhaBomba(sf::RenderWindow &janela, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10], int dim,
		sf::Sprite spriteBarco2_horizontal, sf::Sprite spriteBarco2_vertical) {


	float x, y;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (matrizArmazem[i][j] != Agua) {


						x = i * dim;
						y = j * dim;

						spriteBarco2_horizontal.setPosition(x, y);

						janela.draw(spriteBarco2_horizontal);
					}
				}
			}
	return 0;
}
/*
 int a, b;

 for (int i = 0; i < 10; i++) {
 for (int j = 0; j < 10; j++) {

 if (matrizArmazem[i][j] != Agua) { // PROCURA A ORIGEM DO BARCO

 if (matriz[i + 1][j] != Agua) {	//SE SIM, É PQ O BARCO TA NA VERTICAL
 if (matriz[i][j] >= 1 && matriz[i][j] <= 4) {

 a = i * dim;
 b = j * dim;

 spriteBarco2_horizontal.setPosition(a, b);

 janela.draw(spriteBarco2_horizontal);

 printf("barco 2 V\n");
 }
 if (matriz[i][j] >= 5 && matriz[i][j] <= 7) {
 printf("barco 3 V\n");
 }
 if (matriz[i][j] == 8 || matriz[i][j] == 9) {
 printf("barco 4 V\n");
 }
 if (matriz[i][j] == 10) {
 printf("barco 5 V\n");
 }
 }

 if (matriz[i][j + 1] != Agua) { //SE SIM, É PQ O BARCO TÁ NA HORIZONTAL

 if (matriz[i][j] >= 1 && matriz[i][j] <= 4) {
 printf("barco 2 H\n");
 }
 if (matriz[i][j] >= 5 && matriz[i][j] <= 7) {
 printf("barco 3 H\n");
 }
 if (matriz[i][j] == 8 || matriz[i][j] == 9) {
 printf("barco 4 H\n");
 }
 if (matriz[i][j] == 10) {
 printf("barco 5 H\n");
 }
 }

 }

 }
 }
 */
void barco5(int *direcao, Celulas matriz[10][10], Celulas matrizArmazem[10][10],
		sf::RenderWindow &janela, int dim, sf::Sprite spriteEstrela) {
	int X, Y;
	int count = 0;
	int quebraLoop = 0;

	while (count != 1 && quebraLoop <= 15) {

		X = rand() % 10;
		Y = rand() % 10;

		quebraLoop++;
		if (quebraLoop == 15) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = Agua;
					matrizArmazem[i][j] = Agua;
				}
			}
		}
		while (X == 9 && Y == 9) {

			X = rand() % 10;
			Y = rand() % 10;

		}

		//esse teste proibe que o inicio de um barco seja na posição [9][9] da matriz
		defineDirecao(direcao);

		if (*direcao == 1) {

			if (matriz[X][Y] == Agua && matriz[X + 1][Y] == Agua
					&& matriz[X + 2][Y] == Agua && matriz[X + 3][Y] == Agua
					&& matriz[X + 4][Y] == Agua) { //testa se as posições do barco estão livres

				if (matriz[X - 1][Y] == Agua) {

					if (X + 5 <= 9) {
						if (matriz[X + 5][Y] == Agua) {

							if (matriz[X - 1][Y + 1] == Agua
									&& matriz[X][Y + 1] == Agua
									&& matriz[X + 1][Y + 1] == Agua
									&& matriz[X + 2][Y + 1] == Agua
									&& matriz[X + 3][Y + 1] == Agua
									&& matriz[X + 4][Y + 1] == Agua
									&& matriz[X + 5][Y + 1] == Agua) {

								if (matriz[X - 1][Y - 1] == Agua
										&& matriz[X][Y - 1] == Agua
										&& matriz[X + 1][Y - 1] == Agua
										&& matriz[X + 2][Y - 1] == Agua
										&& matriz[X + 3][Y - 1] == Agua
										&& matriz[X + 4][Y - 1] == Agua
										&& matriz[X + 5][Y - 1] == Agua) {

									matrizArmazem[X][Y] = Barco10;

									matriz[X][Y] = Barco10;
									matriz[X + 1][Y] = Barco10;
									matriz[X + 2][Y] = Barco10;
									matriz[X + 3][Y] = Barco10;
									matriz[X + 4][Y] = Barco10;

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}

		if (*direcao == 2) {

			if (matriz[X][Y] == Agua && matriz[X][Y + 1] == Agua
					&& matriz[X][Y + 2] == Agua && matriz[X][Y + 3] == Agua
					&& matriz[X][Y + 4] == Agua) { //testa se as posições do barco estão livres
					//printf("5\n");

				if (matriz[X][Y - 1] == Agua) {

					if (Y + 5 <= 9) {
						if (matriz[X][Y + 5] == Agua) {

							if (matriz[X + 1][Y - 1] == Agua
									&& matriz[X + 1][Y] == Agua
									&& matriz[X + 1][Y + 1] == Agua
									&& matriz[X + 1][Y + 2] == Agua
									&& matriz[X + 1][Y + 3] == Agua
									&& matriz[X + 1][Y + 4] == Agua
									&& matriz[X + 1][Y + 5] == Agua) {

								if (matriz[X - 1][Y - 1] == Agua
										&& matriz[X - 1][Y] == Agua
										&& matriz[X - 1][Y + 1] == Agua
										&& matriz[X - 1][Y + 2] == Agua
										&& matriz[X - 1][Y + 3] == Agua
										&& matriz[X - 1][Y + 4] == Agua
										&& matriz[X - 1][Y + 5] == Agua) {

									matrizArmazem[X][Y] = Barco10;

									matriz[X][Y] = Barco10;
									matriz[X][Y + 1] = Barco10;
									matriz[X][Y + 2] = Barco10;
									matriz[X][Y + 3] = Barco10;
									matriz[X][Y + 4] = Barco10;

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}
	}
}
void barco4(int *direcao, Celulas matriz[10][10], Celulas matrizArmazem[10][10],
		sf::RenderWindow &janela, int dim, sf::Sprite spriteEstrela) {
	int X, Y;
	int count = 0;
	int quebraLoop = 0;

	while (count != 2 && quebraLoop <= 15) {

		X = rand() % 10;
		Y = rand() % 10;
		quebraLoop++;

		if (quebraLoop == 15) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = Agua;
					matrizArmazem[i][j] = Agua;
				}
			}
		}
		while (X == 9 && Y == 9) {

			X = rand() % 10;
			Y = rand() % 10;

		}

		//esse teste proibe que o inicio de um barco seja na posição [9][9] da matriz
		defineDirecao(direcao);

		if (*direcao == 1) {

			if (matriz[X][Y] == Agua && matriz[X + 1][Y] == Agua
					&& matriz[X + 2][Y] == Agua && matriz[X + 3][Y] == Agua) { //testa se as posições do barco estão livres

				if (matriz[X - 1][Y] == Agua) {

					if (X + 4 <= 9) {
						if (matriz[X + 4][Y] == Agua) {

							if (matriz[X - 1][Y + 1] == Agua
									&& matriz[X][Y + 1] == Agua
									&& matriz[X + 1][Y + 1] == Agua
									&& matriz[X + 2][Y + 1] == Agua
									&& matriz[X + 3][Y + 1] == Agua
									&& matriz[X + 4][Y + 1] == Agua) {

								if (matriz[X - 1][Y - 1] == Agua
										&& matriz[X][Y - 1] == Agua
										&& matriz[X + 1][Y - 1] == Agua
										&& matriz[X + 2][Y - 1] == Agua
										&& matriz[X + 3][Y - 1] == Agua
										&& matriz[X + 4][Y - 1] == Agua) {
									switch (count) {

									case 0:

										matrizArmazem[X][Y] = Barco8;

										matriz[X][Y] = Barco8;
										matriz[X + 1][Y] = Barco8;
										matriz[X + 2][Y] = Barco8;
										matriz[X + 3][Y] = Barco8;
										break;

									case 1:

										matrizArmazem[X][Y] = Barco9;

										matriz[X][Y] = Barco9;
										matriz[X + 1][Y] = Barco9;
										matriz[X + 2][Y] = Barco9;
										matriz[X + 3][Y] = Barco9;
										break;

									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}

		if (*direcao == 2) {

			if (matriz[X][Y] == Agua && matriz[X][Y + 1] == Agua
					&& matriz[X][Y + 2] == Agua && matriz[X][Y + 3] == Agua) { //testa se as posições do barco estão livres

				if (matriz[X][Y - 1] == Agua) {

					if (Y + 4 <= 9) {
						if (matriz[X][Y + 4] == Agua) {

							if (matriz[X + 1][Y - 1] == Agua
									&& matriz[X + 1][Y] == Agua
									&& matriz[X + 1][Y + 1] == Agua
									&& matriz[X + 1][Y + 2] == Agua
									&& matriz[X + 1][Y + 3] == Agua
									&& matriz[X + 1][Y + 4] == Agua) {

								if (matriz[X - 1][Y - 1] == Agua
										&& matriz[X - 1][Y] == Agua
										&& matriz[X - 1][Y + 1] == Agua
										&& matriz[X - 1][Y + 2] == Agua
										&& matriz[X - 1][Y + 3] == Agua
										&& matriz[X - 1][Y + 4] == Agua) {

									switch (count) {

									case 0:

										matrizArmazem[X][Y] = Barco8;

										matriz[X][Y] = Barco8;
										matriz[X][Y + 1] = Barco8;
										matriz[X][Y + 2] = Barco8;
										matriz[X][Y + 3] = Barco8;
										break;

									case 1:

										matrizArmazem[X][Y] = Barco9;

										matriz[X][Y] = Barco9;
										matriz[X][Y + 1] = Barco9;
										matriz[X][Y + 2] = Barco9;
										matriz[X][Y + 3] = Barco9;
										break;
									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}
	}
}

void barco3(int *direcao, Celulas matriz[10][10], Celulas matrizArmazem[10][10],
		sf::RenderWindow &janela, int dim, sf::Sprite spriteEstrela) {
	int X, Y;
	int count = 0;
	int quebraLoop = 0;

	while (count != 3 && quebraLoop <= 15) {

		X = rand() % 10;
		Y = rand() % 10;

		quebraLoop++;
		printf("quebraLoop = %d\n", quebraLoop);
		if (quebraLoop == 15) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = Agua;
					matrizArmazem[i][j] = Agua;
				}
			}
		}
		while (X == 9 && Y == 9) {

			X = rand() % 10;
			Y = rand() % 10;

		}

		//esse teste proibe que o inicio de um barco seja na posição [9][9] da matriz
		defineDirecao(direcao);

		if (*direcao == 1) {

			if (matriz[X][Y] == Agua && matriz[X + 1][Y] == Agua
					&& matriz[X + 2][Y] == Agua) { //testa se as posições do barco estão livres

				if (matriz[X - 1][Y] == Agua) {

					if (X + 3 <= 9) {
						if (matriz[X + 3][Y] == Agua) {

							if (matriz[X - 1][Y + 1] == Agua
									&& matriz[X][Y + 1] == Agua
									&& matriz[X + 1][Y + 1] == Agua
									&& matriz[X + 2][Y + 1] == Agua
									&& matriz[X + 3][Y + 1] == Agua) {

								if (matriz[X - 1][Y - 1] == Agua
										&& matriz[X][Y - 1] == Agua
										&& matriz[X + 1][Y - 1] == Agua
										&& matriz[X + 2][Y - 1] == Agua
										&& matriz[X + 3][Y - 1] == Agua) {

									switch (count) {

									case 0:

										matrizArmazem[X][Y] = Barco5;

										matriz[X][Y] = Barco5;
										matriz[X + 1][Y] = Barco5;
										matriz[X + 2][Y] = Barco5;
										break;

									case 1:

										matrizArmazem[X][Y] = Barco6;

										matriz[X][Y] = Barco6;
										matriz[X + 1][Y] = Barco6;
										matriz[X + 2][Y] = Barco6;
										break;

									case 2:

										matrizArmazem[X][Y] = Barco7;

										matriz[X][Y] = Barco7;
										matriz[X + 1][Y] = Barco7;
										matriz[X + 2][Y] = Barco7;
										break;
									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}

		if (*direcao == 2) {

			if (matriz[X][Y] == Agua && matriz[X][Y + 1] == Agua
					&& matriz[X][Y + 2] == Agua) { //testa se as posições do barco estão livres

				if (matriz[X][Y - 1] == Agua) {

					if (Y + 3 <= 9) {
						if (matriz[X][Y + 3] == Agua) {

							if (matriz[X + 1][Y - 1] == Agua
									&& matriz[X + 1][Y] == Agua
									&& matriz[X + 1][Y + 1] == Agua
									&& matriz[X + 1][Y + 2] == Agua
									&& matriz[X + 1][Y + 3] == Agua) {

								if (matriz[X - 1][Y - 1] == Agua
										&& matriz[X - 1][Y] == Agua
										&& matriz[X - 1][Y + 1] == Agua
										&& matriz[X - 1][Y + 2] == Agua
										&& matriz[X - 1][Y + 3] == Agua) {
									switch (count) {

									case 0:

										matrizArmazem[X][Y] = Barco5;

										matriz[X][Y] = Barco5;
										matriz[X][Y + 1] = Barco5;
										matriz[X][Y + 2] = Barco5;
										break;

									case 1:

										matrizArmazem[X][Y] = Barco6;

										matriz[X][Y] = Barco6;
										matriz[X][Y + 1] = Barco6;
										matriz[X][Y + 2] = Barco6;
										break;

									case 2:

										matrizArmazem[X][Y] = Barco7;

										matriz[X][Y] = Barco7;
										matriz[X][Y + 1] = Barco7;
										matriz[X][Y + 2] = Barco7;
										break;
									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}
	}
}

void barco2(int *direcao, Celulas matriz[10][10], Celulas matrizArmazem[10][10],
		sf::RenderWindow &janela, int dim, sf::Sprite spriteEstrela) {
	int X, Y;
	int count = 0;
	int quebraLoop = 0;

	while (count != 4 && quebraLoop <= 15) {

		X = rand() % 10;
		Y = rand() % 10;

		quebraLoop++;
		if (quebraLoop == 15) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = Agua;
					matrizArmazem[i][j] = Agua;
				}
			}
		}
		//esse teste proibe que o inicio de um barco seja na posição [9][9] da matriz
		while (X == 9 && Y == 9) {

			X = rand() % 10;
			Y = rand() % 10;

		}

		defineDirecao(direcao);
		*direcao = 1;
		if (*direcao == 1) {

			if (matriz[X][Y] == Agua && matriz[X + 1][Y] == Agua) { //testa se as posições do barco estão livres

				if (matriz[X - 1][Y] == Agua) {

					if (X + 2 <= 9) {
						if (matriz[X + 2][Y] == Agua) {

							if (matriz[X - 1][Y + 1] == Agua
									&& matriz[X][Y + 1] == Agua
									&& matriz[X + 1][Y + 1] == Agua
									&& matriz[X + 2][Y + 1] == Agua) {

								if (matriz[X - 1][Y - 1] == Agua
										&& matriz[X][Y - 1] == Agua
										&& matriz[X + 1][Y - 1] == Agua
										&& matriz[X + 2][Y - 1] == Agua) {

									switch (count) {

									case 0:

										matrizArmazem[X][Y] = Barco1;

										matriz[X][Y] = Barco1;
										matriz[X + 1][Y] = Barco1;
										break;

									case 1:

										matrizArmazem[X][Y] = Barco2;

										matriz[X][Y] = Barco2;
										matriz[X + 1][Y] = Barco2;
										break;

									case 2:

										matrizArmazem[X][Y] = Barco3;

										matriz[X][Y] = Barco3;
										matriz[X + 1][Y] = Barco3;
										break;

									case 3:

										matrizArmazem[X][Y] = Barco4;

										matriz[X][Y] = Barco4;
										matriz[X + 1][Y] = Barco4;
										break;
									}

									quebraLoop = 0;
									count++;

								}
							}
						}
					}
				}
			}
		}

		if (*direcao == 2) {

			if (matriz[X][Y] == Agua && matriz[X][Y + 1] == Agua) { //testa se as posições do barco estão livres

				if (matriz[X][Y - 1] == Agua) {

					if (Y + 2 <= 9) {
						if (matriz[X][Y + 2] == Agua) {

							if (matriz[X + 1][Y - 1] == Agua
									&& matriz[X + 1][Y] == Agua
									&& matriz[X + 1][Y + 1] == Agua
									&& matriz[X + 1][Y + 2] == Agua) {

								if (matriz[X - 1][Y - 1] == Agua
										&& matriz[X - 1][Y] == Agua
										&& matriz[X - 1][Y + 1] == Agua
										&& matriz[X - 1][Y + 2] == Agua) {

									switch (count) {

									case 0:

										matrizArmazem[X][Y] = Barco1;

										matriz[X][Y] = Barco1;
										matriz[X][Y + 1] = Barco1;
										break;

									case 1:

										matrizArmazem[X][Y] = Barco2;

										matriz[X][Y] = Barco2;
										matriz[X][Y + 1] = Barco2;
										break;

									case 2:

										matrizArmazem[X][Y] = Barco3;

										matriz[X][Y] = Barco3;
										matriz[X][Y + 1] = Barco3;
										break;

									case 3:

										matrizArmazem[X][Y] = Barco4;

										matriz[X][Y] = Barco4;
										matriz[X][Y + 1] = Barco4;
										break;
									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}
	}
}

//sf no geral significa uma variavel do SFML
sf::RectangleShape criaRetangulo(int x, int y, int width, int height) {

	sf::RectangleShape retangulo(sf::Vector2f(width, height));

	retangulo.setFillColor(sf::Color::Blue);
	retangulo.setOutlineColor(sf::Color::White);
	retangulo.setOutlineThickness(1);
	retangulo.setPosition(x, y);

	return retangulo;
}

//loop de eventos
void loopEventos(sf::RenderWindow *janela, Celulas matriz[10][10],
		sf::Sound *somEstrela, int dim) {

	//trata das interações
	sf::Event eventos;

	while ((*janela).pollEvent(eventos)) {
		if (eventos.type == sf::Event::Closed) {
			(*janela).close();
		}

		if (eventos.type == sf::Event::MouseButtonPressed) {
			int linha = sf::Mouse::getPosition(*janela).x / dim;
			int coluna = sf::Mouse::getPosition(*janela).y / dim;
			if (matriz[linha][coluna] == Agua) {
				(*somEstrela).play();
			}
		}
	}
}

void desenhaRetangulo(sf::RenderWindow &janela,
		sf::RectangleShape tabela[10][10], float x, float y) {

	sf::Color cor;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (tabela[i][j].getGlobalBounds().contains(x, y)) {
				cor = sf::Color::Green;
			} else {
				cor = sf::Color { 38, 182, 255, 255 };
			}
			tabela[i][j].setFillColor(cor);

			janela.draw(tabela[i][j]);
		}
	}
}

int main() {

	srand(time(NULL));

	int direcao = 0;
	int dim = 50;
	int largura = 500;
	int altura = 500;

	int qntBarco = 0;

	float tamanho = 0;

	sf::RenderWindow janela(sf::VideoMode(largura, altura),
			"VOCÊ CONSEGUE OTTO, NÃO DESISTE!!",
			sf::Style::Close | sf::Style::Titlebar); //trava a tela assim, n pode maximizar
	janela.setFramerateLimit(60);
	janela.setVerticalSyncEnabled(true);

	sf::RectangleShape tabela[10][10];

	Celulas matriz[10][10];
	Celulas matrizArmazem[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tabela[i][j] = criaRetangulo(i * dim, j * dim, dim, dim);
			matriz[i][j] = Agua;
			matrizArmazem[i][j] = Agua;
		}
	}
	sf::Texture texturaBarco2_horizontal;
	sf::Sprite spriteBarco2_horizontal;

	texturaBarco2_horizontal.loadFromFile("assets/barco2_horizontal.png");
	texturaBarco2_horizontal.setSmooth(true);

	//mexendos na sprite
	spriteBarco2_horizontal.setTextureRect(sf::IntRect(0, 0, 50, 50));
	spriteBarco2_horizontal.setTexture(texturaBarco2_horizontal, true);

	tamanho = (float) 50 / texturaBarco2_horizontal.getSize().x;
	printf("tamanho = %f\n", tamanho);
	spriteBarco2_horizontal.setScale(tamanho, tamanho);


	sf::Texture texturaBarco2_vertical;
	sf::Sprite spriteBarco2_vertical;

	texturaBarco2_vertical.loadFromFile("assets/barco2_vertical.png");
	texturaBarco2_vertical.setSmooth(true);

	//mexendos na sprite
	spriteBarco2_vertical.setTextureRect(sf::IntRect(0, 0, 50, 50));
	spriteBarco2_vertical.setTexture(texturaBarco2_vertical, true);

	tamanho = (float) 50 / texturaBarco2_vertical.getSize().x;
	printf("tamanho = %f\n", tamanho);
	spriteBarco2_vertical.setScale(tamanho, tamanho);


	sf::Texture texturaBarco3_horizontal;
	sf::Sprite spriteBarco3_horizontal;

	sf::Texture texturaBarco3_vertical;
	sf::Sprite spriteBarco3_vertical;

	sf::Texture texturaBarco4_horizontal;
	sf::Sprite spriteBarco4_horizontal;

	sf::Texture texturaBarco4_vertical;
	sf::Sprite spriteBarco4_vertical;

	sf::Texture texturaBarco5_horizontal;
	sf::Sprite spriteBarco5_horizontal;

	sf::Texture texturaBarco5_vertical;
	sf::Sprite spriteBarco5_vertical;

	sf::Texture texturaBomba;
	sf::Sprite spriteBomba;

	//mexendo na textura
	texturaBomba.loadFromFile("assets/barco2_horizontal.png");
	texturaBomba.setSmooth(true);

	//mexendos na sprite
	spriteBomba.setTextureRect(sf::IntRect(0, 0, 50, 50));
	spriteBomba.setTexture(texturaBomba, true);

	tamanho = (float) 50 / texturaBomba.getSize().x;
	printf("tamanho = %f\n", tamanho);
	spriteBomba.setScale(tamanho, tamanho);

	//som da estrelinha
	sf::SoundBuffer estrelaBuffer; //"textura"
	sf::Sound somEstrela;		  //"sprite"

	estrelaBuffer.loadFromFile("assets/bomb.wav");
	somEstrela.setBuffer(estrelaBuffer);

	//mexendos na sprite
	spriteBomba.setTextureRect(sf::IntRect(0, 0, 50, 50));
	spriteBomba.setTexture(texturaBomba, true);

	printf("matriz:\n");
	for (int i = 0; i < 10; i++) {
		printf("\n");
		for (int j = 0; j < 10; j++) {
			printf("%d\t", matriz[i][j]);
		}
	}
	printf("\nmatrizArmazem:\n");
	for (int i = 0; i < 10; i++) {
		printf("\n");
		for (int j = 0; j < 10; j++) {
			printf("%d\t", matrizArmazem[i][j]);
		}
	}
	//Loop do Jogo

	while (janela.isOpen()) {

		while (qntBarco != 8 + 9 + 8 + 5) {
			qntBarco = 0;

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = Agua;
					matrizArmazem[i][j] = Agua;
				}
			}

			barco5(&direcao, matriz, matrizArmazem, janela, dim, spriteBomba);
			printf("barco 5 ok\n");

			barco4(&direcao, matriz, matrizArmazem, janela, dim, spriteBomba);
			printf("barco 4 ok\n");

			barco3(&direcao, matriz, matrizArmazem, janela, dim, spriteBomba);
			printf("barco 3 ok\n");

			barco2(&direcao, matriz, matrizArmazem, janela, dim, spriteBomba);
			printf("barco 2 ok\n");

			for (int i = 0; i < 10; i++) {
				printf("\n");
				for (int j = 0; j < 10; j++) {
					printf("%d\t", matriz[i][j]);
				}
			}

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (matriz[i][j] != Agua) {

						qntBarco++;
						printf("qntdBarco = %d\n", qntBarco);

					}
				}
			}
		}
		for (int i = 0; i < 10; i++) {
						printf("\n");
						for (int j = 0; j < 10; j++) {
							printf("%d\t", matriz[i][j]);
						}
					}
		printf("\n");
		/*
		 sf::Texture texturaBarco2_horizontal;
		 sf::Sprite spriteBarco2_horizontal;

		 texturaBarco2_horizontal.loadFromFile("assets/barco.png");

		 sf::Texture texturaBarco2_vertical;
		 sf::Sprite spriteBarco2_vertical;

		 sf::Texture texturaBarco3_horizontal;
		 sf::Sprite spriteBarco3_horizontal;

		 sf::Texture texturaBarco3_vertical;
		 sf::Sprite spriteBarco3_vertical;

		 sf::Texture texturaBarco4_horizontal;
		 sf::Sprite spriteBarco4_horizontal;

		 sf::Texture texturaBarco4_vertical;
		 sf::Sprite spriteBarco4_vertical;

		 sf::Texture texturaBarco5_horizontal;
		 sf::Sprite spriteBarco5_horizontal;

		 sf::Texture texturaBarco5_vertical;
		 sf::Sprite spriteBarco5_vertical;
		 */

		/*
		 int a, b;

		 for (int i = 0; i < 10; i++) {
		 for (int j = 0; j < 10; j++) {

		 if (matrizArmazem[i][j] != Agua) { // PROCURA A ORIGEM DO BARCO

		 if (matriz[i + 1][j] != Agua) {	//SE SIM, É PQ O BARCO TA NA VERTICAL
		 if (matriz[i][j] >= 1 && matriz[i][j] <= 4) {

		 a = i * dim;
		 b = j * dim;

		 spriteBarco2_horizontal.setPosition(a, b);

		 janela.draw(spriteBarco2_horizontal);

		 printf("barco 2 V\n");
		 }
		 if (matriz[i][j] >= 5 && matriz[i][j] <= 7) {
		 printf("barco 3 V\n");
		 }
		 if (matriz[i][j] == 8 || matriz[i][j] == 9) {
		 printf("barco 4 V\n");
		 }
		 if (matriz[i][j] == 10) {
		 printf("barco 5 V\n");
		 }
		 }

		 if (matriz[i][j + 1] != Agua) { //SE SIM, É PQ O BARCO TÁ NA HORIZONTAL

		 if (matriz[i][j] >= 1 && matriz[i][j] <= 4) {
		 printf("barco 2 H\n");
		 }
		 if (matriz[i][j] >= 5 && matriz[i][j] <= 7) {
		 printf("barco 3 H\n");
		 }
		 if (matriz[i][j] == 8 || matriz[i][j] == 9) {
		 printf("barco 4 H\n");
		 }
		 if (matriz[i][j] == 10) {
		 printf("barco 5 H\n");
		 }
		 }

		 }

		 }
		 }
		 */

		//defineBomba(janela, matriz, dim, Estrela);
		loopEventos(&janela, matriz, &somEstrela, dim);

		float horizontal = sf::Mouse::getPosition(janela).x;
		float vertical = sf::Mouse::getPosition(janela).y;

		janela.clear(sf::Color::White); //limpa o cmd pra que nao tenha nada antes de desenhar

		//função que vai desenhar os qaudrados, trocando cores dependendo do mouse
		desenhaRetangulo(janela, tabela, horizontal, vertical);

		desenhaBomba(janela, matriz, matrizArmazem, dim,
				spriteBarco2_horizontal, spriteBarco2_vertical);

		janela.display(); //mostra tudo na tela
		sf::sleep(sf::microseconds(50.0f));
	}

	return 0;

}

/*

 sf::Sprite spawnRaindrop(sf::Texture &texture) {
 sf::Sprite raindrop(texture);
 int x = rand() % (800 - 64);
 x = x > 32 ? x : 32;
 int y = -32;
 raindrop.setPosition(x, y);
 raindrop.setOrigin(raindrop.getLocalBounds().width / 2.,
 raindrop.getLocalBounds().height / 2.);
 return raindrop;
 }

 int main() {
 //////////////////////Inicializa Objetos do Jogo//////////////////////
 srand(time(NULL));
 setbuf(stdout, NULL);

 sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!",
 sf::Style::Close | sf::Style::Titlebar);
 // Op��es de abertura da janela: sf::Style::Close + sf::Style::Titlebar + sf::Style::Resize

 //Declara vari�vieis para SFML
 sf::Texture textureFundo;
 sf::Sprite fundoImage;

 sf::Texture textureDropImage;
 sf::Sprite dropImage;

 sf::Texture texturebucketImage;
 sf::Sprite bucketImage;

 sf::SoundBuffer bufferDropSound;
 sf::Sound dropSound;

 sf::SoundBuffer bufferOver;
 sf::Sound overSound;

 sf::Music rainMusic;

 sf::Font font;

 //Declara vari�vieis para o jogo
 int pontos = 0;
 int vidas = 5;

 int velBucketX = 0;
 int velBucketY = 0;
 int velDrop = 5;

 bool pausado = false;

 //Inicializa as vari�vies.


 window.setFramerateLimit(60); // Limita os frames
 window.setVerticalSyncEnabled(true);//limita a sincroniza��o

 //Icone da janela.
 sf::Image image = sf::Image { };
 image.loadFromFile("assets/cogumelo.png");
 window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

 // load the images for the droplet and the bucket, 64x64 pixels each
 textureFundo.loadFromFile("assets/fundo.png");
 textureDropImage.loadFromFile("assets/droplet.png");
 texturebucketImage.loadFromFile("assets/bucket.png");

 fundoImage.setTexture(textureFundo);
 bucketImage.setTexture(texturebucketImage);
 bucketImage.setOrigin(bucketImage.getLocalBounds().width / 2.,
 bucketImage.getLocalBounds().height / 2.);
 bucketImage.setPosition(400, 550);

 bufferDropSound.loadFromFile("assets/drop.wav");
 dropSound.setBuffer(bufferDropSound);

 bufferOver.loadFromFile("assets/Sonic-Game-Over.ogg");
 overSound.setBuffer(bufferOver);

 rainMusic.openFromFile("assets/rain.ogg");
 // start the playback of the background music immediately
 rainMusic.setLoop(true);
 rainMusic.play();

 font.loadFromFile("assets/x-files.ttf");

 sf::Text txtVidas("Vidas:\t5", font, 24);
 sf::Text txtPontos("Pontos:\t0", font, 24);
 sf::Text txtGameOver("", font, 96);

 txtPontos.setColor(sf::Color::Blue);
 txtVidas.setColor(sf::Color::Red);

 txtVidas.setPosition(600, 10);
 txtPontos.setPosition(600, 40);

 // a fun��o cria a gota de chuva como um sprite.
 dropImage = spawnRaindrop(textureDropImage);

 //////////////////////Loop do jogo//////////////////////
 while (window.isOpen()) {
 sf::Event event;
 velBucketX = 0;
 //Trata as intera��es.
 while (window.pollEvent(event)) {
 if (event.type == sf::Event::Closed)
 window.close();
 if (event.type == sf::Event::EventType::KeyPressed) { //Tecla pressionada.
 if (event.key.code == sf::Keyboard::Space) {
 pausado = !pausado; // Inverte pausa ou despausa.
 }
 }

 if (event.type == sf::Event::EventType::KeyReleased) { //Tecla Solta.

 }
 if (event.type == sf::Event::MouseButtonPressed) {
 int x = sf::Mouse::getPosition(window).x;
 bucketImage.setPosition(x, bucketImage.getPosition().y);
 }
 } //Fim do loop de eventos.

 //Verifica teclas individualmente independente do loop de eventos.
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
 velBucketX = -5;
 }
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
 velBucketX = 5;
 }

 //////////////////////Atualiza o mundo//////////////////////
 if (!pausado) { //Pausa a atualiza��o do mundo (barra de espa�o)

 //Move objetos.
 bucketImage.setPosition(bucketImage.getPosition().x + velBucketX,
 bucketImage.getPosition().y + velBucketY);

 dropImage.setPosition(dropImage.getPosition().x,
 dropImage.getPosition().y + velDrop);

 if (dropImage.getPosition().y > 600 + 64) {
 dropImage = spawnRaindrop(textureDropImage);
 vidas--;
 char str[5];
 sprintf(str, "Vidas:\t%d", vidas);
 txtVidas.setString(str);
 }

 //////////////////////Testa colis�es //////////////////////
 if (bucketImage.getGlobalBounds().intersects(
 dropImage.getGlobalBounds())) {
 pontos++;
 dropSound.play();
 char str[5];
 sprintf(str, "Pontos:\t%d", pontos);
 txtPontos.setString(str);
 dropImage = spawnRaindrop(textureDropImage);
 }

 //Verifica o fim do jogo.
 if (vidas == 0) {
 overSound.play(); //Se a condi��o n�o mudar (vidas==0) isso �
 //chamado 60 vezes por segundo.
 //Se n�o puder mudar a condi��o use um clock
 //dar um tempo entre uma chamada e outra.
 rainMusic.pause();
 velDrop = 0;
 dropImage.setPosition(dropImage.getPosition().x, 0 - 64);
 txtGameOver.setString("Game Over!");
 sf::FloatRect bounds(txtGameOver.getLocalBounds());
 txtGameOver.setPosition(
 window.getSize().x / 2
 - (bounds.left + bounds.width / 2),
 window.getSize().y / 2
 - (bounds.top + bounds.height / 2));
 vidas = -1;
 }

 } // Fim do bloco de pause

 //////////////////////Pinta o mundo//////////////////////

 window.clear(sf::Color::White);
 window.draw(fundoImage); 	// Desenha backgroud
 window.draw(bucketImage);	// Desenha Balde
 window.draw(dropImage);		// Desenha gota de chuva
 window.draw(txtPontos);		// Desenha potua��o
 window.draw(txtVidas);		// Desenha vidas
 window.draw(txtGameOver);	// Desenha gameOver
 window.display();		 	// Mostra na tela.
 sf::sleep(sf::milliseconds(10.0f));

 } //Fim do loop do jogo (janela aberta).

 return 0;
 }


 */
