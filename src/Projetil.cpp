#include "../include/Projetil.h"
Projetil::Projetil::Projetil(const sf::Vector2f pos,
							 const Personagens::Jogador* p1,
                             const sf::Vector2f s,
                             const Identifier::ID i,
                             Identifier::ID frdFrom,
                             const int damage) :
                             Entidade(pos, s, i),
							 ativo(false),
							 p(p1),
							 inicial(Vector2f(0,0)),
							 positionPlayer(Vector2f(0,0))
{
		entity.setFillColor(sf::Color::Green);
}

Projetil::Projetil::~Projetil() {}
void Projetil::Projetil::refresh(){
		if(ativo){
				move();
		}
}
void Projetil::Projetil::move()
{   
	sf::Vector2f deltaSpeed(0.0f, 0.0f);
	Vector2f motion(getPosition());
   	if(positionPlayer.x>inicial.x) 
   	{
		motion+=Vector2f(Constants::VEL_PROJECTILE, 0.0f);
   	}
   	else
           motion+=Vector2f(-Constants::VEL_PROJECTILE, 0.0f);

	if(positionPlayer.y>inicial.y) 
   	{
           motion+=Vector2f( 0.0f ,Constants::VEL_PROJECTILE);
   	}else
           motion+=Vector2f( 0.0f ,-Constants::VEL_PROJECTILE);
    setPosition(sf::Vector2f(motion.x, motion.y));
}
void Projetil::Projetil::colision(Entidades::Entidade* entity, sf::Vector2f distance){
    Identifier::ID id = entity->getId();
    switch(id)
    {
        case(Identifier::ID::player) :
        {
			static_cast<Personagens::Jogador*>(entity)->operator--();
			static_cast<Personagens::Jogador*>(entity)->operator--();
			ativo=false;
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
void Projetil::Projetil::fire(Vector2f pos){
		positionPlayer=p->getPosition();
		setPosition(pos);
		inicial=pos;
		ativo=true;
}
