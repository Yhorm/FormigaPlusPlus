/**
 * Project Untitled
 */
#include "Ente.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
int Ente::cont(0);
Ente::Ente():id(cont++){
		retangolo.setFillColor(sf::Color::White);
		retangolo.setSize(sf::Vector2f(200,200));
		retangolo.setPosition(0,0);
}
Ente::~Ente(){
}
void Ente::desenhar(){
		window->Adiciona_Objt(&retangolo,0);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){retangolo.setPosition(retangolo.getPosition().x+4,retangolo.getPosition().y);}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){retangolo.setPosition(retangolo.getPosition().x-4,retangolo.getPosition().y);}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){retangolo.setPosition(retangolo.getPosition().x,retangolo.getPosition().y-4);}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){retangolo.setPosition(retangolo.getPosition().x,retangolo.getPosition().y+4);}
}
