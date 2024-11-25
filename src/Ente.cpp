/**
 * Project Untitled
 */
#include "Ente.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
int Ente::cont(0);
Ente::Ente():id(cont++){
}
Ente::~Ente(){
}
void Ente::desenhar(sf::Drawable *algo,const int camada){
		window->Adiciona_Objt(algo,camada);
}
