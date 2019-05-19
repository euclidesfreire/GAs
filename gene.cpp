#include "gene.h"

using namespace std;


Gene::Gene(double alelo)
{
    this->alelo = alelo;
}

void Gene::setAlelo(double alelo)
{
    this->alelo = alelo;
}

double Gene::getAlelo()
{
    return this->alelo;
}
