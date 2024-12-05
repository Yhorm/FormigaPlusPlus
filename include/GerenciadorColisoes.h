//
// Created by Felipe on 04/11/2023.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <cmath>
#include "Entidade.h"
#include "Obstaculo.h"
#include "Personagem.h"
#include "listEntidade.h"
#include "Inimigo.h"
#include "ID.h"

using namespace std;


namespace Gerenciadores
{
    class GerenciadorColisoes
    {
    private:
        Listas::listEntidade* lista;
		std::vector<Entidades::Personagens::Inimigo::Inimigo*> LIs;
		std::list<Obstaculos::Obstaculo*> LOs;
		Entidades::Personagens::Jogador *pJog1;
		
    public:
        GerenciadorColisoes(Listas::listEntidade* list,Entidades::Personagens::Jogador *jog);
        ~GerenciadorColisoes();

        const sf::Vector2f calcColission(Entidades::Entidade* char1, Entidades::Entidade* char2);
        void execute();
    };
}

using namespace Gerenciadores;



