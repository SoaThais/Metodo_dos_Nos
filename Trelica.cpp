#include <iostream>
#include <cmath>
#include <unordered_map>
#include <list>
#include <fstream>
#include "No.h"
#include "Barra.h"
#include "Trelica.h"

using namespace std;

Trelica::Trelica(float vao, int numModulos)
{
    this->vao = vao;
    this->numModulos = numModulos;
    try
    {
        if (this->numModulos == 0)
        {
            throw 1;
        }
        else
        {
            this->tamBarras = this->vao / this->numModulos;
        }
    }
    catch (int erro)
    {
        if (erro == 1)
        {
            cout << "Erro: Divisão por zero" << endl;
            exit(0);
        }
    }
    this->numBarras = this->numModulos * 3 + this->numModulos - 1;
    this->numNos = this->numModulos * 3 - this->numModulos + 1;
    insereNos();
    insereBarras();
    escreveArquivoDot();
}

void Trelica::insereNos()
{
    float coordX = 0;
    float coordY = 0;
    float aux = 0;
    for (int i = 0; i < this->numNos; i++)
    {
        No *no = new No(i, coordX, coordY);

        if (i == 0)
        {
            no->setApoioX(0);
            no->setApoioY(0);
        }
        else if (i == this->numNos - 1)
        {
            no->setApoioY(0);
        }

        this->mapaNos[i] = no;
        this->nos.push_back(i);

        aux += 0.5;
        coordX = aux * this->tamBarras;
        if (coordY == 0)
        {
            coordY = this->tamBarras * sqrt(3) / 2;
        }
        else
        {
            coordY = 0;
        }
    }
}

void Trelica::imprimeNos()
{
    for (auto i = this->nos.begin(); i != nos.end(); i++)
    {
        int id = *i;
        No *no = mapaNos.at(id);
        cout << "Id: " << no->getId() << " Coordenada X: " << no->getCoordX() << " Coordenada Y: " << no->getCoordY() << endl;
    }
}

void Trelica::insereBarras()
{
    int id = 0;
    for (int i = 0; i < this->numNos; i++)
    {
        for (int j = i + 1; j < this->numNos; j++)
        {
            No *no = mapaNos.at(i);
            bool insere = false;
            if (i == 0)
            {
                if (no->getGrau() < 2)
                    insere = true;
            }
            else if (i == 1 || i == this->numNos - 2)
            {
                if (no->getGrau() < 3)
                    insere = true;
            }
            else if (i != this->numNos - 1)
            {
                if (no->getGrau() < 4)
                    insere = true;
            }
            if (insere)
            {
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

void Trelica::imprime()
{
    for (auto i = this->nos.begin(); i != nos.end(); i++)
    {
        int idNo = *i;
        No *no = mapaNos.at(idNo);
        cout << "------------------------ No " << no->getId() << " -----------------------" << endl;
        cout << "Id: " << no->getId() << endl
             << "Coordenada X: " << no->getCoordX() << endl
             << "Coordenada Y: " << no->getCoordY() << endl;

        cout << endl
             << "Carregamentos: " << endl;
        cout << "Em x: " << endl;
        list<float> aux1 = no->getCarregamentoX();
        for (auto j = aux1.begin(); j != aux1.end(); j++)
        {
            int fx = *j;
            cout << fx << endl;
        }
        cout << "Em y: " << endl;
        aux1 = no->getCarregamentoY();
        for (auto j = aux1.begin(); j != aux1.end(); j++)
        {
            int fy = *j;
            cout << fy << endl;
        }

        cout << endl
             << "Barras: " << endl;
        list<int> aux = no->getBarras();
        for (auto j = aux.begin(); j != aux.end(); j++)
        {
            int id = *j;
            Barra *b = mapaBarras.at(id);
            cout << "Id: " << b->getId() << endl
                 << "Id Inicial: " << b->getNoInicial() << endl
                 << "Id Final: " << b->getNoFinal() << endl;
        }
        cout << endl;
    }
}

void Trelica::adicionaCarregamento(int id, float fx, float fy)
{
    try
    {
        mapaNos.at(id)->insereCarregamento(fx, fy);
    }
    catch (const out_of_range &oor)
    {
        cout << "Erro: Id Invalido" << endl;
        return;
    }
}

// Fy + gera, em relação ao nó 0, momento no sentido anti-horário +
// Fy - gera, em relação ao nó 0, momento no sentido horário -
// Fx + gera, em relação ao nó 0, momento no sentido horário -
// Fx - gera, em relação ao nó 0, momento no sentido anti-horário +
// Assim, no cálculo do momento em relação ao nó 0, o sinal de Fy é mantido 
// e o de Fx é multiplicado por -1

void Trelica::calculaReacoesApoio()
{
    int idRx = -1, idRy1 = -1, idRy2 = -1;
    float somatorioFx = 0, somatorioFy = 0, somatorioM = 0;
    for (int i = 0; i < this->numNos; i++){
        No *no = this->mapaNos.at(i);
        if (no->getApoioX() != INT_MAX)
        {
            idRx = i;
        }
        if (no->getApoioY() != INT_MAX)
        {
            if (idRy1 == -1){
                idRy1 = i;
            }
            else{
                idRy2 = i;
            }
        }

        list <float> aux = no->getCarregamentoX();
        for (auto j = aux.begin(); j != aux.end(); j++){
            float fx = *j;
            somatorioFx += fx;
            somatorioM += fx * -1 * no->getCoordY();
        }

        aux = no->getCarregamentoY();
        for (auto j = aux.begin(); j != aux.end(); j++){
            float fy = *j;
            somatorioFy += fy;
            somatorioM += fy * no->getCoordX();
        }
    }

    if (somatorioFx != 0)
        somatorioFx = somatorioFx * -1;

    mapaNos.at(idRx)->setApoioX(somatorioFx);

    if (somatorioM != 0)
        somatorioM = somatorioM * -1 / mapaNos.at(idRy2)->getCoordX();

    mapaNos.at(idRy2)->setApoioY(somatorioM);

    if (somatorioFy + somatorioM != 0)
        somatorioFy = (somatorioFy + somatorioM) * -1;
    
    mapaNos.at(idRy1)->setApoioY(somatorioFy);
    cout << "------------------------ Reacoes de Apoio -----------------------" << endl;
    cout << "No " << idRx << " (eixo x): " << mapaNos.at(idRx)->getApoioX() << endl;
    cout << "No " << idRy1 << " (eixo y): " << mapaNos.at(idRy1)->getApoioY() << endl;
    cout << "No " << idRy2 << " (eixo y): " << mapaNos.at(idRy2)->getApoioY() << endl << endl;
}

void Trelica::QuickSort(No nos[], int p, int q)
{
    if (p < q)
    {
        int j = particionamento(nos, p, q);
        QuickSort(nos, p, j - 1);
        QuickSort(nos, j + 1, q);
    }
}

int Trelica::particionamento(No nos[], int p, int q)
{
    int i = p - 1, j = q;
    int v = nos[q].getGrau();

    while (1)
    {
        while (nos[++i].getGrau() < v);
        while (v < nos[--j].getGrau())
        {
            if (j == p)
                break;
        }
        if (i >= j)
            break;
        troca(&nos[i], &nos[j]);
    }

    troca(&nos[i], &nos[q]);

    return i;
}

void Trelica::troca(No *a, No *b)
{
    No aux = *a;
    *a = *b;
    *b = aux;
}

void Trelica::calculaEsforcosInternos()
{
    No *nos = new No[this->numNos];
    for (int i = 0; i < this->numNos; i++)
    {
        nos[i].setId(mapaNos.at(i)->getId());
        nos[i].setGrau(mapaNos.at(i)->getGrau());
    }

    QuickSort(nos, 0, this->numNos - 1);

    for (int i = 0; i < this->numNos; i++)
    {
        No no = nos[i];
        list <int> aux = mapaNos.at(no.getId())->getBarras();
        int id_1, id_2;
        float unitarioI_1, unitarioJ_1;
        float unitarioI_2, unitarioJ_2;

        for (auto j = aux.begin(); j != aux.end(); j++)
        {
            int idBarra = *j;
            Barra *b = mapaBarras.at(idBarra);
            if (b->getEsforcoInterno() == INT_MAX) {
                No *noFinal = mapaNos.at(b->getNoFinal());
                No *noInicial = mapaNos.at(b->getNoInicial());
                float unitarioI, unitarioJ;
                if (b->getNoInicial() != no.getId()) {
                    unitarioI = (noInicial->getCoordX() - noFinal->getCoordX());
                    unitarioJ = (noInicial->getCoordY() - noFinal->getCoordY());       
                }
                else {
                    unitarioI = (noFinal->getCoordX() - noInicial->getCoordX());
                    unitarioJ = (noFinal->getCoordY() - noInicial->getCoordY());
                }
                float raiz = sqrt(pow(unitarioI, 2) + pow(unitarioJ, 2));
                unitarioI = unitarioI / raiz;    
                unitarioJ = unitarioJ / raiz;  
                if (unitarioJ != 0){
                    unitarioI_1 = unitarioI;
                    unitarioJ_1 = unitarioJ;
                    id_1 = idBarra;
                }
                else {
                    unitarioI_2 = unitarioI;
                    unitarioJ_2 = unitarioJ;
                    id_2 = idBarra;
                }
            }
        }

        list <float> aux2;
        if (i < this->numNos - 1){
            float somaY = 0;
            aux2 = mapaNos.at(no.getId())->getCarregamentoY();
            for (auto j = aux2.begin(); j != aux2.end(); j++) {
                somaY += *j;
            }
            if (mapaNos.at(no.getId())->getApoioY() != INT_MAX){
                somaY += mapaNos.at(no.getId())->getApoioY();
            }
            list <int> aux3 = mapaNos.at(no.getId())->getBarras();
            for (auto j = aux3.begin(); j != aux3.end(); j++)
            {
                int idBarra = *j;
                Barra *b = mapaBarras.at(idBarra);
                if (b->getEsforcoInterno() != INT_MAX) {
                    No *noFinal = mapaNos.at(b->getNoFinal());
                    No *noInicial = mapaNos.at(b->getNoInicial());
                    float unitarioI, unitarioJ;
                    if (b->getNoInicial() != no.getId()) {
                        unitarioI = (noInicial->getCoordX() - noFinal->getCoordX());
                        unitarioJ = (noInicial->getCoordY() - noFinal->getCoordY());       
                    }
                    else {
                        unitarioI = (noFinal->getCoordX() - noInicial->getCoordX());
                        unitarioJ = (noFinal->getCoordY() - noInicial->getCoordY());
                    }
                    float raiz = sqrt(pow(unitarioI, 2) + pow(unitarioJ, 2));
                    unitarioI = unitarioI / raiz;    
                    unitarioJ = unitarioJ / raiz;  
                    somaY += b->getEsforcoInterno() * unitarioJ;
                }
            }
            float esforco_1 = - somaY / unitarioJ_1;
            mapaBarras.at(id_1)->setEsforcoInterno(esforco_1);
        }
        if (i < this->numNos - 2) {
            float somaX = 0;
            aux2 = mapaNos.at(no.getId())->getCarregamentoX();
            for (auto j = aux2.begin(); j != aux2.end(); j++) {
                somaX += *j;
            }
            if (mapaNos.at(no.getId())->getApoioX() != INT_MAX){
                somaX += mapaNos.at(no.getId())->getApoioX();
            }
            list <int> aux3 = mapaNos.at(no.getId())->getBarras();
            for (auto j = aux3.begin(); j != aux3.end(); j++)
            {
                float unitarioI, unitarioJ;
                int idBarra = *j;
                Barra *b = mapaBarras.at(idBarra);
                if (b->getEsforcoInterno() != INT_MAX) {
                    No *noFinal = mapaNos.at(b->getNoFinal());
                    No *noInicial = mapaNos.at(b->getNoInicial());
                    if (b->getNoInicial() != no.getId()) {
                        unitarioI = (noInicial->getCoordX() - noFinal->getCoordX());
                        unitarioJ = (noInicial->getCoordY() - noFinal->getCoordY());       
                    }
                    else {
                        unitarioI = (noFinal->getCoordX() - noInicial->getCoordX());
                        unitarioJ = (noFinal->getCoordY() - noInicial->getCoordY());
                    }
                    float raiz = sqrt(pow(unitarioI, 2) + pow(unitarioJ, 2));
                    unitarioI = unitarioI / raiz;    
                    unitarioJ = unitarioJ / raiz;  
                    somaX += b->getEsforcoInterno() * unitarioI;
                }
            }
            float esforco_2 = - somaX / unitarioI_2;
            mapaBarras.at(id_2)->setEsforcoInterno(esforco_2);
        }
    }
    
    for (auto i = mapaBarras.begin(); i != mapaBarras.end(); i++){
        int id = i->first;
        Barra *b = i->second;
        cout << "--------------------------- Barra " << id << " --------------------------" << endl;
        cout << "Id: " << id << endl;
        cout << "No Inicial: " << b->getNoInicial() << endl;
        cout << "No Final: " << b->getNoFinal() << endl;
        cout << "Esforco: " << b->getEsforcoInterno() << endl << endl;
    }
}

void Trelica::escreveArquivoDot()
{
    ofstream saida;
    saida.open("Trelica.dot", ios::out);

    saida << "graph Trelica {" << endl;

    bool adicionado[this->numBarras];

    for (auto i = this->nos.begin(); i != this->nos.end(); i++)
    {

        No *no = mapaNos.at(*i);
        list<int> aux = no->getBarras();

        for (auto j = aux.begin(); j != aux.end(); j++)
        {
            int id = *j;
            Barra *b = mapaBarras.at(id);
            if (adicionado[id] == false)
            {
                saida << b->getNoInicial() << " -- " << b->getNoFinal();
                adicionado[id] = true;
                saida << endl;
            }
        }
    }
    saida << "}" << endl;
    saida.close();
}