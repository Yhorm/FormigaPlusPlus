#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "menu.h"
#include <list>


#include <map>

using namespace std;

namespace Gerenciadores {
    class GerenciadorEventos {
    private:
        //Ponteiros para os jogadores:
        //Entidades::Personagens::Jogador *pPlayer1;
        //Entidades::Personagens::Jogador *pPlayer2;

        //Ponteiro p/ o menu:
        //Menus::Menu* pMenu;
        //lista de observadores
        std::list<Observers::Observer*> observadores;
        std::list<Observers::Observer*>::iterator it;

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

        //void setPlayer1(Entidades::Personagens::Jogador *pP) { pPlayer1 = pP; }

        //void setPlayer2(Entidades::Personagens::Jogador *pP) { pPlayer2 = pP; }

        void attach(Observers::Observer* pObs) { if (pObs) { observadores.push_back(pObs); } };

        void detach(Observers::Observer* pObs) { if (pObs) { observadores.remove(pObs); } }

        void checaTeclaApertada(sf::Keyboard::Key key);

        void checaTeclaSolta(sf::Keyboard::Key key);

        std::string getKeyAsString(sf::Keyboard::Key key) { return keyMap[key] == ""? "Unknown" : keyMap[key]; };

        void close() { pGerGraf->close(); }

        void executar();

    };
}

