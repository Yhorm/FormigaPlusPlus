#include <iostream>
#include "States.h"
#include <map>


#pragma once

namespace States
{
    class StateMachine
    {
        protected:
            States::StateType curState;
            States::StateType lastState;

            std::map<States::StateType, State*> m_mapStates;

        public:
            StateMachine();
            
            virtual ~StateMachine();

            void changeCurState(States::StateType stt) ;
            void execState();
            void updateState() { m_mapStates[curState]->update(); };

            States::StateType getCurState() { return curState; };
            States::StateType getLastState() { return lastState; };
            void insertState(States::State* pSt);
    };

}
