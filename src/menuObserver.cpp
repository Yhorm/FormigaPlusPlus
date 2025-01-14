#include "../include/menuObserver.h"
#include "../include/menu.h"

namespace Observers
{
    menuObserver::menuObserver(Menus::Menu* pM) :
    Observer(),
    p_menu(pM)
    {
    }

    menuObserver::~menuObserver()
    {
        p_menu = nullptr;
    }

    void menuObserver::notifyKeyPress(std::string key)
    {
        if(p_menu == NULL)
        {
            std::cout << "PONTEIRO MENU NULO EM MENUOBSERVER" << endl;
            exit(1);
        }

        if(key == "Up" || key == "W")
        {
            p_menu->selectUp();
        }

        if(key == "Down" || key == "S")
        {
            p_menu->selectDown();
        }

        if(key == "Enter")
        {
            p_menu->executar();
        }
        
    }

    void menuObserver::notifyKeyReleased(std::string key)
    {
    }
}

