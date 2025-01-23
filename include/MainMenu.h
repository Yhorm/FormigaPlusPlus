#pragma once
#include "menu.h"
#include "States.h"

namespace States
{
    class Jogo;
}

namespace Menus
{
    class MainMenuState : public Menu, public States::State
    {
        private:
            States::Jogo* pJogo;
            ElemGraf::Text Titulo;

        public:
            MainMenuState(States::Jogo* pJ = nullptr);
            ~MainMenuState();

            void executar();
            void update();
            void draw();


            void resetState();

    };
}
