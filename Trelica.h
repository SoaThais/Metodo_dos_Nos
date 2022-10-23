#ifndef TRELICA_H
#define TRELICA_H

#include <unordered_map>
#include <list>
#include "No.h"
#include "Barra.h"

using namespace std;

class Trelica {
    private:
        float vao;
        int numModulos;
        float tamBarras;
        int numBarras;
        int numNos;
        unordered_map <int, No*> mapaNos;
        unordered_map <int, Barra*> mapaBarras;
        list <int> nos;
        void insereNos();
        void insereBarras();
        void escreveArquivoDot();
    public:
        Trelica(float vao, int numModulos);
        void imprimeNos();
        void imprime();
        void adicionaCarregamento(int id, float carregamentoX, float carregamentoY);
};

#endif