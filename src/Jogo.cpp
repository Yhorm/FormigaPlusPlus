#include "Jogo.h"
#include "Janela.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
Gerenciador::Janela Jogo::janela("Menu",sf::Vector2u(200,200));
Gerenciador::Janela* Ente::window = Jogo::GetJanela();
Jogo::Jogo(){
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
				t.desenhar();
				janela.Desenha_Objt();
				janela.Desenha();
		}
}
