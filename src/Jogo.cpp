#include "../include/Jogo.h"
#include "../include/Fase.h"

namespace States
{

    Jogo::Jogo() :
            pGerGraf(pGerGraf->getGerGraf()),
            EventManager(EventManager->getGerEvent())
            {
                States::State* auxState;
                auxState = new Fases::Fase(this);
                insertState(auxState);
                auxState = static_cast<State*>(new Menus::MainMenuState(this));
                insertState(auxState);

                auxState = NULL;

                changeCurState(States::StateType::STATE_MAIN_MENU);

                executar();
            }

    Jogo::~Jogo()
    {
            pGerGraf=nullptr;
            EventManager=nullptr;
    }

    void Jogo::executar()
    {
        while (pGerGraf->getOpen())
        {
            EventManager->executar();
            pGerGraf->clean();

            updateState();
            execState();

            pGerGraf->display();
        }
    }
}
