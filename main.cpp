#include <iostream>
#include "populacao.cpp"
#include "cromossomo.cpp"
#include "avaliacao.cpp"
#include "Rand.cpp"
#include "gene.cpp"
#include "selecao.h"
#include "crossover.h"
#include <vector>
#include <fstream>
using namespace std;

extern Rand ra;

int main(){
    Populacao populacao(256,10);
    Avaliacao fitness;
    int i, j, tempo = 0, tam = populacao.getTamPopulacao();
     //CRIAR ARQUIVO
    ofstream out; // out é uma variavel.
    out.open("grafico.txt"); // o arquivo que será criado;

    while(tempo < 1024){

        //VETOR DE CROMOSSOMO TEMPORARIO
        vector<Cromossomo*> tmpC = populacao.getCromossomos();
        //CALCULO DO FITNESS DA GERAÇÃO PARA CADA CROMOSSOMO
        for(i = 0; i < tam; i++){

           double f = fitness.calcularFitness(tmpC[i]);
           tmpC[i]->setFitness(f);

        }

        //VARIÁVEL COM O INDICE DO CROMOSSOMO DE MELHOR FITNESS
        int selF = 0;
        //CROMOSSOMO COM O MELHOR FITNESS
        Cromossomo* selCromossomo = tmpC[0];
        //PROCURAR O MELHOR CROMOSSOMO
        for(int i = 1; i < tam; i++){
            if(tmpC[i]->getFitness() < tmpC[selF]->getFitness()){
                selF = i;
                selCromossomo = tmpC[selF];
            }
        }

       cout << tmpC[selF]->getFitness() << endl;

       //IMPRIMIR GENES
       vector<Gene*> g;

       g = tmpC[selF]->getGenes();
        double d;
       Avaliacao av;
       for(int k = 0; k<g.size(); k++){
            d = av.decodificar(tmpC[selF], k);
            cout << d << " ";
       }
        cout << endl;
        //GRAVAR NO ARQUIVO
        out<<tmpC[selF]->getFitness()<<"\n";

        tmpC = populacao.crossover(populacao, tmpC);

        populacao.setCromossomos(tmpC);

        populacao.mutacao();

        tmpC = populacao.getCromossomos();

        int r1 = ra.Uniform(0, tam);

        tmpC[r1] = selCromossomo;


        populacao.setCromossomos(tmpC);

        tempo++;
    }
}
