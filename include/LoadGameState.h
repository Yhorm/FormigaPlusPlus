#pragma once
#include "States.h"
#include "text.h"
#include "fstream"
#include "sstream"

namespace Fases
{
    class Fase;
    class PrimeiraFase;
    class SegundaFase;
}

namespace States
{
    class LoadGame : public State
    {
        private:
            Fases::PrimeiraFase* pFase1;
            Fases::SegundaFase* pFase2;
            //ElemGraf::Text Texto;

        public:
            LoadGame(StateMachine* pSM, Fases::PrimeiraFase* p1, Fases::SegundaFase* p2);
            ~LoadGame();

            void executar();
            void update();
            void draw();

            void resetState();
    };
}