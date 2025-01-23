#pragma once

#include "menu.h"
#include "States.h"

namespace Menus
{
    class LoadMenu : public Menu, public States::State
    {
        private:

        public:
            LoadMenu(States::StateMachine* pSM)
    };
}