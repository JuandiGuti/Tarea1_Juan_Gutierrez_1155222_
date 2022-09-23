#include "TAREA1_MAIN.h"
#include "EJERCICIO1.h"
#include "EJERCICIO2.h"
#include "EJERCICIO3.h"
#include <iostream>

using namespace std;

//METODO PARA SABER SI UN STRING ES UN NUMERO O NO MEDIANTE EL CODIGO ASCII DEL 0 AL 9
bool TAREA1_MAIN::isnumeric(char texto[100])
{
	int valor_en_ASCII, contador = 0, largo;

	string suplente = texto;;

	char caracter;

	largo = suplente.length();

	int ASCII_inicio = 48;
	int ASCII_final = 57;

	for (int i = 0; i <= largo; i++)
	{
		caracter = texto[i];
		valor_en_ASCII = caracter;

		for (int j = ASCII_inicio; j <= ASCII_final; j++)
		{
			if (valor_en_ASCII == j)
			{
				contador++;
			}
		}

	}
	if (largo == contador)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char seleccion[100];
	int seleccio_numero;
	EJERCICIO1 EJ1;
	EJERCICIO2 EJ2;
	EJERCICIO3 EJ3;
	TAREA1_MAIN tarea1_main;

	//DESPLIEGUE DE MENU DE OPCION
	cout << "< Menu >	< elige el numero de la opcion > \n";
	cout << "1. Ejercicio 1\n";
	cout << "2. Ejercicio 2\n";
	cout << "3. Ejercicio 3\n";
	cout << "4. Salir\n";
	cin >> seleccion;

	//COMPROBACION SI EL DATO INTRODUCCIDO ES UN NUMERO
	if (tarea1_main.isnumeric(seleccion))
	{
		//SWITCH PARA SABER QUE ELIGUIO DENTRO DEL MENU O SI NO ELIGIO NINGUNA DE LAS OPCIONES
		switch (atoi(seleccion)) {
		case 1:
			system("cls");
			cout << "Ejercicio 1 \n";
			EJ1.main();
			break;
		case 2:
			system("cls");
			cout << "Ejercicio 2 \n";
			EJ2.main();
			break;
		case 3:
			system("cls");
			cout << "Ejercicio 3 \n";
			EJ3.main();
			break;
		case 4:
			system("cls");
			cout << "Salir\n";
			system("pause");
			break;
		default:
			cout << "Elige una opcion valida que este dentro del menu...\n";
			cout << "Reinicia el programa \n";
			system("pause");
			break;
		}
	}
	else
	{
		cout << "Escribe un numero entero de la opcion dentro del menu... \n";
		cout << "Reinicia el programa \n";
		system("pause");
	}

}