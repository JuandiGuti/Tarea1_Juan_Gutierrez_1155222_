#include <iostream>
#include "EJERCICIO3.h"
#include "TAREA1_MAIN.h"
#include <string>

using namespace std;
TAREA1_MAIN tarea1_main_ej3;

//METODO PARA CAMBIAR DE BASE X A BASE 10
int convercion_basex_base10(string n_basex, int base) {
	int contador = 0;
	int valor_posicional;
	int valor_individual;
	int decimal = 0;

	for (int i = n_basex.length()-1; i >= 0; i--) {
		char num[] = { n_basex[i] };
		int num_int = atoi(num);
		valor_posicional = pow(base, contador);
		valor_individual = num_int * valor_posicional;
		decimal = decimal + valor_individual;
		contador++;
	}
	return decimal;
};
//METODO RECURSIVO PARA CAMBIAR DE BASE 10 A BASE X
int convercion_base10_basex(int numero, int base, int cociente, int residuo, string numero_string) {
	cociente = numero / base;
	residuo = numero % base;
	numero = cociente;
	numero_string = to_string(residuo) + numero_string;
	if (cociente == 0) {
		return stoi(numero_string);
	}
	return convercion_base10_basex(numero, base, cociente, residuo, numero_string);
}
//METODO ITERATIVO PARA CAMBIAR DE BASE 10 A BASE X
void convercion_base10_basex_iterativo(int numero, int base, int cociente, int residuo, string numero_string) {
	do {
		cociente = (numero / base);
		residuo = (numero % base);
		numero = cociente;
		numero_string = to_string(residuo) + numero_string;
	} while (cociente != 0);
	cout << "El resultado de la convercion iterativa es: " << numero_string << endl;
}
void EJERCICIO3::main()
{
	char numero_convertir[100];
	char base_inicial[100], base_final[100];
	string string_numero = "";

	//SOLICITUD DE BASES Y NUMERO A CONVERTIR
	cout << "Ingrese la base en la que esta el numero a convertir:" << endl;
	cin >> base_inicial;
	cout << "Ingrese la base a la que quiere convertir:" << endl;
	cin >> base_final;
	cout << "Ingrese el numero a convertir" << endl;
	cin >> numero_convertir;

	//COMPROBACION PARA SABER SI LOS DATOS INGRESADOS SON NUMEROS
	if (tarea1_main_ej3.isnumeric(base_inicial) && tarea1_main_ej3.isnumeric(base_final) && tarea1_main_ej3.isnumeric(numero_convertir)) {
		//COMPROBACION PARA SABER SI QUIERE CAMBIAR UN BINARIO
		if (atoi(base_inicial) == 2) {
			//COMPROBACION PARA SABER SI METIO UN BINARIO
			if (isbinary(numero_convertir) == false) {
				cout << "Error, usted quiere convertir de base" << base_inicial << " a base " << base_final << endl;
				cout << "Reinicie el programa e ingrese un numero binario para esta accion." << endl;
				system("pause");
			}
		}
		//CAMBIO DE BASEX A BASE DECIMAL MEDIANTE SU METODO
		int decimal = convercion_basex_base10(numero_convertir, atoi(base_inicial));
		int cociente = decimal / stoi(base_final);
		int residuo = decimal % stoi(base_final);

		//DESPLEGUE DE METODO ITERATIVO
		convercion_base10_basex_iterativo(decimal, stoi(base_final), cociente, residuo, string_numero);
		//DESPLEGUE DE METODO RECURSIVO
		int basex = convercion_base10_basex(decimal, stoi(base_final), cociente, residuo, string_numero);
		cout << "El resultado de la convercion recursiva es: " << basex << endl;
	}
	else {
		cout << "Ingrese una base valida o numero valido" << endl;
		system("pause");
	}
}

//METODO PARA SABER SI ES BINARIO EL NUMERO
bool EJERCICIO3::isbinary(char texto[100])
{
	int valor_en_ASCII, contador = 0, largo;

	string suplente = texto;

	char caracter;

	largo = suplente.length();

	int ASCII_inicio = 48;
	int ASCII_final = 49;

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

