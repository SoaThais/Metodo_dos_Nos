#include "Barra.h"
#include <iostream>

using namespace std;

Barra::Barra(int id, int noInicial, int noFinal)
{
    this->id = id;
    this->noInicial = noInicial;
    this->noFinal = noFinal;
    this->esforcoInterno = INT_MAX;
}

int Barra::getId()
{
    return this->id;
}

int Barra::getNoInicial()
{
    return this->noInicial;
}

int Barra::getNoFinal()
{
    return this->noFinal;
}

float Barra::getEsforcoInterno()
{
    return this->esforcoInterno;
}

void Barra::setEsforcoInterno(float esforcoInterno)
{
    this->esforcoInterno = esforcoInterno;
}