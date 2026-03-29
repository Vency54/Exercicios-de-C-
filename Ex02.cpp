#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool ehPalindromo(string texto) {
    string limpo = "";
    
    for (size_t i = 0; i < texto.length(); i++) {
        char c = texto[i];
        if (!isspace(c)) {
            limpo += (char)tolower(c);
        }
    }
    
    string reverso = limpo;
    
    reverse(reverso.begin(), reverso.end());
    
    return (limpo == reverso);
}

int main() {
    string mensagem;
    
    cout << "Digite uma mensagem: ";
    // getline lê a linha inteira com espaço
    getline(cin, mensagem);
    
    if (ehPalindromo(mensagem)) {
        cout << "\nA mensagem é um palindromo." << endl;
    } else {
        cout << "\nA mensagem não é um palindromo." << endl;
    }
    
    cout << "\nPressione Enter para sair...";
    cin.get(); 
    
    return 0;
}
