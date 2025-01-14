#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "PrimeiraFase.h"
#include "SegundaFase.h"
using namespace std;
using namespace sf;

class Jogo {
private:
    Gerenciadores::GerenciadorGrafico *pGerGraf;
    Gerenciadores::GerenciadorEventos *EventManager;
	Fases::SegundaFase fase;
public:
    Jogo();

    ~Jogo();

    void instanceEntities();

    void executar();

};

