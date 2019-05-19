#ifndef _MUTACAO_H_
#define _MUTACAO_H_

#include "populacao.h"
#include "Rand.h"
#include "cromossomo.h"
#include "gene.h"
#include "selecao.h"
#include <vector>
#include <iostream>

extern Rand ra;

class Mutacao {

public:

     vector<Gene*> mutacao(Cromossomo* c, int i);

};

#endif // _MUTACAO_H_

