#include "cromossomo.h"

using namespace std;


Cromossomo::Cromossomo(int tamCromossomo)
{
    this->tamCromossomo = tamCromossomo;
    this->fitness = 0;
}

void Cromossomo::setGenes(vector<Gene*> genes)
{
    this->genes = genes;
}

vector<Gene*> Cromossomo::getGenes()
{
    return this->genes;
}

void Cromossomo::setFitness(double f)
{
    this->fitness = f;
}

double Cromossomo::getFitness()
{
    return this->fitness;
}

void Cromossomo::setTamCromossomo(int tamCromossomo)
{
    this->tamCromossomo = tamCromossomo;
}

int Cromossomo::getTamCromossomo()
{
    return this->tamCromossomo;
}

void Cromossomo::inGene(Gene* gene)
{
    this->genes.push_back(gene);
}

void Cromossomo::inGene(double valor)
{
    Gene* gene = new Gene(valor);
    inGene(gene);
}

void Cromossomo::inicializarCromossomo()
{
    for(int i=0; i<this->tamCromossomo; i++){
        double valor = ra.Uniform(0, 1);
        Gene* gene = new Gene(valor);
        inGene(gene);
    }
}
