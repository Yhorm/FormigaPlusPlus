//
// Created by Felipe on 04/11/2023.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "listEntidade.h"

using namespace std;


namespace Gerenciadores
{
    class GerenciadorColisoes
    {
    private:
        Listas::listEntidade* listPers;
        Listas::listEntidade* listEnemies;
        Listas::listEntidade* listObstaculo;
    public:
        GerenciadorColisoes(Listas::listEntidade* listaPersonagens, Listas::listEntidade* listEne,Listas::listEntidade* listaObstac);
        ~GerenciadorColisoes();

        const sf::Vector2f calcColission(Entidades::Entidade* char1, Entidades::Entidade* char2);
        void execute();
    };
}

using namespace Gerenciadores;



