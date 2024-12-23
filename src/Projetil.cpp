//
// Created by Felipe on 13/11/2023.
//

#include "../include/Projetil.h"

Projetil::Projetil::Projetil(const sf::Vector2f pos, Identifier::ID frdFrom, const int damage) :
                             Entidade(pos, sf::Vector2f(Constants::SIZE_PROJECTILE_X, Constants::SIZE_PROJECTILE_Y), Identifier::ID::projectile),
                             ProjectileDamage(damage),
                             firedFrom(frdFrom)
{
}

Projetil::Projetil::~Projetil() {}

void Projetil::Projetil::move()
{
    sf::Vector2f deltaSpeed(0.0f, 0.0f);
    deltaSpeed.x = Constants::VEL_PROJECTILE * Constants::DELTATIME;

}





