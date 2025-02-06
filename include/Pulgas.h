#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Jogador.h"
#include "Constants.h"
#include "Inimigo.h"
#include <cmath>

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigo
        {
            class Pulgas : public Inimigo
            {
            private: 
                bool goUp;
            public:
                Pulgas(const sf::Vector2f pos,
			       	Jogador* pP = NULL);
                ~Pulgas();

                void refresh();
				void move();
                void colision(Entidades::Entidade* entity, sf::Vector2f distance);
				void danificar(Jogador *p);
            };
        }
    }
}



