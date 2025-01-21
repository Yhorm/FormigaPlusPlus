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
			bool ativo;
			const Personagens::Jogador *p;
			sf::Vector2f positionPlayer;
			Vector2f inicial;
        public:
            Projetil(const sf::Vector2f pos,
					 const Personagens::Jogador* p1,
                     const sf::Vector2f s = sf::Vector2f(Constants::SIZE_PROJECTILE_X, Constants::SIZE_PROJECTILE_Y),
                     const Identifier::ID i = Identifier::ID::projectile,
                     const int damage = Constants::PROJECTILE_DMG_ENEMY);
            ~Projetil();
			void refresh();
            void move();
            void setPlayer(Entidades::Personagens::Jogador* pP) { if(pP) {p = pP;} }
            void chasePlayer();
			void fire(Vector2f pos);
            void colision(Entidades::Entidade* entity, sf::Vector2f distance);
			const bool getAtivo(){return ativo;}
			string salvar();
        };
    }
}
