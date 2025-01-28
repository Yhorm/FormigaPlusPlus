#include "../include/menuObserver.h"
#include "../include/menu.h"
#include "../include/PauseMenu.h"
#include "../include/Fase.h"
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
        
        if(key == "Escape")
        {
            if(dynamic_cast<Menus::PauseMenu*>(p_menu) != nullptr)
            {
                dynamic_cast<Menus::PauseMenu*>(p_menu)->TriggerMenu();
            }
        }

    }

    void menuObserver::notifyKeyReleased(std::string key)
    {
    }
}

