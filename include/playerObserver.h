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
            Entidades::Personagens::Jogador* pPlayer1;
            Entidades::Personagens::Jogador* pPlayer2;
            std::map<std::string, bool> keysPressed;

            //keys player 1
            std::string jump1;
            std::string left1;
            std::string right1;
            //keys player 2
            std::string jump2;
            std::string left2;
            std::string right2;

        public:
            playerObserver(Gerenciadores::GerenciadorEventos* pGm, Entidades::Personagens::Jogador* pP1 = nullptr, Entidades::Personagens::Jogador* pP2 = nullptr);
            ~playerObserver();

            void notifyKeyPress(std::string key);
            void notifyKeyReleased(std::string key);

            void setPlayer1(Entidades::Personagens::Jogador* pP) { pPlayer1 = pP; };
            void setPlayer2(Entidades::Personagens::Jogador* pP) { pPlayer2 = pP; };
            void setKeysP1(std::string jmp, std::string l, std::string r);
            void setKeysP2(std::string jmp, std::string l, std::string r);
    };
}