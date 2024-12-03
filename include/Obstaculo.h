//
// Created by Felipe on 05/11/2023.
//

#pragma once
#include "Jogador.h"
#include "Constants.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidades::Entidade
        {
        protected:
            sf::Vector2f size;
            sf::Vector2f position;

            sf::Vector2f scale;
        public:
            Obstaculo(sf::Vector2f position,
                      sf::Vector2f tam = sf::Vector2f(Constants::SIZE_PLTFORM_W, Constants::SIZE_PLTFORM_H),
                      sf::Vector2f s = sf::Vector2f(Constants::SCALE_PLTFRM, Constants::SCALE_PLTFRM),
                      const Identifier::ID i = Identifier::ID::platform);
            ~Obstaculo();

            virtual void colision(Entidades::Entidade* entity,
                                  sf::Vector2f distance) = 0;
            virtual void colisionObstacle(sf::Vector2f ds, Personagens::Personagem* pChar);
            virtual void refresh() = 0;

            void setScale(const sf::Vector2f s) {scale = s;}
            const sf::Vector2f getScale() const { return scale; }
        };
    }
}

using namespace Obstaculos;

