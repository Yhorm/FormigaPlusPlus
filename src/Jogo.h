#pragma once 
#include <iostream>
#include "GerenciadorGrafico.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "list.h"
#include "ListPersonagem.h"
#include "Jogador.h"
#include "GerenciadorEventos.h"
class Jogo{
		private:
			Gerenciadores::GerenciadorGrafico *pGerGraf;
			Gerenciadores::GerenciadorEventos *Envento;
			Entidades::Personagens::Jogador *player1;
			Listas::listEntidade lista;
		public:
				Jogo();
				~Jogo();
				void executar();
};
