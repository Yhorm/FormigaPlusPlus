//
// Created by Felipe on 04/11/2023.
//

#include "../include/listEntidade.h"

listEntidade::listEntidade() : EntityObjList(),nKilled(0) {}

listEntidade::~listEntidade()
{
		for(auto i=EntityObjList.getPrim();i!=nullptr;i++)
				delete (*i);
        EntityObjList.clear();//mudei 
}


const unsigned int listEntidade::getNumKilled()
{
    return nKilled;
}

const bool listEntidade::CleanAlive(Entidade *aux) {
  if ((aux)->getId() == ID::enemy) {
    if (!(static_cast<Personagens::Personagem *>(aux)->getAlive())) {
  		nKilled++;
     	return true;
    }
  }
  return false;
}
void listEntidade::execute()
{
    auto aux = EntityObjList.getPrim();//auto 
    while(aux != nullptr)
    {	
		if(!CleanAlive(*aux)){
		(*aux)->draw();
        (*aux)->refresh();
		}
   		aux++;
    }
}
