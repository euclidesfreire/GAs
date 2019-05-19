#ifndef _AVALIACAO_H_
#define _AVALIACAO_H_

#include "cromossomo.h"
#include "gene.h"
#include <math.h>

class Avaliacao {

private:

    double fitness;

public:

    Avaliacao();
    void setFitness(double f);
    double getFitness();
    double calcularFitness(Cromossomo *c);
    double decodificar(Cromossomo *c, int j);
};

#endif // _AVALIACAO_H_

