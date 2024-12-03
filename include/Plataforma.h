//
// Created by Felipe on 07/11/2023.
//

#pragma once
#include "Obstaculo.h"
#include "Jogador.h"


namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
        protected:
            std::string type;
        public:
            Plataforma(const sf::Vector2f pos,
                       const sf::Vector2f size, const std::string t = "",
                       const sf::Vector2f scale = sf::Vector2f(Constants::SCALE_PLTFRM, Constants::SCALE_PLTFRM),
                       const Identifier::ID i = Identifier::ID::platform);
            ~Plataforma();

            virtual void colision(Entidades::Entidade* entity,
                                  sf::Vector2f distance);

            virtual void refresh() {};

        };
    }
} // Entidades
