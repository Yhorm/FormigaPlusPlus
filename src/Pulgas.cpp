#include "../include/Pulgas.h"
Entidades::Personagens::Inimigo::Pulgas::Pulgas(const sf::Vector2f pos, Personagens::Jogador *pP):
	Inimigo(pos,Vector2f(40,35),pP,1)	
{
			id=6;
			textura = pGerGraf->getTexture(Constants::PULGAS_TEXTURE_FILE_PATH);
			entity.setTexture(textura);
 
}

Entidades::Personagens::Inimigo::Pulgas::Pulgas::~Pulgas()
{
		jogador=nullptr;
}

void Entidades::Personagens::Inimigo::Pulgas::move()
{
    float dt = timer.getElapsedTime().asSeconds();
	enum {up = 3, down = 2, left = 1, right = 0, not_move = -1};
	Vector2f motion=getPosition();
    switch(movement_dir)
    {
        case(up) :
            setPosition(motion+Vector2f(0.0f, (Constants::GRAVITY + Constants::F_NORMAL) -Constants::VEL_ENEMY_Y));
            break;
        case(down) :
            setPosition(motion+Vector2f(0.0f, Constants::VEL_ENEMY_Y + (Constants::GRAVITY*0.1)));
            break;
        case(left) :
 			entity.setTextureRect(sf::IntRect(textura->getSize().x,0,-static_cast<int>(textura->getSize().x),static_cast<int>(textura->getSize().y)));
            setPosition(motion+Vector2f(-Constants::VEL_ENEMY_X, 0.0f));
            break;
        case(right) :
 			entity.setTextureRect(sf::IntRect(0, 0,static_cast<int>(textura->getSize().x),static_cast<int>(textura->getSize().y)));
            setPosition(motion+Vector2f(Constants::VEL_ENEMY_X, 0.0f));
            break;
        default:
            break;

    }
    if(dt-previous >= 1.4f)
    {
		previous=dt;
        movement_dir = rand()%4;
		dt=dt-timer.getElapsedTime().asSeconds();
    }
}
void Entidades::Personagens::Inimigo::Pulgas::Pulgas::refresh()
{
   	move();
    if(hitpoints <= 0 && getAlive())
        setAlive(false);
}


void Entidades::Personagens::Inimigo::Pulgas::Pulgas::colision(Entidades::Entidade *entity, sf::Vector2f distance)
{
    float dt = timer.getElapsedTime().asSeconds();
    Identifier::ID id = entity->getId();
    switch(id)
    {
        case(Identifier::ID::player) :
        {
		auto pChar = static_cast<Personagens::Personagem*>(entity);
   		sf::Vector2f charCurPos = pChar->getPosition();
    	sf::Vector2f charCurVel = pChar->getvelFinal(); //se colocar 0.f 0.f ele fica preso igual cola dá pra fazer o obstaculo medio
		sf::Vector2f charSize = pChar->getEntSize();
        if(distance.x > distance.y)
        {
            if(charCurPos.x < getPosition().x)
                charCurPos.x+=distance.x;
            else
                charCurPos.x-=distance.x;
            charCurVel.x = 0.0f;
            pChar->setPosition(charCurPos);
        }
        else
        {
            if(charCurPos.y < getPosition().y)
            {
            	    charCurPos.y+=distance.y;
                    Entidades::Personagens::Jogador *pPlyr = static_cast<Entidades::Personagens::Jogador *>(pChar);
            }
            else
            {
                charCurPos.y-=distance.y;
            }
            charCurVel.y = 0.0f;

            pChar->setVelFinal(charCurVel);
            pChar->setPosition(charCurPos);
        }
	
				if(!jogador->getInAir()&&dt-animation>=1.3){
					animation=dt;
					danificar(jogador);
					dt=dt-timer.getElapsedTime().asSeconds();
				}
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
void Entidades::Personagens::Inimigo::Pulgas::danificar(Jogador* p){
		p->operator--();
}
