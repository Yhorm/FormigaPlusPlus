#pragma once 
#include <iostream>
#include "GerenciadorGrafico.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "list.h"
#include "ListPersonagem.h"
class Jogo{
		private:
			Gerenciadores::GerenciadorGrafico *pGerGraf;
			Listas::listEntidade lista;

		public:
				Jogo();
				~Jogo();
				void executar();
};
