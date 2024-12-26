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
            class Aranhas: public Inimigo
            {
			private:
					bool bigger;
            public:
                Aranhas(const sf::Vector2f pos,
			       	Jogador* pP = nullptr);
                ~Aranhas();

                void refresh();
				void move();
				void changeSize();
                void colision(Entidades::Entidade* entity, sf::Vector2f distance);
				void danificar(Jogador *p);
            };
        }
    }
}



