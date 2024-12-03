#include "Jogo.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
Jogo::Jogo():window(new sf::RenderWindow(sf::VideoMode(800,800),"joguin")),terminar(false){
		for(int i=0;i<100;i++){
		lista.addEntity(new Personagem(window,rand()%100,rand()%100,sf::Color(rand()%255,rand()%255,rand()%255)));
		}
}
Jogo::~Jogo(){
		if(window)
				delete window;
}
void Jogo::executar(){
		sf::Event e;
		while(!terminar){
				window->clear();
				if(window->pollEvent(e)){
					if(e.type == sf::Event::Closed){
							terminar=true;
						} 
				}
				lista.execute(e);
				window->display();
				}
}
