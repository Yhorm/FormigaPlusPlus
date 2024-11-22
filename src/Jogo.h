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
		Janela janela;
		sf::RectangleShape retangulo;
public: 
		Jogo();
		~Jogo();
		void executar();
		void update();
		Janela *GetJanela(){return &janela;}

};
