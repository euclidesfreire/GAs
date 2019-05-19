#ifndef _POPULACAO_H_
#define _POPULACAO_H_

#include "Rand.h"
#include "cromossomo.h"
#include "gene.h"
#include <vector>
#include <iostream>

Rand ra;

class Populacao {

private:

    vector<Cromossomo*> cromossomos;
    int tamPopulacao, tamCromossomo;

public:

    Populacao(int tamPopulacao, int tamCromossomo);
    void setCromossomos(vector<Cromossomo*> c);
    vector<Cromossomo*> getCromossomos();
    void setTamPopulacao(int tamPopulacao);
    int getTamPopulacao();
    void setTamCromossomo(int tamCromossomo);
    int getTamCromossomo();
    void inCromossomo(Cromossomo* cromossomo);
    void outCromossomos();
    void inicializarPoupulacao();
    Cromossomo* selecaoTorneio(Populacao p, vector<Cromossomo*> c);
    vector<Cromossomo*> crossover(Populacao p, vector<Cromossomo*> c);
    double mutacao();

};

#endif // _POPULACAO_H_
