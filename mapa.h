#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define VAZIO '.'
#define PAREDE_HORIZONTAL '-'
#define PAREDE_VERTICAL '|'
#define FANTASMA 'F'
#define PILULA 'P'

struct mapa { //Define um arranjo de comandos.
	char** matriz; //Ponteiro de ponteiro de char.
	int linhas;
	int colunas;
};

typedef struct mapa MAPA; //Permite atribuir um nome a struct.

struct posicao {

int x;
int y;
};

typedef struct posicao POSICAO;

void liberamapa(MAPA* m);
void lermapa(MAPA* m);
void alocamapa(MAPA* m);
int encontramapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int podeandar(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);

#endif