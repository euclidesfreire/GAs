#ifndef _CROMOSSOMO_H_
#define _CROMOSSOMO_H_

#include "gene.h"
#include "Rand.h"
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

extern Rand ra;

class Cromossomo {

private:

    vector<Gene*> genes;
    double fitness;
    int tamCromossomo;

public:

    Cromossomo(int tamCromossomo);
    void setGenes(vector<Gene*> genes);
    vector<Gene*> getGenes();
    void setFitness(double f);
    double getFitness();
    void setTamCromossomo(int tamCromossomo);
    int getTamCromossomo();
    void inGene(Gene* gene);
    void inGene(double valor);
    void inicializarCromossomo();

};

#endif // _CROMOSSOMO_H_
