#pragma once

#include "Personagem.h"
#include "../include/playerObserver.h"
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

            Observers::playerObserver Controlador;

            static unsigned int score;
            static unsigned int death_C;

            enum { left = 1, right = 2}; 
            int direction;
            bool damage;
            bool isPlayer2;
            bool inMovement;
            bool canJump;

        public:
            Jogador(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), bool isPlayer2 = false , Gerenciadores::GerenciadorEventos* pGE = nullptr);

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
            void stopMoving() { inMovement = false; }

            void jump();
			void refresh();

            void setDirection(int dir) { direction = dir; };
            void setCanJump(bool jmp) { canJump = jmp; };

            void colision(Entidades::Entidade* entity, sf::Vector2f distance);

        };
    }
}
