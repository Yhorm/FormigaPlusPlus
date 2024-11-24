#include "Jogo.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
Jogo::Jogo():janela("Menu",sf::Vector2u(800,600)){
}
Jogo::~Jogo(){
}

void Jogo::update(){
		janela.Update();

}
void Jogo::executar(){
		while(!GetJanela()->Acabou()){
				update();
				janela.Limpa();
				janela.Desenha_Objt();
				janela.Desenha();
		}
}
