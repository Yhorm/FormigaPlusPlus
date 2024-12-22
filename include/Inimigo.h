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

                //Estados possíveis de cada inimigo:
                bool hasProjectile;
                bool hasFired;
                bool canMove;
            public:
                Inimigo(const sf::Vector2f pos,
			       	const sf::Vector2f size,
			       	Jogador* pP = NULL,int hp=4);
                ~Inimigo();

                bool CheckRadius(sf::Vector2f posPlayer, sf::Vector2f posEnemy);

                virtual void refresh()=0;
				virtual void danificar(Jogador *p)=0;
                virtual void colision(Entidades::Entidade* entity, sf::Vector2f distance);
                virtual void move()=0;
                void setHasProj(bool hasPrj) { hasProjectile = hasPrj; }

            };
        }
    }
}



