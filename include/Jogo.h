#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "Fase.h"
#include "StateMachine.h"
using namespace std;
using namespace sf;

namespace States
{
    class Jogo : public StateMachine 
    {
        private:
            Gerenciadores::GerenciadorGrafico *pGerGraf;
            Gerenciadores::GerenciadorEventos *EventManager;
            Fases::Fase fase;


        public:
                Jogo();

                ~Jogo();

                void instanceEntities();

                void executar();

                void endGame() {pGerGraf->close();};
    };
}

