#pragma once
#include "Entidade.h"
#include "Constants.h"

using namespace std;

namespace Entidades
{
	namespace Personagens
	{
		class Personagem : public Entidade
		{
		protected:
			int hitpoints;

			sf::Vector2f velFinal;
            sf::Clock timer;


			bool inAir;
			bool inMovement;

            short direction;
            enum {left = 1, right = 0, not_move = -1};

		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f vel, const int hp = 1, const Identifier::ID i = Identifier::ID::none);
			~Personagem();


			void setHP(const int hp) { hitpoints = hp; }
			const int getHP() const { return hitpoints; }

			void setVelFinal(const sf::Vector2f vel) { velFinal = vel; }
			const sf::Vector2f getvelFinal() const { return velFinal; }
            void setDirection(const short dir = -1) {direction = dir;}
            void setInAir(const bool in) {inAir = in;}

            void refresh(); //virtual void para camera
            virtual void colision(Entidades::Entidade* entity, sf::Vector2f distance) = 0;


		};

	}
}


