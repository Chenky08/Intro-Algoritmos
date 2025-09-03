#include "pch.h"
#include "iostream"

using namespace std;
using namespace System;


short menu() {
	short op;
	cout << endl << "\t MENU";
	cout << endl << "1.- LISTAR ELEMENTOS ";
	cout << endl << "2.- AGREGAR AL FINAL ";
	cout << endl << "3.- AGREGAR AL INICIO ";
	cout << endl << "4.- ELIMINAR UN ELEMENTO ";
	cout << endl << "5.- SALIR";
	cout << endl << "Elija una opcion: "; cin >> op;
	return op;

}

int* eliminar(int* arreglo, int& t, int pos) {
	int* temporal = new int[t - 1];

	for (int i = 0;i < pos;i++) {
		temporal[i] = arreglo[i];
	}

	for (int i = pos + 1;i < t;i++) {
		temporal[i-1] = arreglo[i];
	}

	t -= 1;

	return temporal;
}

int *agregar_incio(int* arreglo, int& t, int nuevo) {
	int k = 0;
	int* temporal = new int[t + 1];

	for (int i = 1;i < t+1 ;i++) {
		temporal[i] = arreglo[k];
		k++;
	}
	temporal[0] = nuevo;
	t+=1;

	return temporal;
}



int* agregar_final(int *arreglo, int &t, int nuevo) {
	
	int* temporal = new int[t + 1];

	
	for (int i = 0; i < t; i++) {
		temporal[i] = arreglo[i];
	}

	
	temporal[t] = nuevo;

	
	t += 1;

	return temporal;
}

void listar_elementos(int *arreglo, int t) {
	if (arreglo != nullptr && t > 0) {
		for (int i = 0; i < t; i++) {
			cout << endl << " " << arreglo[i];
		}
	}
	else {
		cout << "EL ARREGLO ESTA VACIO";
	}
}



int main() {

	int* numeros;
	numeros = nullptr;

	int tam = 0, nuevo, pos;

	short opcion;

	do {
		opcion = menu();

		switch (opcion) {
		case 1:listar_elementos(numeros, tam);
			break;
		case 2:cout << "Digite el nuevo elemento: "; cin >> nuevo;
			numeros=agregar_final(numeros, tam, nuevo);
			break;
		case 3:cout << "Digite el nuevo elemento: ";cin >> nuevo;
			numeros = agregar_incio(numeros, tam, nuevo);
			break;
		case 4: cout << "Digite la posicion del elemento que desea eliminar: ";cin >> pos;
			numeros = eliminar(numeros, tam, pos);
			break;
		}
		system("pause>0");
		Console::Clear();

	} while (opcion != 5);


	delete[]numeros;

	return 0;
}
