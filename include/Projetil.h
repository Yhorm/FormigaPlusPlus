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
            Entidades::Personagens::Jogador* pPlayer;
			bool ativo;
        public:
            Projetil(const sf::Vector2f pos,
                     const sf::Vector2f s = sf::Vector2f(Constants::SIZE_PROJECTILE_X, Constants::SIZE_PROJECTILE_Y),
                     const Identifier::ID i = Identifier::ID::projectile,
                     Identifier::ID frdFrom = Identifier::ID::none,
                     const int damage = Constants::PROJECTILE_DMG_ENEMY);
            ~Projetil();
			void refresh();
            void move();
            void chasePlayer();
			void fire();
            void colision(Entidades::Entidade* entity, sf::Vector2f distance);
        };
    }
}
