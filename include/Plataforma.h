#pragma once
#include "Obstaculo.h"
#include "Jogador.h"


namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
		private:
				const bool real;
        public:
            Plataforma(const sf::Vector2f pos,
                       const sf::Vector2f size, const bool Preal=true,
                       const sf::Vector2f scale = sf::Vector2f(Constants::SCALE_PLTFRM, Constants::SCALE_PLTFRM),
                       const Identifier::ID i = Identifier::ID::platform);
            ~Plataforma();

            void colision(Entidades::Entidade* entity,
                                  sf::Vector2f distance);

            void obstacular(Entidades::Personagens::Jogador* j);
            void colisionObstacle(sf::Vector2f ds, Personagens::Personagem* pChar);
            void refresh();

        };
    }
} // Entidades
