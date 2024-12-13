#include "../include/Personagem.h"
Entidades::Personagens::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f vel, const int hp, const Identifier::ID i) :
	Entidade(pos, size, i),
	velFinal(vel),
	previous(0),
	animation(0),
    timer(),
	hitpoints(hp),
    alive(true),
	inMovement(false),
	inAir(false),
    direction(-1)
{
	srand(time(nullptr));
}

Entidades::Personagens::Personagem::~Personagem()
{
		//não fazia sentido 
}
void Entidades::Personagens::Personagem::move()
{
    float dt = timer.getElapsedTime().asSeconds();
	enum {up = 3, down = 2, left = 1, right = 0, not_move = -1};
    if(dt - previous >= 1.4f)
    {
		previous=dt;
        movement_dir = rand()%4;
		dt=dt-timer.getElapsedTime().asSeconds();
    }
    if(dt - animation >= 0.1f)
	{
		animation=dt;
		entity.setFillColor(Color(entity.getFillColor().r,entity.getFillColor().g,entity.getFillColor().b,255));
	}
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
}

