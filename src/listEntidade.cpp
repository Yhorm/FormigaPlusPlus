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
		if ((aux)->getId() == ID::player){
    		if (!(static_cast<Personagens::Personagem *>(aux)->getAlive())) {
				restart();		
			}
		} 
	if ((aux)->getId() == ID::enemy) {
    	if (!(static_cast<Personagens::Personagem *>(aux)->getAlive())) {
  			nKilled++;
     	return true;
    	}
	}
	if ((aux)->getId() == ID::projectile) {
    	if (!(static_cast<Entidades::Projetil::Projetil*>(aux)->getAtivo())) {
     		return true;
	   }
	}
  return false;
}
void listEntidade::restart(){
		for(auto aux = EntityObjList.getPrim();aux!=nullptr;aux++){
  		if ((*aux)->getId() == ID::enemy || (*aux)->getId() == ID::player ) {
			static_cast<Personagens::Personagem *>(*aux)->restart();
		}
	}
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
void listEntidade::save(){
		FILE *file;
		file=fopen("save.txt","w");
		for(auto aux = EntityObjList.getPrim();aux!=nullptr;aux++){
				fprintf(file,"%s",(*aux)->salvar().c_str());
		}
		fclose(file);
}

const Vector2f listEntidade::lastPla(){
	Vector2f ultima=Vector2f(-1,-1);
	for(auto aux = EntityObjList.getPrim();aux!=nullptr;aux++){
  		if ((*aux)->getIdS() == 1) {
			ultima=(*aux)->getPosition();	
		}
	}
	return ultima;
}
void listEntidade::clear(){
		for(auto i=EntityObjList.getPrim();i!=nullptr;i++)
				delete (*i);
        EntityObjList.clear();//mudei 
}
