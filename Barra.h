#ifndef BARRA_H
#define BARRA_H

class Barra {
    private:
        int id;
        int noInicial;
        int noFinal;
        float esforcoInterno;
    public:
        Barra (int id, int noInicial, int noFinal);
        int getId();
        int getNoInicial();
        int getNoFinal();
        float getEsforcoInterno();
        void setEsforcoInterno(float esforcoInterno);
};

#endif