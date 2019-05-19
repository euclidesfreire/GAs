#include "selecao.h"

using namespace std;

Cromossomo* Selecao::selecaoTorneio(Populacao p, vector<Cromossomo*> c){

    int tamp = p.getTamPopulacao() - 1;
    int r1, r2, r3;
    double f1, f2, f3;

    r1 = ra.Uniform(0, tamp);
    r2 = ra.Uniform(0, tamp);
    r3 = ra.Uniform(0, tamp);

    f1 = c[r1]->getFitness();
    f2 = c[r2]->getFitness();
    f3 = c[r3]->getFitness();

    if((f1 < f2) && (f1 < f3)){
        return c[r1];
    } else if((f2 < f1) && (f2 < f3)){
        return c[r2];
    } else {
        return c[r3];
    }

}
