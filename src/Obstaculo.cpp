#include "../include/Obstaculo.h"


Obstaculo::Obstaculo(sf::Vector2f position, sf::Vector2f tam, const sf::Vector2f s ,const Identifier::ID i) :
	danoso(false),
    Entidade(position,tam, i),
    size(tam),
    position(position),
    scale(s)
{
    setSize(size);
}

Obstaculo::~Obstaculo()
{
}

string Obstaculo::salvar(){
		string salvo;
		salvo.clear();
		salvo+=to_string(getIdS())+','+to_string(getPosition().x)+','+to_string(getPosition().y)+','+to_string(getEntSize().x)+','+to_string(getEntSize().y)+'\n';
		return salvo;
}
