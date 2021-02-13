#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	// imprime cabeçalho do jogo
	printf("******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
	printf("******************************************\n");
	printf("* Voce tem que adivinhar o numero secreto \n");
	printf("* que esta entre 0 e 100 *****************\n\n");

	int chute;
	int tentativas = 1;
	double pontos = 1000.00;
	int segundos = time(0);
	srand(segundos);
	int numero = rand();
	int numerosecreto = numero % 100;
	int chances;
	int acertou;
	int maior;
	int nivel;

	printf("Escolha o nivel de dificuldade: \n");
	printf("(1)->Easy (2)->Normal (3)->Hard \n");
	printf("Your chose: \n");
	scanf("%d", &nivel);

	switch (nivel) {
		case 1:
			chances = 20;
			break;
		case 2:
			chances = 10;
			break;
		default:
			chances = 5;
			break;
	}

	for (int i = 1; i <= chances; i++) {
	printf("Tentativa %d \n", tentativas);
	printf("Qual e o seu chute? \n");
	scanf("%d", &chute);
	printf("Seu chute foi %d \n", chute);

	if (chute < 0) {
		printf("Voce nao pode chutar numeros negativos \n");
		continue;
	}

	acertou = (chute == numerosecreto);
	maior = chute > numerosecreto;

	if (acertou) {
		break;
	}
	else if (maior) {
		printf("Seu chute foi maior que o numero secreto \n");
	}
	else {
		printf("Seu chute foi menor que o numero secreto \n");
	}
	tentativas++;
	double pontosperdidos = abs(chute - numerosecreto) / (double)2;
	pontos = pontos - pontosperdidos;		
	}

	if (acertou) {
		printf("Parabens voce ganhou !!! \n");
		printf("Voce ganhou em %d tentativas \n", tentativas);
		printf("Voce marcou: %.2f pontos \n", pontos);
	}
	else {
		printf("You lose otario !!! \n");
	}
}