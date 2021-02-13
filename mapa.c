#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void copiamapa(MAPA* destino, MAPA* origem) {

	destino->linhas = origem->linhas;
	destino->colunas = origem->colunas;

	alocamapa(destino);

	for (int i = 0; i < origem->linhas; i++) {
		
		strcpy(destino->matriz[i], origem->matriz[i]); //Copia uma string para outra.
	}
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino) {

	char personagem = m->matriz[xorigem][yorigem];
	m->matriz[xdestino][ydestino] = personagem;
	m->matriz[xorigem][yorigem] = VAZIO;
}

int ehvalida(MAPA* m, int x, int y) {

	if (x >= m->linhas) {

		return 0;
	}

	if (y >= m->colunas) {

		return 0;
	}

	return 1;
}

int ehvazia(MAPA* m, int x, int y) {

	return m->matriz[x][y] == VAZIO;
}

int encontramapa(MAPA* m, POSICAO* p, char c) {

	for (int i = 0; i < m->linhas; i++) { //Acha a posição do fogefoge.
		for (int j = 0; j < m->colunas; j++) {
			if (m->matriz[i][j] == c) {
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}

	return 0;
}

int ehpersonagem(MAPA* m, char personagem, int x, int y) {

	return m->matriz[x][y] == personagem;
}

int ehparede(MAPA* m, int x, int y) {

	return m->matriz[x][y] == PAREDE_VERTICAL || m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int podeandar(MAPA* m, char personagem, int x, int y) {

	return ehvalida(m, x, y) && !ehparede(m, x, y) && !ehpersonagem(m, personagem, x, y);
}

void liberamapa(MAPA* m) {

	for (int i = 0; i < m->linhas; i++) { //O '->' indica onde o valor do ponteiro deve ser alocado.
		free(m->matriz[i]); //Libera o espaço alocado de cada linha.
	}

	free(m->matriz); //Libera o espaço do mapa.
}

void lermapa(MAPA* m) {

	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0) {
		printf("Ocorreu um erro.\n");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

	alocamapa(m);//Coloca o 'm' direto, pois ele já é um ponteiro.

	for (int i = 0; i < m->linhas; i++) {
		fscanf(f, "%s", m->matriz[i]);
	}

	fclose(f); //Nunca esquecer de fechar o arquivo que está aberto.
}

void alocamapa(MAPA* m) {

	m->matriz = malloc(sizeof(char*) * m->linhas); //Aloca espaço para o mapa.
	for (int i = 0; i < m->linhas; i++) {
		m->matriz[i] = malloc(sizeof(char) * m->colunas + 1); //Sizeof define o tamanho do espaço a ser alocado.
	}
}