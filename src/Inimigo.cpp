//
// Created by Felipe on 02/11/2023.
//

#include "../include/Inimigo.h"


Personagens::Inimigo::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f size, Personagens::Jogador *pP) :
    Personagens::Personagem(pos, size, sf::Vector2f(Constants::VEL_ENEMY_X, Constants::VEL_ENEMY_Y)),
    jogador(pP),
    //timer(),
    hasFired(false)
{
    srand(time(NULL));
    movement_dir = rand()%4;
    entity.setFillColor(sf::Color::Cyan);
}

Personagens::Inimigo::Inimigo::~Inimigo()
{}


bool Personagens::Inimigo::Inimigo::CheckRadius(sf::Vector2f posPlayer, sf::Vector2f posEnemy)
{
    if(fabs(posPlayer.x - posEnemy.x) < Constants::E_TRGT_RADIUS_X && fabs(posPlayer.y - posEnemy.y) < Constants::E_TRGT_RADIUS_Y)
        return true;
    else
        return false;
}

void Personagens::Inimigo::Inimigo::move()
{
    if(CheckRadius(jogador->getPosition(), getPosition()))
    {
        followPlayer();
    }
    else
    {
        randomMovement();
    }
}


void Personagens::Inimigo::Inimigo::randomMovement()
{
    switch(movement_dir)
    {
        case(up) :
            entity.move(0.0f, -Constants::VEL_ENEMY_Y);
            break;
        case(down) :
            entity.move(0.0f, Constants::VEL_ENEMY_Y);
            break;
        case(left) :
            entity.move(-Constants::VEL_ENEMY_X, 0.0f);
            break;
        case(right) :
            entity.move(Constants::VEL_ENEMY_X, 0.0f);
            break;
        default:
            break;
    }
    float dt = timer.getElapsedTime().asSeconds();
    if(dt >= 1.0f)
    {
        movement_dir = rand()%4;
        timer.restart();
    }
}


void Personagens::Inimigo::Inimigo::followPlayer()
{
    if(jogador->getPosition().x - getPosition().x > 0.0f)
    {
        entity.move(Constants::VEL_ENEMY_X, 0.0f);
    }
    else
    {
        entity.move(-Constants::VEL_ENEMY_X, 0.0f);
    }

    if(jogador->getPosition().y - getPosition().y > 0.0f)
    {
        entity.move(0.0f, Constants::VEL_ENEMY_Y);
    }
    else
    {
        entity.move(0.0f, -Constants::VEL_ENEMY_Y);
    }
}

void Personagens::Inimigo::Inimigo::refresh()
{
    this->draw();
    this->move();
    if(hitpoints == 0 && getAlive())
        setAlive(false);
}


void Personagens::Inimigo::Inimigo::colision(Entidades::Entidade *entity, sf::Vector2f distance)
{
    Identifier::ID id = entity->getId();
    switch(id)
    {
        case(Identifier::ID::player) :
        {
            break;
        }
        case(Identifier::ID::platform) :
        {
            break;
        }
        default:
            break;
    }
}

int Entidades::Personagens::Inimigo::Inimigo::damage(1);
