/**
 * Project Untitled
 */


#ifndef _INIMIGO_H
#define _INIMIGO_H

#include "Personagem.h"


class Inimigo: public Personagem {
public: 
    
virtual void executar();
    
/**
 * @param p
 */
virtual virtual void = o danificar(*Jogador p) = 0;
protected: 
    int nivel_maldade;
    void ...;
};

#endif //_INIMIGO_H