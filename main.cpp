#include "Trelica.h"
#include <iostream>

using namespace std;

int main() {

    float vao;
    int numModulos;

    cout << endl << "----------------Parametros de Entrada----------------" << endl;
    cout << "Vao: ";
    cin >> vao;
    cout << "Numero de modulos: ";
    cin >> numModulos;

    Trelica *t = new Trelica(vao, numModulos);
    
    bool continua = true;
    int carregamento = 1;

    do {
        cout << endl << "Menu" <<  endl << "1. Adicionar Carregamento Externo" << endl;
        cout << "2. Aplicar Metodo dos Nos" << endl;

        int opcao;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1){
            cout << endl << "Carregamento " << carregamento << ": " << endl;
            int id;
            float fx, fy;
            cout << "Id do No: ";
            cin >> id;
            cout << "Fx: ";
            cin >> fx;
            cout << "Fy: ";
            cin >> fy;
            carregamento += 1;
            t->adicionaCarregamento(id, fx, fy);
        }
        else if (opcao == 2){
            continua = false;
        }
        else {
            cout << "Erro: Opcao Invalida" << endl;
        }
    }
    while (continua);

    // Para visualizar a estrutura da treliça
    // Link para download do graphviz: https://graphviz.org/download/
    // Após o download:
    // No terminal: dot -Tyourformat(png, pdf...) your file -o output
    // Ex: dot -Tpng arquivo.dot -o arquivo.png
    // Obs: a figura gerada não mostra as forças que agem sobre a treliça

    t->imprime();
    return 0;
}