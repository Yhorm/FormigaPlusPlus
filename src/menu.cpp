#include "../include/menu.h"

namespace Menus
{
    Menu::Menu() :
    selected(0),
    min(0),
    max(2),
    active(false),
    observadorMenu(this),
    cor(sf::Color::Black)
    {
        botoes.clear();
        iterator = botoes.begin();
    }

    Menu::~Menu()
    {
        ElemGraf::Botao* aux = NULL;
        while(botoes.size() != 0)
        {
            aux = botoes.back();
            delete(aux);
            botoes.pop_back();
        }

        botoes.clear();
    }

    void Menu::selectUp()
    {
        if(active)
        {
            botoes[selected]->select(false);
            selected++;
            if(selected > max)
            {
                selected = min;
            }
            botoes[selected]->select(true);
        }
    }

    void Menu::selectDown()
    {
        if(active)
        {
            botoes[selected]->select(false);
            selected--;
            if(selected < min)
            {
                selected = max;
            }
            botoes[selected]->select(true);
        }
    }
}