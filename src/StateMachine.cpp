#include "../include/StateMachine.h"

namespace States
{
    StateMachine::StateMachine() :
        curState(NULL_STATE),
        lastState(NULL_STATE)
    {
    }

    StateMachine::~StateMachine()
    {
        std::map<States::StateType, States::State*>::iterator it;

        for(it = m_mapStates.begin(); it != m_mapStates.end(); ++it)
        {
            delete(it->second);
        }
    }

    void StateMachine::changeCurState(States::StateType stt)
    {  
        lastState = curState;
        curState = stt;
        m_mapStates[curState]->resetState();
    }

    void StateMachine::execState()
    {
        m_mapStates[curState]->draw();
    }

    void StateMachine::insertState(States::State* pSt) 
    {
        if(!pSt)
        {
            std::cout << "ERRO AO ADICIONAR ESTADO NULO EM STATE MACHINE";
            exit(1);
        }

        m_mapStates.insert(std::pair<States::StateType, State*>(pSt->getState(), pSt));
    }

    
}