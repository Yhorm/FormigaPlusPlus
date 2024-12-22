#include "../include/Personagem.h"
Entidades::Personagens::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f vel, const int hp, const Identifier::ID i) :
	Entidade(pos, size, i),
	velFinal(vel),
	previous(0),
	animation(0),
    timer(),
	hitpoints(hp),
    alive(true),
	inMovement(false),
	inAir(false),
    direction(-1),
	restartPos(pos),
	HPinicial(hp)
{
	srand(time(nullptr));

}
Entidades::Personagens::Personagem::~Personagem()
{
		//não fazia sentido 
}

void Entidades::Personagens::Personagem::restart(){
		setAlive(true);
		setHP(HPinicial);
		setPosition(restartPos);
}

