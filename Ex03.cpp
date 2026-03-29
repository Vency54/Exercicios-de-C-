#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <locale.h>
using namespace std;


/* Exercício 3 - À partir de uma lista de nomes disponível em um arquivo TXT, 
transforma-los em nomes no formato agenda telefônica */

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	ifstream arq("nomes.txt");

    if (arq.is_open()) {

        string linha;
        cout << "Lista Telefônica:\n";
        while (getline(arq, linha)) {
        	
  	 	 	 stringstream ss(linha);
			vector<string> partes;
			string Primeiro_Nome;
			string palavra; 
			
        	    while (ss >> palavra) { 
        partes.push_back(palavra);
    }
    
       	string Sobrenome = partes.back();
		
            for (int i = 0; i < partes.size() - 1; i++) {
                Primeiro_Nome += partes[i] + " ";

                if (i < partes.size() - 2)
                    cout << " ";
            }
            
            cout << endl;

            cout << Sobrenome<< "," << " " << Primeiro_Nome << "\n\n";

		}
	
        arq.close();
     }else {
        cout << "Erro ao abrir o arquivo";
    }
	
	return 0;
}