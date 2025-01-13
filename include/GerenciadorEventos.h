#pragma once

#include <iostream>
#include <list>
#include <map>

#include "GerenciadorGrafico.h"

namespace Observers
{
    class Observer;
}

namespace Gerenciadores {
    class GerenciadorEventos {
    private:

        //lista de observadores

        std::list<Observers::Observer*> observadores;
        std::list<Observers::Observer*>::iterator iterador;

        //Gerenciador gr�fico:
        GerenciadorGrafico *pGerGraf;

        //Window:
        RenderWindow *pWindow;

        //keymap
        std::map<sf::Keyboard::Key, std::string> keyMap;

        //singleton
        static GerenciadorEventos *pGerEvent;

        GerenciadorEventos();

        enum { left = 1, right = 2 };

    public:
        static GerenciadorEventos *getGerEvent();

        ~GerenciadorEventos();

        void attach(Observers::Observer* pObs) { if (pObs) { observadores.push_back(pObs); } };

        void detach(Observers::Observer* pObs) { if (pObs) { observadores.remove(pObs); } }

        void checaTeclaApertada(sf::Keyboard::Key key);

        void checaTeclaSolta(sf::Keyboard::Key key);

        std::string getKeyAsString(sf::Keyboard::Key key) { return keyMap[key] == ""? "Unknown" : keyMap[key]; };

        void close() { pGerGraf->close(); }

        void executar();

    };
}

