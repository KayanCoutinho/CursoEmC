#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanhomatriz 3

using namespace std;

int pesos () { // Criar uma matriz randômica.

	srand(time(NULL));
	int l, c;
	int m [tamanhomatriz][tamanhomatriz];	
	
		for (l = 0; l < tamanhomatriz; l++) { // Executa 1
			for (c = 0; c < tamanhomatriz; c++) { // Executa 2
				m [l][c] = rand() % 100; // Executa 3 e assim em diante.
				//cout << m [l][c] << " ";
			}
			//cout << endl;
		}
		
		//cout << endl;
}

int somarmatriz (int A[tamanhomatriz][tamanhomatriz], int B[tamanhomatriz][tamanhomatriz]) { // Somar duas matrizes.

	int i, j, M;
	
	for(i=0; i<tamanhomatriz; i++) {
		for(j=0; j<tamanhomatriz; j++) {
			M[i][j] = A[i][j] + B[i][j];
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main () {
	
	
	
}