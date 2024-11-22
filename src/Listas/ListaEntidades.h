#pragma once
#include "../Entidades/Entidade.h"
#include <list>
class ListaEntidades{
public: 
    
ListaEntidades();
    
~ListaEntidades();
    
private: 
	std::list<Entidade> LEs;
};

