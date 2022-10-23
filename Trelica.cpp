#include <iostream>
#include <cmath>
#include <unordered_map>
#include <list>
#include "No.h"
#include "Barra.h"
#include "Trelica.h"

using namespace std;

Trelica::Trelica (float vao, int numModulos){
    this->vao = vao;
    this->numModulos = numModulos;
    try {
        if (this->numModulos == 0){
            throw 1;
        }
        else {
            this->tamBarras = this->vao / this->numModulos;
        }
    }
    catch (int erro){
        if (erro == 1){
            cout << "Erro: Divisão por zero" << endl;
            exit(0);
        }
    }
    // this->primeiroNo = NULL;
    this->numBarras = this->numModulos * 3 + this->numModulos - 1;
    this->numNos = this->numModulos * 3 - this->numModulos + 1;
    insereNos();
    insereBarras();
}

void Trelica::insereNos(){
    float coordX = 0;
    float coordY = 0;
    float aux = 0;
    for (int i = 0; i < this->numNos; i++){
        No *no = new No (i, coordX, coordY);

        if (i == 0){
            no->setApoioX(0);
            no->setApoioY(0);
        }
        else if (i == this->numNos - 1){
            no->setApoioY(0);
        }

        this->mapaNos[i] = no;
        this->nos.push_back(i);

        aux += 0.5;
        coordX = aux * this->tamBarras;
        if (coordY == 0){
            coordY = this->tamBarras * sqrt(3) / 2;
        }
        else {
            coordY = 0;
        }
    }
}

void Trelica::imprimeNos(){
    for (auto i = this->nos.begin(); i != nos.end(); i++){
        int id = *i;
        No *no = mapaNos.at(id);
        cout << "Id: " << no->getId() << " Coordenada X: " << no->getCoordX() << " Coordenada Y: " << no->getCoordY() << endl;
    }
}

void Trelica::insereBarras(){
    int id = 0;
    for (int i = 0; i < this->numNos; i++){
        for (int j = i + 1; j < this->numNos; j++){
            No *no = mapaNos.at(i);
            bool insere = false;
            if (i == 0) {
                if (no->getGrau() < 2)
                    insere = true;
            }
            else if (i == 1 || i == this->numNos - 2) {
                if (no->getGrau() < 3)
                    insere = true;
            }
            else if (i != this->numNos - 1){
                if (no->getGrau() < 4)
                    insere = true;
            }
            if (insere){
                Barra *barra = new Barra(id, i, j);
                mapaNos.at(i)->setGrau(mapaNos.at(i)->getGrau() + 1);
                mapaNos.at(j)->setGrau(mapaNos.at(j)->getGrau() + 1);
                mapaNos.at(i)->insereBarra(id);
                mapaNos.at(j)->insereBarra(id);
                mapaBarras[id] = barra;
                id += 1;
            }
        }
    }
}

void Trelica::imprime() {
    for (auto i = this->nos.begin(); i != nos.end(); i++){
        int idNo = *i;
        No *no = mapaNos.at(idNo);
        cout << "------------------------No-----------------------" << endl;
        cout << "Id: " << no->getId() << endl << "Coordenada X: " << no->getCoordX() << endl << "Coordenada Y: " << no->getCoordY() << endl;
        cout << "Barras: " << endl;
        list <int> aux = no->getBarras();
        for (auto j = aux.begin(); j != aux.end(); j++){
            int id = *j;
            Barra *b = mapaBarras.at(id);
            cout << "Id: " << b->getId() << endl << "Id Inicial: " << b->getNoInicial() << endl << "Id Final: " << b->getNoFinal() << endl;
        }
        cout << endl;
    }
}