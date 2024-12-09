//
// Created by Felipe on 04/11/2023.
//

#include "../include/GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(Listas::listEntidade *list,Entidades::Personagens::Jogador *jog) :
    lista(list),
	pJog1(jog)
{
	LIs.clear();
	LOs.clear();
}

GerenciadorColisoes::~GerenciadorColisoes()
{
		
		//Não faz sentido deletar era o problema de FREE()
		// Era um objeto estatico não teria necessidade
}

const sf::Vector2f GerenciadorColisoes::calcColission(Entidades::Entidade *char1, Entidades::Entidade *char2)
{
   sf::Vector2f position1 = char1->getPosition();
   sf::Vector2f position2 = char2->getPosition();

   sf::Vector2f size1 = char1->getEntSize();
   sf::Vector2f size2 = char2->getEntSize();

   sf::Vector2f distanceCenter(
           fabs(((position1.x + size1.x/2.0f) - (position2.x + size2.x/2.0f))),
           fabs(((position1.y + size1.y/2.0f) - (position2.y + size2.y/2.0f)))
           );
    sf::Vector2f somaDasMetades((size1.x/2.0f) + (size2.x/2.0f), (size1.y/2.0f) + (size2.y/2.0f));
    return sf::Vector2f((distanceCenter.x - somaDasMetades.x), (distanceCenter.y - somaDasMetades.y));
}
void GerenciadorColisoes::tratarColisoesJogsObstacs(){
    sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f);
	for(auto it=LOs.begin();it!=LOs.end();it++){
					if((*it)){
            			ds = calcColission(pJog1, *it);
                   		if(ds.x < 0.0f && ds.y < 0.0f)
                    		(*it)->colision(pJog1, ds);
        			}
			}
}
void GerenciadorColisoes::tratarColisoesJogsInimgs(){
    	sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f);
		for(auto enemy=LIs.begin();enemy!=LIs.end();enemy++)
            {
					if((*enemy)){
               	 		if((*enemy)->getAlive())
               			 {
               	    		 ds = calcColission(pJog1, (*enemy));
               	     		if(ds.x < 0.0f && ds.y < 0.0f)
               	       	  		pJog1->colision(*enemy, ds);

							//tava travando muito quando analisava o enemy com a plataforma
							//sla nao entendi (?????)
               			 }
					}
            }
}
void GerenciadorColisoes::IncluirInimigo(Entidades::Entidade *pi){
	if((pi)->getId()==ID::enemy){
		LIs.push_back(static_cast<Entidades::Personagens::Inimigo::Inimigo*>(pi));
	}
}
void GerenciadorColisoes::IncluirObstcaulo(Entidades::Entidade *po){
	if((po)->getId()==ID::platform){
		LOs.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(po));		
	}	
}
void GerenciadorColisoes::execute()
{
		for(auto it=lista->getPrim();it!=nullptr;it++){
				IncluirInimigo(*it);
				IncluirObstcaulo(*it);
		}

       if(pJog1->getAlive())
        {
				tratarColisoesJogsInimgs();
				tratarColisoesJogsObstacs();
		}
}
