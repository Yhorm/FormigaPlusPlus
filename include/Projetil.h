//
// Created by Felipe on 13/11/2023.
//
#pragma once
#include "Entidade.h"
#include "Constants.h"
#include "Jogador.h"


namespace Entidades
{
    namespace Projetil
    {
        class Projetil : public Entidade
        {
        private:
            sf::Vector2f projectileVelocity;

            int ProjectileDamage;

            Identifier::ID firedFrom;
            Entidade* ProjectileOwner;

            Entidades::Personagens::Jogador* pPlayer;

        public:
            Projetil(const sf::Vector2f pos,
                     Identifier::ID frdFrom = Identifier::ID::none,
                     const int damage = Constants::PROJECTILE_DMG_ENEMY);
            ~Projetil();

            void move();
            void colision();

            void setFiredFrom(const Identifier::ID owner) {firedFrom = owner;}
            const Identifier::ID getFiredFrom() const {return firedFrom;}

            void setProjVel(const sf::Vector2f vel) {projectileVelocity = vel;}
            const sf::Vector2f getProjVel() {return projectileVelocity;}

            void setPlayer(Entidades::Personagens::Jogador* pP) { if(pP) {pPlayer = pP;} }
        };
    }
}

