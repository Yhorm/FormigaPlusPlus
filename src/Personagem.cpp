#include "../include/Personagem.h"
Entidades::Personagens::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f vel, const int hp, const Identifier::ID i) :
	Entidade(pos, size, i),
	velFinal(vel),
    timer(),
	hitpoints(hp),
    alive(true),
	inMovement(false),
	inAir(false),
    direction(-1)
{
}

Entidades::Personagens::Personagem::~Personagem()
{
	pGerGraf->size(Vector2f(((float)pGerGraf->getWindow()->getSize().x),((float)pGerGraf->getWindow()->getSize().x))); 
}

