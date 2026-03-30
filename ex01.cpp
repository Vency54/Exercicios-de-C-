#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>

using namespace std;

/**
 Exercício 1  - Receber através de digitação uma mensagem. 

Apresentar esta mensagem, centralizada, na linha 5 da tela.

À partir daí, cada letra desta mensagem deverá "cair", 
da linha 5 até a linha 20, simulando uma "cascata". 
Ao final, a mensagem deverá estar toda apresentada na linha 20.
 */


int main()
{
   setlocale(LC_ALL, "");

    string msg;
    cout << "Digite a Mensagem: ";
    getline(cin, msg);

    int colunaInicial = (80 - msg.length()) / 2;

    cout << "\033[5;" << colunaInicial << "H" << msg;
    Sleep(50);

    for (int i = 0; i < msg.length(); i++) {

        int coluna = colunaInicial + i;  // coluna específica da letra

        for (int linha = 5; linha <= 20; linha++) {

            cout << "\033[" << linha << ";" << coluna << "H";
            cout << msg[i];
            
            Sleep(50);

            if (linha < 20) {
                cout << "\033[" << linha << ";" << coluna << "H";
                cout << " ";
            }
        }
    }

    cout << "\033[20;" << colunaInicial << "H" << msg;

    cout << "\n\n";
    return 0;
}
