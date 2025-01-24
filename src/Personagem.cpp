#include "../include/Personagem.h"
Entidades::Personagens::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const sf::Vector2f vel, const int hp, const Identifier::ID i) :
	Entidade(pos, size, i),
	velFinal(vel),
	hitpoints(hp),
    alive(true),
	inMovement(false),
	inAir(false),
    direction(-1),
	restartPos(pos),
	HPinicial(hp)
{
	srand(time(nullptr));

}
Entidades::Personagens::Personagem::~Personagem()
{
		//não fazia sentido 
}

void Entidades::Personagens::Personagem::restart(){
		setAlive(true);
		setHP(HPinicial);
		setPosition(restartPos);
}
string Entidades::Personagens::Personagem::salvar(){
		string salvo;
		salvo.clear();
		salvo+=to_string(getIdS())+','+to_string(getRestartPos().x)+','+to_string(getRestartPos().y)+','+to_string(getEntSize().x)+','+to_string(getEntSize().y)+','+to_string(getPosition().x)+','+to_string(getPosition().y)+','+to_string(getHP())+'\n';

		return salvo;
}
