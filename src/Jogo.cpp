#include "Jogo.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
Jogo::Jogo():janela("Menu",sf::Vector2u(800,600)){
		retangulo.setSize(sf::Vector2f(200,100));
		retangulo.setFillColor(sf::Color::White);
		retangulo3.setSize(sf::Vector2f(200,10));
		retangulo3.setFillColor(sf::Color::Green);
		retangulo3.setPosition(0,0);
		retangulo.setPosition(0,0);
		janela.Adiciona_Objt(&retangulo,1);
		janela.Adiciona_Objt(&retangulo3,0);

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
