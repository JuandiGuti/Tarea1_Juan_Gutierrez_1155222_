#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "EJERCICIO2.h"

using namespace std;

string palindromos_iterativa(string palabra) {
    int contador = 0, constante = 0;
    for (int i = palabra.length() - 1; i >= 0; i--) {
        if (palabra[i] == palabra[contador]) {
            constante++;
        }
        contador++;
    }
    if (palabra.length() == constante) {
        return "es palindromo";
    }
    else {
        return "no es palindromo";
    }
}
string palindrmos_recursiva(string palabra, int contador1, int contador2, int contador3, int contador4) {
    if (palabra[contador1] == palabra[contador2]) {
        contador3++;
    }
    else {
        contador4++;
    }
    if (contador3 == palabra.length()) {
        return "es palindromo";
    }
    else if (contador4 > 0) {
        return "no es palindromo";
    }
    return palindrmos_recursiva(palabra, (contador1--), (contador2++), contador3, contador4);

}
void EJERCICIO2::main()
{
    string nombreArchivo = "palabras.csv";
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    while (getline(archivo, linea)) {
        stringstream stream(linea);
        string valor;
        while (getline(stream, valor, ',')) {
            int contador1 = valor.length() - 1;
            int contador2 = 0, contador3 = 0, contador4 = 0;
            cout << "recursivo: " << valor << endl;
            cout << palindrmos_recursiva(valor, contador1, contador2, contador3, contador4) << endl;
            cout << "iterativo: " << valor << endl;
            cout << palindromos_iterativa(valor) << endl;
        }
    }
}

