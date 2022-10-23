#include <iostream>
#include <list>
#include "No.h"

using namespace std;

No::No (int id, float coordX, float coordY){
    this->id = id;
    this->coordX = coordX;
    this->coordY = coordY;
    this->grau = 0;
    // this->primeiraBarra = NULL;
    // this->proxNo = NULL;
    this->apoioX = -1;
    this->apoioY = -1;
}

void No::insereBarra(int id){
    this->barras.push_back(id);
}

list <int> No::getBarras(){
    return barras;
}

void No::imprime(){
    for (auto j = this->barras.begin(); j != this->barras.end(); j++){
        int id = *j;
        cout << id << " ";
    }
    cout << endl;
}

void No::setApoioX(float apoioX){
    this->apoioX = apoioX;
}

void No::setApoioY(float apoioY){
    this->apoioY = apoioY;
}

int No::getId(){
    return this->id;
}

float No::getCoordX(){
    return this->coordX;
}

float No::getCoordY(){
    return this->coordY;
}

void No::setGrau(int grau){
    this->grau = grau;
}

int No::getGrau(){
    return this->grau;
}

