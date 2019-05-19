#include "mutacao.h"


using namespace std;

vector<Gene*> Mutacao::mutacao(Cromossomo* c, int i){
    double taxa, mutacao, newAlelo;
    vector<Gene*> tmpG;

        tmpG = c->getGenes();
        for(int j=0; j<tmpG.size(); j++){
            taxa = ra.Uniform(0.0, 1.0);

            if(taxa < 0.02){
                mutacao = ra.Normal(0.0, 0.2);
                newAlelo = mutacao + tmpG[j]->getAlelo();

                if(newAlelo < 0){
                    newAlelo = 1+(newAlelo+1);
                } else if(newAlelo > 1){
                    newAlelo = 1-(newAlelo-1);
                }

                tmpG[j]->setAlelo(newAlelo);

                 return tmpG;
            }
        }
}
