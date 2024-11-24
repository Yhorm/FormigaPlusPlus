/**
 * Project Untitled
 */
#include "Ente.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
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
}
