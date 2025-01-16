#pragma once

#include <iostream>
#include "Observer.h"
#include <map>

namespace Entidades
{
    namespace Personagens
    {
        class Jogador;  
    }
}

namespace Observers
{
    class playerObserver : public Observer
    {
        private:
            Entidades::Personagens::Jogador* pPlayer;
            std::map<std::string, bool> keysPressed;
            
            std::string jump;
            std::string left;
            std::string right;

        public:
            playerObserver(Entidades::Personagens::Jogador* pP);
            ~playerObserver();

            void notifyKeyPress(std::string key);
            void notifyKeyReleased(std::string key);

            void setPlayer(Entidades::Personagens::Jogador* pP) { pPlayer = pP; };
            void setKeys(std::string jmp, std::string l, std::string r);
    };
}
