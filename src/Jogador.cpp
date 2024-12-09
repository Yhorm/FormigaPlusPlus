#include "../include/Jogador.h"
#include "../include/GerenciadorEventos.h"

Entidades::Personagens::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size, const int hp, Identifier::ID i) :
        EventManager(EventManager->getGerEvent()),
        Personagem(pos, size, sf::Vector2f(Constants::VEL_PLAYER_X, Constants::VEL_PLAYER_Y), hp, i),
        doubleJumped(false)
        {
               entity.setFillColor(sf::Color(0, 0, 255));
        }

Entidades::Personagens::Jogador::~Jogador()
{
}


void Entidades::Personagens::Jogador::move() {
    this->inMovement = true;
}

void Entidades::Personagens::Jogador::jump() {
    if(!inAir)
    {
        this->inAir = true;
        velFinal.y = -sqrt((2.0f * Constants::GRAVITY * Constants::JMP_HEIGHT));
    }
}

void Personagens::Jogador::colision(Entidades::Entidade *entity, sf::Vector2f distance)
{
    Identifier::ID id = entity->getId();
    switch(id)
    {
        case(Identifier::ID::enemy) :
        {
            operator--();
            if(hitpoints <= 0)
                setAlive(false);
            break;
        }
        case(Identifier::ID::platform) :
        {
            entity->colision(this, distance);
            break;
        }
        case(Identifier::ID::projectile) :
        {
            operator--();
            if(hitpoints <= 0)
                setAlive(false);
            break;
        }
        default:
            break;
    }
}

void Personagens::Jogador::refresh()
{

	pGerGraf->size(Vector2f(((float)pGerGraf->getWindow()->getSize().x)/Constants::SCALE_CAM,((float)pGerGraf->getWindow()->getSize().x)/Constants::SCALE_CAM)); //TESTE DE CAMERA VALORES ARBITRARIOS
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
    draw();
}
unsigned int Entidades::Personagens::Jogador::score(0);
unsigned int Entidades::Personagens::Jogador::death_C(0);
