#pragma once

#include <vector>
#include "botao.h"
#include "menuObserver.h"
#include "GerenciadorGrafico.h"

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

            Gerenciadores::GerenciadorGrafico* m_pGerGraf;
           // sf::Texture* background;
            sf::RectangleShape body;

        public:
            Menu();
            virtual ~Menu();

            virtual void executar() = 0;
            //void refresh();
            void updateView();
            
            void selectUp();
            void selectDown();

    };
}
