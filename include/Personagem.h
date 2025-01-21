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
		private:
				const Vector2f restartPos;
				const int HPinicial;
		protected:
			int hitpoints;
			sf::Vector2f velFinal;
        	bool alive; // Entidade não tem vida, Personagem tem
			bool inAir;
			bool inMovement;
            short direction;
    		short movement_dir;
		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f vel, const int hp = 5, const Identifier::ID i = Identifier::ID::none);
			virtual ~Personagem();
			void setHP(const int hp) { hitpoints = hp; }
			const int getHP() const { return hitpoints; }
			const Vector2f getRestartPos(){return restartPos;}
			void setVelFinal(const sf::Vector2f vel) { velFinal = vel; }
			const sf::Vector2f getvelFinal() const { return velFinal; }
            void setDirection(const short dir = -1) {direction = dir;}
            void setInAir(const bool in) {inAir = in;}
			const bool getInAir() const {return inAir;}
        	void setAlive(const bool a) { alive = a; }
        	const bool getAlive() const { return alive; }
            void stopMoving() {inMovement = false;
                                setDirection(-1); }
			virtual void move()=0;
			void restart();
            virtual void refresh()=0; 
            virtual void colision(Entidades::Entidade* entity, sf::Vector2f distance) = 0;
				void operator--(){hitpoints--;}
			 string salvar();
		};

	}
}


