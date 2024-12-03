#include "../include/Jogador.h"
#include "../include/GerenciadorEventos.h"

Entidades::Personagens::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size, const int hp, Identifier::ID i) :
        EventManager(EventManager->getGerEvent()),
        Personagem(pos, size, sf::Vector2f(Constants::VEL_PLAYER_X, Constants::VEL_PLAYER_Y), hp, i),
        doubleJumped(false),
        direction(not_move)
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

unsigned int Entidades::Personagens::Jogador::score(0);
unsigned int Entidades::Personagens::Jogador::death_C(0);
