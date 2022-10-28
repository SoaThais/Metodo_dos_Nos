#include "Trelica.h"
#include <iostream>

using namespace std;

int main()
{
    float vao;
    int numModulos;

    cout << endl
         << "----------------Parametros de Entrada----------------" << endl;
    cout << "Vao: ";
    cin >> vao;
    cout << "Numero de modulos: ";
    cin >> numModulos;

    Trelica *t = new Trelica(vao, numModulos);

    bool continua = true;
    int forca = 1;
    int momento = 1;

    do
    {
        cout << endl
             << "Menu" << endl
             << "1. Adicionar Forca" << endl;
        cout << "2. Aplicar Metodo dos Nos" << endl;
        cout << "3. Encerrar Programa" << endl;
        int opcao;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            cout << endl
                 << "Forca " << forca << ": " << endl;
            int id;
            float fx, fy;
            cout << "Id do No: ";
            cin >> id;
            cout << "Fx: ";
            cin >> fx;
            cout << "Fy: ";
            cin >> fy;
            forca += 1;
            t->adicionaCarregamento(id, fx, fy);
        }
        else if (opcao == 2)
        {
            cout << endl;
            // t->imprime();
            continua = false;
            t->calculaReacoesApoio();
            t->calculaEsforcosInternos();
        }
        else if (opcao == 3){
            continua = false;
        }
        else
        {
            cout << "Erro: Opcao Invalida" << endl;
        }
    } while (continua);

    // Para visualizar a estrutura da treliça
    // Link para download do graphviz: https://graphviz.org/download/
    // Após o download:
    // No terminal: dot -Tyourformat(png, pdf...) your file -o output
    // Ex: dot -Tpng arquivo.dot -o arquivo.png
    // Obs: a figura gerada não mostra as forças que agem sobre a treliça

    // t->imprime();
    return 0;
}