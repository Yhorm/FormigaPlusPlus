//
// Created by Felipe on 13/11/2023.
//

#include "../include/Projetil.h"

Projetil::Projetil::Projetil(const sf::Vector2f pos,
                             const sf::Vector2f s,
                             const Identifier::ID i,
                             const short type,
                             Identifier::ID frdFrom,
                             const int damage) :
                             Entidade(pos, s, i),
                             ProjectileDamage(damage),
                             ProjectileType(type),
                             firedFrom(frdFrom)
{
}

Projetil::Projetil::~Projetil() {
		ProjectileOwner = nullptr;
		pPlayer=nullptr;
}

void Projetil::Projetil::move()
{
    short type = getProjType();
    switch(type)
    {
        case(HOMING) :
        {
            chasePlayer();
            break;
        }
        case(STRAIGHT) :
        {
            sf::Vector2f deltaSpeed(0.0f, 0.0f);
            deltaSpeed.x = Constants::VEL_PROJECTILE * Constants::DELTATIME;
            break;
        }
    }
}

void Projetil::Projetil::chasePlayer()
{
    if(pPlayer->getPosition().x - getPosition().x > 0.0f)
    {
        entity.move(Constants::VEL_PROJECTILE, 0.0f);
    }
    else
    {
        entity.move(-Constants::VEL_PROJECTILE, 0.0f);
    }

    if(pPlayer->getPosition().y - getPosition().y > 0.0f)
    {
        entity.move(0.0f, Constants::VEL_PROJECTILE);
    }
    else
    {
        entity.move(0.0f, -Constants::VEL_PROJECTILE);
    }
}





