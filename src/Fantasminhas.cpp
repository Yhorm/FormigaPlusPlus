#include "../include/Fantasminhas.h"
Entidades::Personagens::Inimigo::Fantasminhas::Fantasminhas(const sf::Vector2f pos, const sf::Vector2f size, Personagens::Jogador *pP):
	Inimigo(pos,size,pP,1)	
{
    entity.setFillColor(sf::Color::Cyan);
}

Entidades::Personagens::Inimigo::Fantasminhas::Fantasminhas::~Fantasminhas()
{
		jogador=nullptr;
}

void Entidades::Personagens::Inimigo::Fantasminhas::move()
{
    float dt = timer.getElapsedTime().asSeconds();
	enum {up = 3, down = 2, left = 1, right = 0, not_move = -1};
	Vector2f motion=getPosition();
    switch(movement_dir)
    {
        case(up) :
            setPosition(motion+Vector2f(0.0f, -Constants::VEL_ENEMY_Y));
            break;
        case(down) :
            setPosition(motion+Vector2f(0.0f,Constants::VEL_ENEMY_Y));
            break;
        case(left) :
            setPosition(motion+Vector2f(-Constants::VEL_ENEMY_X, 0.0f));
            break;
        case(right) :
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
void Entidades::Personagens::Inimigo::Fantasminhas::Fantasminhas::refresh()
{
   	move();
    if(hitpoints == 0 && getAlive())
        setAlive(false);
}


void Entidades::Personagens::Inimigo::Fantasminhas::Fantasminhas::colision(Entidades::Entidade *entity, sf::Vector2f distance)
{
    float dt = timer.getElapsedTime().asSeconds();
    Identifier::ID id = entity->getId();
    switch(id)
    {
        case(Identifier::ID::player) :
        {
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
void Entidades::Personagens::Inimigo::Fantasminhas::danificar(Jogador* p){
		p->operator--();
}
