#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <stdlib.h>
#include <time.h>

char palavrasecreta[TAMPALAVRA];
char chutes[26];
int qtdchutes = 0;

int letraigual(char letra) {

	for (int j = 0; j < strlen(palavrasecreta); j++) {

		if (letra == palavrasecreta[j]) {
			
			return 1;
		} else {

		return 0;
		}	
	}
}

int chuteserrados() {

	int erros = 0;

	for (int i = 0; i < qtdchutes; i++) {

		if (!letraigual(chutes[i])) {

			erros++;
		}
	}
	return erros;
}

void addplavra() {

	char quer;

	printf("Voce quer adicionar uma nova palavra ao jogo ? (S/N)");
	scanf(" %c", &quer);

	if (quer == 'S') {

		char novapalavra[TAMPALAVRA];
		printf("Digite a nova palavra: \n");
		scanf("%s", novapalavra);
		FILE* f;
		f = fopen("palavras.txt", "r+");

		if (f == 0) {

			printf("Ocorreu um erro.");
			exit(1);
		}

		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;
		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);
		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);
		fclose(f);
		printf("Parabens! sua palavra foi adicinada com sucesso ! \n");
	} 

	printf("Fim de jogo ! \n");
}

void abertura() {
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta() {

	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);

	if (letraigual(chute) == 1) {

		printf("\nAcertou Mizeravi a palavra tem: %c \n\n", chute);
	} else {

		printf("\nSe fudeu !! A palavra nao tem a letra: %c \n\n", chute);
	}

	chutes[qtdchutes] = chute;
}

int jachutou(char letra) {
	int achou = 0;
	for(int j = 0; j < qtdchutes; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}

void desenhaforca() {

	printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", (chuteserrados() >= 1 ? '(' : ' '), (chuteserrados() >= 1 ? '_' : ' '), (chuteserrados() >= 1 ? ')' : ' '));
    printf(" |      %c%c%c \n", (chuteserrados() >= 2 ? '\\' : ' '), (chuteserrados() >= 2 ? '|' : ' '), (chuteserrados() >= 2 ? '/' : ' '));
    printf(" |       %c    \n", (chuteserrados() >= 3 ? '|' : ' '));
    printf(" |     %c%c %c%c\n", (chuteserrados() >= 4 ? '/' : ' '), (chuteserrados() >= 4 ? '(' : ' '), (chuteserrados() >= 4 ? ')' : ' '), (chuteserrados() >= 4 ? '\\' : ' '));
    printf(" |       %c    \n", (chuteserrados() >= 5 ? '|' : ' '));
    printf("_|___          \n");
    printf("\n\n");

	printf("Voce ja deu %d chutes\n", qtdchutes);

	for(int i = 0; i < strlen(palavrasecreta); i++) {

		if(jachutou(palavrasecreta[i])) {

			printf("%c", palavrasecreta[i]);

		} else {

			printf("_ ");

		}
	}

	printf("\n");

}

void escolhepalavra() {

	FILE* f;
	f = fopen("palavras.txt", "r");
	if (f==0) {

		printf("Ocorreu um erro.");
		exit(1);
	}

	int qtdpalavras;
	fscanf(f, "%d", &qtdpalavras);
	srand(time(0));
	int random = rand() % qtdpalavras;

	for (int i = 0; i <= random; i++) {

		fscanf (f, "%s", palavrasecreta);
	}

	fclose(f);
}

int enforcou() {

	return chuteserrados() >= 6;
}

int ganhou() {

	for (int i = 0; i < strlen(palavrasecreta); i++) {

		if (!jachutou(palavrasecreta[i])) {

			return 0;
		}
	}

	return 1;
}

int main() {

	abertura();
	escolhepalavra();

	do {

		desenhaforca();
		chuta();
		
		qtdchutes++;

	} while (!ganhou() && !enforcou());

	if (ganhou(1)) {

		printf("Parabens ! Voce venceu ! \n");

	} else {

		printf("Voce foi enforcado. Se fodeu ! \n");
	}

	addplavra();
}