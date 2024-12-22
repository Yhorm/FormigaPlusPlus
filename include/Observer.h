#pragma once

#include "GerenciadorEventos.h"


namespace Observers
{
    //classe abstrata 
    class Observer
    {
        private:
            Gerenciadores::GerenciadorEventos* pEventos;
        public:
            Observer();
            virtual ~Observer();
            virtual void notifyKeyPress(std::string key) = 0;
            virtual void notifyKeyReleased(std::string key) = 0;
    };
}