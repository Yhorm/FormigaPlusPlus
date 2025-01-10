#pragma once

#include <vector>
#include "botao.h"
#include "menuObserver.h"

namespace Menus
{
    class Menu
    {
        protected:
            std::vector<ElemGraf::Botao*> botoes;
            std::vector<ElemGraf::Botao*>::iterator iterator;

            int selected;
            int min;
            int max;

            bool active;

            Observers::menuObserver observadorMenu;
            //sf::Texture background;
            sf::Color cor;
        public:
            Menu();
            virtual ~Menu();

            virtual void executar() = 0;
            //void refresh();

            void selectUp();
            void selectDown();

    };
}
