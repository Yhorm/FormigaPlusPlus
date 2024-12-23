#include "../include/Espinhos.h"
Entidades::Obstaculos::Espinhos::Espinhos(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f scale, const Identifier::ID i):
    Obstaculo(pos, size, scale, i),
	danoso(false)
{
		entity.setFillColor(Color::Yellow);
}

Entidades::Obstaculos::Espinhos::~Espinhos()
{
}

void Espinhos::colision(Entidades::Entidade *entity, sf::Vector2f distance)
{
    Identifier::ID id = entity->getId();
    if(id == ID::player)
    {
        colisionObstacle(distance, static_cast<Entidades::Personagens::Personagem*>(entity));
    }
}
void Espinhos::refresh(){
    float dt = timer.getElapsedTime().asSeconds();
    if(dt-previous >= 4.0)
    {
		previous=dt;
		danoso=rand()%2;
		dt=dt-timer.getElapsedTime().asSeconds();
    }

		if(danoso){
			entity.setFillColor(Color::Red);
		}
		else{
			entity.setFillColor(Color::Yellow);
		}
}
void Espinhos::colisionObstacle(sf::Vector2f ds, Personagens::Personagem *pChar)
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
            pChar->setPosition(charCurPos);
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
            pChar->setVelFinal(charCurVel);
            pChar->setPosition(charCurPos);
        }
    }
	if(danoso){
			pChar->setAlive(false);
	}
}

