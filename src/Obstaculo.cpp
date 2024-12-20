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


