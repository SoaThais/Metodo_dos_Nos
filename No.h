#ifndef NO_H
#define NO_H

#include <list>
#include "Barra.h"
using namespace std;

class No {
    private:
        int id;
        float coordX;
        float coordY;
        int grau;
        float apoioX;
        float apoioY;
        list <float> carregamentoX;
        list <float> carregamentoY;
        list <int> barras;
    public:
        No (int id, float coordX, float coordY);
        No (){};
        void setApoioX(float apoioX);
        void setApoioY(float apoioY);
        float getApoioX();
        float getApoioY();
        void setGrau(int grau);
        int getGrau();
        int getId();
        void setId(int id);
        float getCoordX();
        float getCoordY();
        void insereBarra(int id);
        void insereCarregamento(float carregamentoX, float carregamentoY);
        list <float> getCarregamentoX();
        list <float> getCarregamentoY();
        list <int> getBarras();
        void imprime();
};

#endif