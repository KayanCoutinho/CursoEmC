#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include "forca.h"

#define paua system("pause")
#define limpa system("cls")
#define qtdletras 50

using namespace std;

int main() {
    
    int opcao;
    SetConsoleTitle("Jogo da Forca");
    menu();
    cin >> opcao;
           
    return 0;
    
}

void menu(){

    system("color 0A");
    
    cout << "\t\t\t\tJogo "; Sleep(500);
    cout << "Da "; Sleep(500);
    cout << "Forca"; Sleep(500);
    
    cout << endl;
    cout << "\t\t\t\t 1 - Iniciar" << endl;
    cout << "\t\t\t\t 2 - Regras" << endl;
    cout << "\t\t\t\t 3 - Sair" << endl << endl;
    cout << "Opção ->";
}

void regras() {
	
	cout << "Essas são as regras do jogo: " << endl;
	exit(0);
		
}

void jogo() {


		
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