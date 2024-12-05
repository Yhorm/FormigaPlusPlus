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

void GerenciadorColisoes::execute()
{
		for(auto it=lista->getPrim();it!=nullptr;it++){
				if((*it)->getId()==ID::enemy){
						LIs.push_back(static_cast<Entidades::Personagens::Inimigo::Inimigo*>(*it));
				}
				else if((*it)->getId()==ID::platform){
						LOs.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(*it));		
					}
		}
    sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f);

       if(pJog1->getAlive())
        {
		for(auto it=LIs.begin();it!=LIs.end();it++)
            {
					if((*it)){

               	 		if(static_cast<Personagens::Personagem*>(*it)->getAlive())
               			 {
               	    		 ds = calcColission(pJog1, (*it));
               	     		if(ds.x < 0.0f && ds.y < 0.0f)
               	       	  pJog1->colision(*it, ds);
							for(auto itO=LOs.begin();itO!=LOs.end();itO++){
								ds=calcColission((*it),(*itO));	
               	     				if(ds.x < 0.0f && ds.y < 0.0f)
											(*itO)->colision(*it,ds);

               			 	}
               			 }
					}
            }
		for(auto it=LOs.begin();it!=LOs.end();it++){
					if((*it)){
                    	ds = calcColission(pJog1, *it);
                   			 if(ds.x < 0.0f && ds.y < 0.0f)
                    		    (*it)->colision(pJog1, ds);
        			}
			}
		}
}
