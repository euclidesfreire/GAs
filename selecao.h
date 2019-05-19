#ifndef _SELECAO_H_
#define _SELECAO_H_

#include "populacao.h"
#include "Rand.h"
#include "cromossomo.h"
#include "gene.h"
#include <vector>
#include <iostream>

extern Rand ra;

class Selecao {

public:

    Cromossomo* selecaoTorneio(Populacao p, vector<Cromossomo*> c);

};

#endif // _SELECAO_H_

