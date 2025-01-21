//
// Created by Felipe on 05/11/2023.
//

#include "../include/Obstaculo.h"


Obstaculo::Obstaculo(sf::Vector2f position, sf::Vector2f tam, const sf::Vector2f s ,const Identifier::ID i) :
	danoso(false),
    Entidade(position,tam, i),
    size(tam),
    position(position),
    scale(s)
{
    setSize(size);
}

Obstaculo::~Obstaculo()
{
}

string Obstaculo::salvar(){
		string salvo;
		salvo.clear();
		salvo+=getIdS()+','+getPosition().x+','+getPosition().y+','+getEntSize().x+','+getEntSize().y+'\n';
		cout<<salvo;
		return salvo;
}
