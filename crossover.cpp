#include "crossover.h"

using namespace std;

vector<Cromossomo*>  Crossover::crossoverAritmetico(Populacao p, vector<Cromossomo*> c){
    int tamp = 0;
    double taxa, a;
    vector<Cromossomo*> newC;
    vector<Gene*> g1, g2;
    Cromossomo* p1 = new Cromossomo(p.getTamCromossomo());
    Cromossomo* p2 = new Cromossomo(p.getTamCromossomo());
    Selecao selecao;

    while(tamp<p.getTamPopulacao()){
        p1 = selecao.selecaoTorneio(p, c);
        p2 = selecao.selecaoTorneio(p, c);
        g1 = p1->getGenes();
        g2 = p2->getGenes();

        a = ra.Uniform(0.0, 1.0);

        taxa = ra.Uniform(0.0, 1.0);
        Cromossomo* c1 = new Cromossomo(p.getTamCromossomo());
        Cromossomo* c2 = new Cromossomo(p.getTamCromossomo());

        if(taxa < 0,8){
            for(int j=0; j<p.getTamCromossomo(); j++){
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
