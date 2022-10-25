#include <iostream>
#include <list>
#include "No.h"

using namespace std;

No::No(int id, float coordX, float coordY)
{
    this->id = id;
    this->coordX = coordX;
    this->coordY = coordY;
    this->grau = 0;
    this->apoioX = -1;
    this->apoioY = -1;
}

void No::insereBarra(int id)
{
    this->barras.push_back(id);
}

list<int> No::getBarras()
{
    return barras;
}

void No::insereCarregamento(float carregamentoX, float carregamentoY)
{
    this->carregamentoX.push_back(carregamentoX);
    this->carregamentoY.push_back(carregamentoY);
}

list<float> No::getCarregamentoX()
{
    return carregamentoX;
}

list<float> No::getCarregamentoY()
{
    return carregamentoY;
}

void No::imprime()
{
    for (auto j = this->barras.begin(); j != this->barras.end(); j++)
    {
        int id = *j;
        cout << id << " ";
    }
    cout << endl;
}

void No::setApoioX(float apoioX)
{
    this->apoioX = apoioX;
}

void No::setApoioY(float apoioY)
{
    this->apoioY = apoioY;
}

float No::getApoioX()
{
    return this->apoioX;
}

float No::getApoioY()
{
    return this->apoioY;
}

int No::getId()
{
    return this->id;
}

float No::getCoordX()
{
    return this->coordX;
}

float No::getCoordY()
{
    return this->coordY;
}

void No::setGrau(int grau)
{
    this->grau = grau;
}

int No::getGrau()
{
    return this->grau;
}
