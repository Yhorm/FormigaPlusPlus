#pragma once 
#include "Personagem.h"


class Inimigo: public Personagem {
public: 
    
virtual void executar();
    
protected: 
    int nivel_maldade;
};

