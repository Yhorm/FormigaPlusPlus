#pragma once

#include <iostream>
#include <SFML/graphics.hpp>

#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "listEntidade.h"


using namespace std;
using namespace sf;

class Jogo {
private:
    Entidades::Personagens::Jogador* player1;
    //Entidades::Personagens::Jogador* player2;
    Entidades::Personagens::Inimigo::Inimigo* enemy;
    Entidades::Obstaculos::Plataforma* platform;

    Listas::listEntidade listaPersonagens;
    Listas::listEntidade listaInimigos;
    Listas::listEntidade listaObstaculos;

    Gerenciadores::GerenciadorColisoes ColMngr;
    Gerenciadores::GerenciadorGrafico *pGerGraf;
    Gerenciadores::GerenciadorEventos *EventManager;
public:
    Jogo();

    ~Jogo();

    void instanceEntities();

    void executar();

};

