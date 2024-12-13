//
// Created by Felipe on 02/11/2023.
//

#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Jogador.h"
#include "Constants.h"
#include <cmath>

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigo
        {
            class Inimigo : public Personagem
            {
            protected:
                Jogador* jogador;

                //Todos os inimigos darão 1 de dano ao player:
                static int damage;

                //Estados possíveis de cada inimigo:
                bool hasProjectile;
                bool hasFired;
                bool canMove;
            public:
                Inimigo(const sf::Vector2f pos,
			       	const sf::Vector2f size,
			       	Jogador* pP = NULL);
                ~Inimigo();

                bool CheckRadius(sf::Vector2f posPlayer, sf::Vector2f posEnemy);

                void refresh();
                void colision(Entidades::Entidade* entity, sf::Vector2f distance);
                void randomMovement();
                void followPlayer();
                void setHasProj(bool hasPrj) { hasProjectile = hasPrj; }
            };
        }
    }
}



