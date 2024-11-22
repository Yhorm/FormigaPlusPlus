/**
 * Project Untitled
 */


#ifndef _OBSTACULO_H
#define _OBSTACULO_H

#include "Entidade.h"


class Obstaculo: public Entidade {
public: 
    
virtual virtual void = 0 executar() = 0;
    
/**
 * @param p
 */
virtual virtual void = 0 obstacular(*Jogador p) = 0;
    
void ...();
protected: 
    bool danoso;
    void ...;
};

#endif //_OBSTACULO_H