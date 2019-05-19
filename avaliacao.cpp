#include "avaliacao.h"

using namespace std;

Avaliacao::Avaliacao()
{
    this->fitness = 0;
}

void Avaliacao::setFitness(double f)
{
    this->fitness = f;
}

double Avaliacao::getFitness()
{
    return this->fitness;
}

double Avaliacao::calcularFitness(Cromossomo *c)
{
    this->fitness = 0;
    int tam = c->getTamCromossomo();
    double p, q[10] = {52.547, 72.154, 53.694, 57.771, 115.88, 105.59, 75.368, 126.02, 52.756, 85.100
};

    for(int i = 0; i < tam; i++){
        p = decodificar(c, i);
        this->fitness += pow(p-q[i], 2);
    }
    return sqrt(this->fitness);
}

double Avaliacao::decodificar(Cromossomo *c, int i)
{
    double d;
    vector<Gene*> tmpG =  c->getGenes();

    d = tmpG[i]->getAlelo() * (130-50) + 50;

    return d;
}
