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
            std::string type;
        public:
            Plataforma(const sf::Vector2f pos,
                       const sf::Vector2f size, const std::string t = "",
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
