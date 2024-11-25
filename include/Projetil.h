//
// Created by Felipe on 13/11/2023.
//
#pragma once
#include "Entidade.h"
#include "constants.h"
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
            short ProjectileType;
            short direction;

            Identifier::ID firedFrom;
            Entidade* ProjectileOwner;

            enum {PLAYER = 1, ENEMY = 2, OBSTACLE = 3};
            enum {HOMING = 4, STRAIGHT = 5};
            enum {LEFT = -1, RIGHT = 0};

            Entidades::Personagens::Jogador* pPlayer;

        public:
            Projetil(const sf::Vector2f pos,
                     const sf::Vector2f s = sf::Vector2f(Constants::SIZE_PROJECTILE_X, Constants::SIZE_PROJECTILE_Y),
                     const Identifier::ID i = Identifier::ID::projectile,
                     const short type = STRAIGHT,
                     Identifier::ID frdFrom = Identifier::ID::none,
                     const int damage = Constants::PROJECTILE_DMG_ENEMY);
            ~Projetil();

            void move();
            void colision();

            void setFiredFrom(const Identifier::ID owner) {firedFrom = owner;}
            const Identifier::ID getFiredFrom() const {return firedFrom;}

            void setProjType(const short type) {ProjectileType = type;}
            void setProjVel(const sf::Vector2f vel) {projectileVelocity = vel;}

            const short getProjType() const {return ProjectileType;}
            const sf::Vector2f getProjVel() {return projectileVelocity;}

            void chasePlayer();
            void setPlayer(Entidades::Personagens::Jogador* pP) { if(pP) {pPlayer = pP;} }
        };
    }
}

