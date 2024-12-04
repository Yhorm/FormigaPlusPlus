#include "Jogo.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
Jogo::Jogo():pGerGraf(pGerGraf->getGerGraf()),
			Envento(Envento->getGerEvent()){
			player1=new Entidades::Personagens::Jogador();
			lista.addEntity(player1);
			Envento->setPlayer1(player1);
}
Jogo::~Jogo(){
}
void Jogo::executar(){
		sf::Event e;
		while(pGerGraf->getOpen()){
				Envento->executar();
				pGerGraf->clean();
				if(pGerGraf->getWindow()->pollEvent(e)){
					if(e.type == sf::Event::Closed){
						} 
				}
				lista.execute(e);
				pGerGraf->display();
				}
}
