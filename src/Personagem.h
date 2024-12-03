#pragma once
#include "GerenciadorGrafico.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
class Personagem{
		private:
			  Gerenciadores::GerenciadorGrafico *window;
				sf::RectangleShape corpo;
				sf::Vector2f posicao;
		public:
				Personagem(Gerenciadores::GerenciadorGrafico *w,float xI=0,float yI=0,sf::Color color=sf::Color::White);
				~Personagem();
				void atualizar(sf::Event envent);
				void desenhar();
};
