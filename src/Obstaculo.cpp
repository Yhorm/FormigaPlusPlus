//
// Created by Felipe on 05/11/2023.
//

#include "../include/Obstaculo.h"


Obstaculo::Obstaculo(sf::Vector2f position, sf::Vector2f tam, const sf::Vector2f s ,const Identifier::ID i) :
    Entidade(position,tam, i),
    size(tam),
    position(position),
    scale(s)
{
    setSize(size);
    setPosition(position);
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::colisionObstacle(sf::Vector2f ds, Personagens::Personagem *pChar)
{
    sf::Vector2f charCurPos = pChar->getPosition();
    sf::Vector2f charCurVel = pChar->getvelFinal();
    sf::Vector2f charSize = pChar->getEntSize();

    if(ds.x < 0.0f && ds.y < 0.0f)
    {
        if(ds.x > ds.y)
        {
            if(charCurPos.x < position.x)
                charCurPos.x+=ds.x;
            else
                charCurPos.x-=ds.x;
            charCurVel.x = 0.0f;
        }
        else
        {
            if(charCurPos.y < position.y)
            {
                charCurPos.y+=ds.y;

                if(pChar->getId() == Identifier::ID::player)
                {
                    Entidades::Personagens::Jogador *pPlyr = static_cast<Entidades::Personagens::Jogador *>(pChar);
                    pPlyr->setInAir(false);
                }
            }
            else
            {
                charCurPos.y-=ds.y;
            }
            charCurVel.y = 0.0f;
            pChar->setPosition(charCurPos);
            pChar->setVelFinal(charCurVel);
        }
    }
}

