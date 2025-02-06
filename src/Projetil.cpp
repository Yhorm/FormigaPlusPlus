#include "../include/Projetil.h"

Projetil::Projetil::Projetil(const sf::Vector2f pos,
							 const Personagens::Jogador* p1,
                             const sf::Vector2f s,
                             const Identifier::ID i,
                             const int damage) :
                             Entidade(pos, s, i),
							 ativo(false),
							 p(p1),
							 inicial(Vector2f(0,0)),
							 positionPlayer(Vector2f(0,0))
										
{
		id=4;
		entity.setFillColor(sf::Color::Black);
}


Projetil::Projetil::~Projetil() {}

void Projetil::Projetil::refresh(){
		if(ativo){
				move();
		}
}
void Projetil::Projetil::move()
{
	//enriquecer
	sf::Vector2f motion = getPosition();
	sf::Vector2f direction = positionPlayer - inicial;

	float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (magnitude != 0)
    	direction /= magnitude;

	sf::Vector2f velocity = direction * Constants::VEL_PROJECTILE;

	motion += velocity;

	setPosition(motion);
	
}

void Projetil::Projetil::colision(Entidades::Entidade* entity, sf::Vector2f distance){
    Identifier::ID id = entity->getId();
    switch(id)
    {
        case(Identifier::ID::player) :
        {
			ativo=false;
			static_cast<Personagens::Jogador*>(entity)->operator--();
			static_cast<Personagens::Jogador*>(entity)->operator--();
			static_cast<Personagens::Jogador*>(entity)->operator--();
            break;
        }
        case(Identifier::ID::platform) :
        {
			ativo=false;
            break;
        }
        default:
            break;
    }

}
void Projetil::Projetil::fire(Vector2f pos)
{
		positionPlayer=p->getPosition();
		setPosition(pos);
		inicial=pos;
		ativo=true;
}
string Projetil::Projetil::salvar()
{
		string salvo;
		salvo.clear();
		salvo=to_string(getIdS())+","+to_string(getPosition().x)+","+to_string(getPosition().y)+","+to_string(ativo)+'\n';
		return salvo;
}
