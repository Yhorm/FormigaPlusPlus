#include "Janela.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
namespace Gerenciador{
Janela::Janela(const std::string &titulo,const sf::Vector2u &tam):nome(titulo),tamanho(tam),fullscreen(false),acabou(false),fps_limited(60){
		window.create({tamanho.x,tamanho.y},nome,(fullscreen? sf::Style::Fullscreen : sf::Style::Default));
		window.setFramerateLimit(fps_limited);
		figuras.clear();
}
Janela::~Janela(){
		window.close();
}
void Janela::Limpa(){window.clear(sf::Color::Black);}
void Janela::Desenha(){window.display();}
void Janela::TrocaFullscreen(){
		fullscreen=!fullscreen; 
		window.close();
		window.create({tamanho.x,tamanho.y},nome,(fullscreen? sf::Style::Fullscreen : sf::Style::Default));
		window.setFramerateLimit(fps_limited);
}
void Janela::Update(){
		sf::Event event;
		while(window.pollEvent(event)){
				if(event.type==sf::Event::Closed){
						acabou=true;
				}
				else if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::F5){
						TrocaFullscreen();
				}
		}
}
void Janela::Desenha_Objt(){
		std::sort(figuras.begin(),figuras.end());
		for(const auto i:figuras){
			window.draw(*i.second);
		}
		figuras.clear(); //Não aparece na tela os objetos tem que ser criados e pronto
}
void Janela::Adiciona_Objt(sf::Drawable *algo,const int camada){
		figuras.push_back(std::make_pair(camada,algo));
}
void Janela::setNome(const std::string &titulo){nome=titulo;}
void Janela::setTamnho(sf::Vector2u *tam){tamanho=*tam;}
}
