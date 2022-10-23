#ifndef BARRA_H
#define BARRA_H

class Barra {
    private:
        int id;
        int noInicial;
        int noFinal;
    public:
        Barra (int id, int noInicial, int noFinal);
        int getId();
        int getNoInicial();
        int getNoFinal();
};

#endif