#include "pch.h"
#include "iostream"
#include "ctime"
using namespace std;
using namespace System;

void reservarMemoria(int* numeros, int tam) {
	for (int i = 0;i < tam;i++) {
		numeros[i] = rand() % 100 + 1;
	}
}

int ** crearmatriz(int fil, int col) {
	int** m = new int*[fil];
	for (int i = 0;i < fil;i++) {
		m[i] = new int[col];
	}
	return m;
}


void llenarMatriz(int** matriz, int fil, int col) {
	for (int i = 0;i < fil;i++) {
		for (int j = 0;j < col;j++) {
			*(*(matriz + i) + j) = rand() % 100 + 1;
		}
	}
}

void mostrarMatriz(int** matriz, int fil, int col) {
	for (int i = 0;i < fil;i++) {
		for (int j = 0;j < col;j++) {
			cout << *(*(matriz + i) + j) << " ";
		}
		cout << "\n";
	}
}


void mostrarArregloDinamico(int* numeros, int tam) {
	for (int i = 0;i < tam;i++) {
		cout << numeros[i] << " ";
	}
}

int main() {
	
	int tam = 12, fil=4, col=4;
	int* numeros;
	int** matriz = crearmatriz(fil, col);
	reservarMemoria(numeros, tam);
	mostrarArregloDinamico(numeros, tam);
	cout << "\n\n\n";
	llenarMatriz(matriz, fil, col);
	mostrarMatriz(matriz, fil, col);

	for (int i = 0;i < fil;i++) {
		delete[]matriz[i];
	}

	delete[]matriz;
	delete[]numeros;

	system("pause>0");
	return 0;
}