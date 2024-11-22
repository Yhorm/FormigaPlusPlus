#pragma once
#include "Obstaculo.h"
class Obst_Facil: public Obstaculo {
public: 
    
void executar();
    
/**
 * @param p
 */
private: 
    int elasticidade;
};

