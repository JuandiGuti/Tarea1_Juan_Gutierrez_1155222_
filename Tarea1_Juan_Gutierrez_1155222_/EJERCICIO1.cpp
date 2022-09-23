#include <iostream>
#include "EJERCICIO1.h"
#include "TAREA1_MAIN.h"

using namespace std;
TAREA1_MAIN tarea1_main_ej1;

int multiplicacion_recursiva(int a, int b, int suma, int contador) {
	if (a == contador) {
		return suma;
	}
	return multiplicacion_recursiva(a, b,(suma + b),(contador + 1));
};
int multiplicacion_iterativa(int a, int b, int suma) {
	for (int i = 0; i < a; i++) {
		suma = suma + b;
	}
	return suma;
};
void EJERCICIO1::main()
{
	char a[100], b[100];
	cout << "Coloca en numeros enteros el primer multiplicador:\n";
	cin >> a;
	cout << "Coloca en numeros enteros el segundo multiplicador:\n";
	cin >> b;
	if (tarea1_main_ej1.isnumeric(a) == false || tarea1_main_ej1.isnumeric(b) == false) {
		cout << "Coloca numeros enteros \n";
		cout << "Reinicia el programa \n";
		system("exit");
	}
	int contador = 0;
	int suma = 0;
	cout << "Recursiva: \n";
	cout << multiplicacion_recursiva(atoi(a), atoi(b), suma, contador) << "\n";
	cout << "Iterativa: \n";
	cout << multiplicacion_iterativa(atoi(a), atoi(b), suma) << "\n";
}

