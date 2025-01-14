#pragma once
#include "menu.h"
#include "States.h"

namespace Menus
{
    class StageSelection : public Menu, public States::State
    {
        private:
            ElemGraf::Text Cabecalho;
        public:
            StageSelection(States::StateMachine* pSM);
            ~StageSelection();

            void executar();
            void update();
            void draw();

            void resetState();

    };
}