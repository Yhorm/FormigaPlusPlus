#include "Jogo.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
Jogo::Jogo():pGerGraf(pGerGraf->getGerGraf()){
		lista.addEntity(new Personagens::Personagem(pGerGraf,rand()%100,rand()%100,sf::Color(rand()%255,rand()%255,rand()%255)));
}
Jogo::~Jogo(){
}
void Jogo::executar(){
		sf::Event e;
		while(pGerGraf->getOpen()){
				pGerGraf->clean();
				if(pGerGraf->getWindow()->pollEvent(e)){
					if(e.type == sf::Event::Closed){
						} 
				}
				lista.execute(e);
				pGerGraf->display();
				}
}
