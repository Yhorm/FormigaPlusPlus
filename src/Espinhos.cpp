#include "../include/Espinhos.h"
Entidades::Obstaculos::Espinhos::Espinhos(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f scale, const Identifier::ID i):
    Obstaculo(pos, size, scale, i),
	danoso(false)
{
		id=3;
}

Entidades::Obstaculos::Espinhos::~Espinhos()
{
}

void Espinhos::colision(Entidades::Entidade *entity, sf::Vector2f distance)
{
    Identifier::ID id = entity->getId();
    if(id != ID::projectile)
    {
        colisionObstacle(distance, static_cast<Entidades::Personagens::Personagem*>(entity));
    }
}
void Espinhos::refresh()
{
    sf::Vector2f curPos = getPosition();
    sf::Vector2f applyGravidade = sf::Vector2f(curPos.x, (curPos.y - (Constants::GRAVITY + Constants::F_NORMAL)));
    setPosition(applyGravidade);

    float dt = timer.getElapsedTime().asSeconds();
    if(dt-previous >= 4.0)
    {
		previous=dt;
		danoso=rand()%2;
		dt=dt-timer.getElapsedTime().asSeconds();
    }

		if(danoso){
		textura = pGerGraf->getTexture(Constants::ESPINHOS_TEXTURE_FILE_PATH);
		entity.setTexture(textura);
		textura->setRepeated(true);
		textura->setSmooth(true);
		entity.setTextureRect(sf::IntRect(0,0,size.x,size.y));
		}
		else{
		textura = pGerGraf->getTexture(Constants::PLATFORM_TEXTURE_FILE_PATH);
		entity.setTexture(textura);
		textura->setRepeated(true);
		textura->setSmooth(true);
		entity.setTextureRect(sf::IntRect(0,0,size.x,size.y));
		}
}
void Espinhos::obstacular(Personagens::Jogador* j){
                    j->setInAir(false);
                    j->setCanJump(true);

}
void Espinhos::colisionObstacle(sf::Vector2f ds, Personagens::Personagem *pChar)
{
    sf::Vector2f charCurPos = pChar->getPosition();
    sf::Vector2f charCurVel = pChar->getvelFinal(); 
	sf::Vector2f charSize = pChar->getEntSize();
    Identifier::ID id = pChar->getId();

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
					obstacular(pPlyr);
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
	if(danoso && id==ID::player){
			pChar->setAlive(false);
	}
}

