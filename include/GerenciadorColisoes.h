//
// Created by Felipe on 04/11/2023.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <set>
#include <cmath>
#include "Entidade.h"
#include "Obstaculo.h"
#include "Personagem.h"
#include "listEntidade.h"
#include "Inimigo.h"
#include "ID.h"
#include "Projetil.h"
using namespace std;


namespace Gerenciadores
{
    class GerenciadorColisoes
    {
    private:
        Listas::listEntidade* lista;
		std::vector<Entidades::Personagens::Inimigo::Inimigo*> LIs;
		std::list<Obstaculos::Obstaculo*> LOs;
		std::set<Projetil::Projetil*> LP;
		Entidades::Personagens::Jogador *pJog1;
		
    public:
        GerenciadorColisoes(Listas::listEntidade* list,Entidades::Personagens::Jogador *jog);
        ~GerenciadorColisoes();

        const sf::Vector2f calcColission(Entidades::Entidade* char1, Entidades::Entidade* char2);
		void tratarColisoesJogsObstacs(); 
		void tratarColisoesJogsInimgs(); 
		void tratarColisoesInimigsInimigs();
		void IncluirInimigo(Entidades::Entidade *pi);
	   	void IncluirObstcaulo(Entidades::Entidade *po);
	   	void IncluirProjetil(Entidades::Entidade *po);
		void execute();
    };
}

using namespace Gerenciadores;



