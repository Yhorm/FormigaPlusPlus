#include "Personagem.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
Personagem::Personagem(Gerenciadores::GerenciadorGrafico *w,float xI,float yI,sf::Color color):posicao(sf::Vector2f(xI,yI)){
		corpo.setSize(sf::Vector2f(rand()%60,20.f));
		corpo.setPosition(posicao);
		corpo.setFillColor(color);
		window=w;
}
Personagem::~Personagem(){

}
void Personagem::atualizar(sf::Event event){
			if(event.type == sf::Event::KeyPressed){
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
							posicao.x-=1.5;
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
							posicao.x+=1.5;
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
								posicao.y-=1.5;
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
								posicao.y+=1.5;
				}
		window->centralize(Vector2f(corpo.getPosition().x,corpo.getPosition().y));
		window->size(Vector2f(corpo.getSize().x+100,corpo.getSize().y+100));
		corpo.setPosition(posicao);
}
void Personagem::desenhar(){
		window->draw(corpo);
}
