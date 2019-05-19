#ifndef _CROSSOVER_H_
#define _CROSSOVER_H_

#include "populacao.h"
#include "Rand.h"
#include "cromossomo.h"
#include "gene.h"
#include "selecao.h"
#include <vector>
#include <iostream>

extern Rand ra;

class Crossover {

public:

     vector<Cromossomo*> crossoverAritmetico(Populacao p, vector<Cromossomo*> c);

};

#endif // _CROSSOVER_H_
