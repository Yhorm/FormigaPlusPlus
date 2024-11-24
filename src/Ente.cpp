/**
 * Project Untitled
 */
#include "Ente.h"
int Ente::cont(0);
Gerenciador::Janela *Ente::window = Gerenciador::Janela::getJanela("Jogo",sf::Vector2u(800,600));
Ente::Ente():id(cont++){
}
Ente::~Ente(){
}
