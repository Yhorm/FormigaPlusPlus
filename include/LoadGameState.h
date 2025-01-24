#pragma once
#include "States.h"
#include "text.h"
#include "SaveFase.h"
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
            Fases::SaveFase* pSave;

        public:
            LoadGame(StateMachine* pSM, Fases::SaveFase* p1);
            ~LoadGame();

            void executar();
            void update();
            void draw();

            void resetState();
    };
}
