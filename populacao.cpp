#include "populacao.h"

using namespace std;

Populacao::Populacao(int tamPopulacao, int tamCromossomo)
{
    ra.SetSeed(time(0));
    this->tamPopulacao = tamPopulacao;
    this->tamCromossomo = tamCromossomo;
    inicializarPoupulacao();
}

void Populacao::setCromossomos(vector<Cromossomo*> c)
{
    this->cromossomos = c;
}

vector<Cromossomo*> Populacao::getCromossomos()
{
    return this->cromossomos;
}

void Populacao::setTamPopulacao(int tamPopulacao)
{
    this->tamPopulacao = tamPopulacao;
}

int Populacao::getTamPopulacao()
{
    return this->tamPopulacao;
}

void Populacao::setTamCromossomo(int tamCromossomo)
{
    this->tamCromossomo = tamCromossomo;
}

int Populacao::getTamCromossomo()
{
    return this->tamCromossomo;
}

void Populacao::inCromossomo(Cromossomo* cromossomo)
{
    this->cromossomos.push_back(cromossomo);
}

void Populacao::outCromossomos()
{
    vector<Gene*> tmpG;

    for(int i=0; i<cromossomos.size(); i++){
        tmpG = this->cromossomos[i]->getGenes();
        for(int j=0; j<tmpG.size(); j++){
            cout << tmpG[j]->getAlelo() << " ";
        }
        cout << endl;
    }
}

void Populacao::inicializarPoupulacao()
{
    int i;

    for(i=0; i<this->tamPopulacao; i++){
        Cromossomo* cromossomo = new Cromossomo(tamCromossomo);
        cromossomo->inicializarCromossomo();
        inCromossomo(cromossomo);
    }
}

Cromossomo* Populacao::selecaoTorneio(Populacao p, vector<Cromossomo*> c){

    int tamp = p.tamPopulacao - 1;
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

vector<Cromossomo*>  Populacao::crossover(Populacao p, vector<Cromossomo*> c){
    int tamp = 0;
    double taxa, a;
    vector<Cromossomo*> newC;
    vector<Gene*> g1, g2;
    Cromossomo* p1 = new Cromossomo(p.tamCromossomo);
    Cromossomo* p2 = new Cromossomo(p.tamCromossomo);

    while(tamp<this->tamPopulacao){
        p1 = selecaoTorneio(p, c);
        p2 = selecaoTorneio(p, c);
        g1 = p1->getGenes();
        g2 = p2->getGenes();

        a = ra.Uniform(0.0, 1.0);

        taxa = ra.Uniform(0.0, 1.0);
        Cromossomo* c1 = new Cromossomo(p.tamCromossomo);
        Cromossomo* c2 = new Cromossomo(p.tamCromossomo);

        if(taxa < 0,8){
            for(int j=0; j<p.tamCromossomo; j++){
               c1->inGene((a * g1[j]->getAlelo()) + ((1-a) * g2[j]->getAlelo()));
               c2->inGene((a * g2[j]->getAlelo()) + ((1-a) * g1[j]->getAlelo()));
            }

            newC.push_back(c1);
            newC.push_back(c2);
            tamp +=2;
        } else {
            newC.push_back(p1);
            newC.push_back(p2);
            tamp += 2;
        }
    }

    return newC;
}

double Populacao::mutacao(){
    double taxa, mutacao, newAlelo;
    vector<Gene*> tmpG;

    for(int i=0; i<this->cromossomos.size(); i++){
        tmpG = this->cromossomos[i]->getGenes();
        for(int j=0; j<tmpG.size(); j++){
            taxa = ra.Uniform(0.0, 1.0);

            if(taxa < 0.05){
                mutacao = ra.Normal(0.0, 0.2);
                newAlelo = mutacao + tmpG[j]->getAlelo();

                if(newAlelo < 0){
                    newAlelo = 1+(newAlelo+1);
                } else if(newAlelo > 1){
                    newAlelo = 1-(newAlelo-1);
                }

                tmpG[j]->setAlelo(newAlelo);
            }
        }
    }
}

