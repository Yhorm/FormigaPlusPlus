#pragma once 
#include <iostream>
#include "Personagem.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "list.h"
#include "ListPersonagem.h"
class Jogo{
		private:
			sf::RenderWindow *window;
			bool terminar;
			Listas::listEntidade lista;

		public:
				Jogo();
				~Jogo();
				void executar();
};
