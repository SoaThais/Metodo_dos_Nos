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
        // No *primeiroNo;
        unordered_map <int, No*> mapaNos;
        unordered_map <int, Barra*> mapaBarras;
        list <int> nos;
        // list<Barra*> BarraTrelica;
        void insereNos();
        void insereBarras();
    public:
        Trelica(float vao, int numModulos);
        void imprimeNos();
        void imprime();
};

#endif