//
// Created by Felipe on 07/11/2023.
//

#include "../include/Plataforma.h"


Entidades::Obstaculos::Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f size, const std::string t, const sf::Vector2f scale, const Identifier::ID i) :
    Obstaculo(pos, size, scale, i),
    type(t)
{
}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void Plataforma::colision(Entidades::Entidade *entity, sf::Vector2f distance)
{
    Identifier::ID id = entity->getId();
    if(id != Identifier::ID::projectile)
    {
        colisionObstacle(distance, static_cast<Entidades::Personagens::Personagem*>(entity));
    }
}
