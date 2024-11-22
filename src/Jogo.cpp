#include "Jogo.h"
#include <SFML/System/Vector2.hpp>
Jogo::Jogo():janela("Menu",sf::Vector2u(800,600)){
		retangulo.setSize(sf::Vector2f(200,200));
}
Jogo::~Jogo(){
}

void Jogo::update(){
		janela.Update();
}
void Jogo::executar(){
		janela.Limpa();
		janela.Desenha_Objt(retangulo);
		janela.Desenha();
}
