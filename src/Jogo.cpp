#include "../include/Jogo.h"

namespace States
{

    Jogo::Jogo() :
            pGerGraf(pGerGraf->getGerGraf()),
            EventManager(EventManager->getGerEvent())
            {
                State* auxState = NULL;
                auxState = new Fases::PrimeiraFase(this);
                insertState(auxState);
                auxState = new Fases::SegundaFase(this);
                insertState(auxState);
                auxState = static_cast<State*>(new Menus::MainMenuState(this));
                insertState(auxState);
                auxState = static_cast<State*>(new Menus::StageSelection(this));
                insertState(auxState);
                
                auxState = new LoadGame(this, 
                dynamic_cast<Fases::PrimeiraFase*>(m_mapStates[States::STATE_FASE_1] ), 
                dynamic_cast<Fases::SegundaFase*>(m_mapStates[States::STATE_FASE_2]) );

                insertState(auxState);
                auxState = static_cast<State*>(new Menus::PauseMenu( this, 
                dynamic_cast<Fases::Fase*> ( m_mapStates[StateType::STATE_FASE_1] ), 
                dynamic_cast<Fases::Fase*> ( m_mapStates[StateType::STATE_FASE_2] ) ) );

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
