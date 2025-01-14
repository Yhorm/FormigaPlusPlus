#pragma once

#include <iostream>
#include "Observer.h"
#include <map>

namespace Menus
{
    class Menu;
}


namespace Observers
{
    class menuObserver : public Observer
    {
        private:
            Menus::Menu *p_menu;
            
            std::string m_up;
            std::string m_down;

        public:
            menuObserver(Menus::Menu* pM);
            ~menuObserver();

            void notifyKeyPress(std::string key);
            void notifyKeyReleased(std::string key);

            void setMenu(Menus::Menu* pM) {p_menu = pM;}
    };
}