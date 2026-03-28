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

    // largura padrão de terminal
    int colunaInicial = (80 - msg.length()) / 2;

    // PRIMEIRO imprime a mensagem centralizada na linha 5
    cout << "\033[5;" << colunaInicial << "H" << msg;
    Sleep(50);

    // PARA CADA LETRA, efetuar a "queda"
    for (int i = 0; i < msg.length(); i++) {

        int coluna = colunaInicial + i;  // coluna específica da letra

        // A letra começa na linha 5
        for (int linha = 5; linha <= 20; linha++) {

            // Move o cursor onde a letra deve aparecer
            cout << "\033[" << linha << ";" << coluna << "H";
            cout << msg[i];
            
            Sleep(50);

            // Apaga a letra da posição anterior (exceto se já está na última linha)
            if (linha < 20) {
                cout << "\033[" << linha << ";" << coluna << "H";
                cout << " ";
            }
        }
    }

    // No final, a frase inteira deve estar na linha 20
    cout << "\033[20;" << colunaInicial << "H" << msg;

    cout << "\n\n";
    return 0;
}