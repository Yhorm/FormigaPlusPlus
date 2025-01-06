#include "../include/Projetil.h"
#include <SFML/Graphics/Color.hpp>

Projetil::Projetil::Projetil(const sf::Vector2f pos,
                             const sf::Vector2f s,
                             const Identifier::ID i,
                             Identifier::ID frdFrom,
                             const int damage) :
                             Entidade(pos, s, i),
							 ativo(true)
{
		entity.setFillColor(sf::Color::Magenta);
		entity.setSize(Vector2f(200,200));
}

Projetil::Projetil::~Projetil() {}
void Projetil::Projetil::refresh(){
		if(ativo){
				move();
		}
}
void Projetil::Projetil::move()
{   
	float dt = timer.getElapsedTime().asSeconds();
	float x = getPosition().x + 200*dt;
	float y = getPosition().x - 0.5f*200*Constants::GRAVITY*dt*dt;
	setPosition(Vector2f(x,y));
}
void Projetil::Projetil::colision(Entidades::Entidade* entity, sf::Vector2f distance){
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
void Projetil::Projetil::fire(){
		ativo=true;
}
