#include "../include/Aranhas.h"
Entidades::Personagens::Inimigo::Aranhas::Aranhas(const sf::Vector2f pos,Personagens::Jogador *pP):
	Inimigo(pos,Vector2f(100,100),pP,5),
	bigger(false)	
{
	id=7;
    entity.setFillColor(sf::Color::Magenta);
}

Entidades::Personagens::Inimigo::Aranhas::Aranhas::~Aranhas()
{
		jogador=nullptr;
}

void Entidades::Personagens::Inimigo::Aranhas::move()
{
	sf::Vector2f deltaSpeed(0.0f, 0.0f);
   	const float velY = velFinal.y;
    velFinal.y = velFinal.y + Constants::GRAVITY * Constants::DELTATIME;
   	deltaSpeed.y = velY * Constants::DELTATIME + (Constants::GRAVITY * Constants::DELTATIME * Constants::DELTATIME) / 2.0f;
	Vector2f motion(getPosition());
   	if(jogador->getPosition().x>getPosition().x) 
   	{
           motion+=Vector2f(Constants::VEL_ENEMY_X, 0.0f);
   	}
   	else
           motion+=Vector2f(-Constants::VEL_ENEMY_X, 0.0f);
    setPosition(sf::Vector2f(motion.x + deltaSpeed.x, motion.y + deltaSpeed.y));
}
void Entidades::Personagens::Inimigo::Aranhas::Aranhas::refresh()
{
	changeSize();
   	move();
    if(hitpoints <= 0 && getAlive())
        setAlive(false);
}


void Entidades::Personagens::Inimigo::Aranhas::Aranhas::changeSize(){
	float dt = timer.getElapsedTime().asSeconds();
	if(dt-previous>4.1){
			{
			if(rand()%2==0)
			{
				bigger=true;
			}
			else
				bigger=false;
			}			
			previous=dt;
	}
	if(bigger){
			setSize(Vector2f(200,200));
	}
	else{
			setSize(Vector2f(100,100));
	}
}
void Entidades::Personagens::Inimigo::Aranhas::Aranhas::colision(Entidades::Entidade *entity, sf::Vector2f distance)
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
                    pPlyr->setInAir(false);
                    pPlyr->setCanJump(true);
            }
            else
            {
                charCurPos.y-=getPosition().y;
            }
            charCurVel.y = 0.0f;
            pChar->setVelFinal(charCurVel);
            pChar->setPosition(charCurPos);
        }
		if(charCurPos.y>getPosition().y&&!jogador->getInAir()&&dt-animation>=1.3){
			animation=dt;
			danificar(jogador);
			danificar(jogador);
			dt=dt-timer.getElapsedTime().asSeconds();
		}
           break;
        }
        case(Identifier::ID::enemy) :
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
    		        }
    		        else
    		        {
    		            charCurPos.y-=getPosition().y;
    		        }
    		        charCurVel.y = 0.0f;
    		        pChar->setVelFinal(charCurVel);
    		        pChar->setPosition(charCurPos);
    		    }
    	        break;
        }
        default:
            break;
    }
}
void Entidades::Personagens::Inimigo::Aranhas::danificar(Jogador* p){
		p->operator--();
}
