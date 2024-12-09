//
// Created by Felipe on 04/11/2023.
//

#include "../include/listEntidade.h"

using Entidades::Entidade;

listEntidade::listEntidade() : EntityObjList(),nKilled(0) {}

listEntidade::~listEntidade()
{
        EntityObjList.clear();//mudei 
}


const unsigned int listEntidade::getNumKilled()
{
<<<<<<< HEAD
    unsigned int nKilled = 0;
    Listas::List<Entidades::Entidade>::Iterator<Entidades::Entidade> aux = EntityObjList.getPrim();

    while(aux != nullptr)
   	 {
   	 	if((*aux)->getId()==ID::enemy){
   	 	    if(!(static_cast<Personagens::Personagem*>(*aux)->getAlive()))
   	 	    {
   	 	        nKilled++;
   	 	    }
   	 }
   	 	    aux++;
	}
=======
>>>>>>> master
    return nKilled;
}

const bool listEntidade::CleanAlive(Entidade *aux) {
  if ((aux)->getId() == ID::enemy) {
    if (!(static_cast<Personagens::Personagem *>(aux)->getAlive())) {
   		nKilled++;
     	EntityObjList.remove(aux);
		delete aux;
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
		auto next=aux;
		next++;
<<<<<<< HEAD
		if((*aux)->getId()==ID::enemy){
   	 	   	if(!(static_cast<Personagens::Personagem*>(*aux)->getAlive()))
   	 	    {
					EntityObjList.remove(*aux);
					delete *aux;
					aux=next;
					continue;
			}
		}
        (*aux)->draw();
        (*aux)->refresh();
        aux++;
=======
		if(CleanAlive(*aux)){
			aux=next;
		}
   		(*aux)->draw();
        (*aux)->refresh();
>>>>>>> master
		aux=next;
    }
}
