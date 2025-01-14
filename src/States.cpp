#include "../include/States.h"
#include "../include/StateMachine.h"

namespace States
{
    State::State(StateMachine* SM, StateType stt) :
        pSM(SM),
        m_stType(stt)
    {
    }

    State::~State()
    {
        pSM = nullptr;
    }

    void State::changeState(const StateType stt)
    {   
        pSM->changeCurState(stt);
    }
}