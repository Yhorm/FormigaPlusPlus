#pragma once
#include "Ente.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <string>

class Menu: public Ente {
private: 
		sf::RectangleShape MenuGrande;
		sf::CircleShape bolinha;
		std::vector<sf::Text> opcoes;
		sf::Font fonte;
		short int opcs;
public: 
		Menu();
		~Menu();
		void renderizar();
		void executar();
};

