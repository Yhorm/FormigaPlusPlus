#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Jogador.h"
#include "Constants.h"
#include "Inimigo.h"
#include "Projetil.h"
#include <cmath>
namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigo
        {
            class Joaninha: public Inimigo
            {
			private:
					Projetil::Projetil *P;
            public:
                Joaninha(const sf::Vector2f pos,
			       	const sf::Vector2f size,
			       	Jogador* pP = nullptr,
					Projetil::Projetil* p = nullptr);
                ~Joaninha();

                void refresh();
				void move();
				void fire();
                void colision(Entidades::Entidade* entity, sf::Vector2f distance);
				void danificar(Jogador *p);
            };
        }
    }
}



