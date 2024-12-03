#include "../include/Personagem.h"

Entidades::Personagens::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f vel, const int hp, const Identifier::ID i) :
	Entidade(pos, size, i),
	velFinal(vel),
	hitpoints(hp),
	inMovement(false),
	inAir(false),
    timer(),
    direction(-1)
{
}

Entidades::Personagens::Personagem::~Personagem()
{
}

void Personagens::Personagem::refresh()
{

    sf::Vector2f deltaSpeed(0.0f, 0.0f);

    if(inMovement)
    {
        deltaSpeed.x = velFinal.x * Constants::DELTATIME;
        if(direction == left)
        {
            deltaSpeed.x *= -1;
        }
    }

    const float velY = velFinal.y;
    velFinal.y = velFinal.y + Constants::GRAVITY * Constants::DELTATIME;
    deltaSpeed.y = velY * Constants::DELTATIME + (Constants::GRAVITY * Constants::DELTATIME * Constants::DELTATIME) / 2.0f;

    setPosition(sf::Vector2f(getPosition().x + deltaSpeed.x, getPosition().y + deltaSpeed.y));

    velFinal.x = Constants::VEL_PLAYER_X;

	pGerGraf->centralize(getPosition());
	pGerGraf->size(Vector2f(((float)pGerGraf->getWindow()->getSize().x)/3,((float)pGerGraf->getWindow()->getSize().x)/3)); //TESTE DE CAMERA VALORES ARBITRARIOS
    draw();
}

