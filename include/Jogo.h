#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "Fase.h"
using namespace std;
using namespace sf;

class Jogo {
private:
    Gerenciadores::GerenciadorGrafico *pGerGraf;
    Gerenciadores::GerenciadorEventos *EventManager;
	Fases::Fase fase;
public:
    Jogo();

    ~Jogo();

    void instanceEntities();

    void executar();

};

