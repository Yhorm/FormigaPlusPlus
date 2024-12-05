#pragma once


#include "Personagem.h"
#include "Constants.h"
#include <cmath>

using namespace std;

namespace Gerenciadores
{
    class GerenciadorEventos;
}

namespace Entidades {
    namespace Personagens {
        class Jogador : public Personagem {
        private:
            Gerenciadores::GerenciadorEventos *EventManager;
            static unsigned int score;
            static unsigned int death_C;
    		sf::Vector2f deltaSpeed;
            //DOUBLE JUMP P/ DEPOIS.
            bool doubleJumped;

        public:
            Jogador(sf::Vector2f pos = sf::Vector2f(200.f, 200.f), sf::Vector2f size = sf::Vector2f(200.f,200.f),
                    const int hp = 3, Identifier::ID i = Identifier::ID::player);

            ~Jogador();

            Jogador &operator++()
            {
                score += 500;
                return *this;
            }

            Jogador &operator--()
            {
                setHP(hitpoints - 1);
                return *this;
            }

            static const unsigned int getScore() { return score; }

            void move();
            void stopMoving(); 
            void jump();
			void refresh();
            void stopDJumping() { this->doubleJumped = false; }

            void colision(Entidades::Entidade* entity, sf::Vector2f distance);

        };
    }
}
