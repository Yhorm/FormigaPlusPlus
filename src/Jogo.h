#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "Janela.h"
class Jogo {
private:
		Gerenciador::Janela janela;
		sf::RectangleShape retangulo;
		sf::RectangleShape retangulo3;
public: 
		Jogo();
		~Jogo();
		void executar();
		void update();
		Gerenciador::Janela *GetJanela(){return &janela;}
};
