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

            std::map<States::StateType, State*> m_mapStates;
        public:
            StateMachine();
            
            virtual ~StateMachine();

            void changeCurState(States::StateType stt) ;
            void execState();

            States::StateType getCurState() { return curState; };
            void insertState(States::State* pSt);
    };

}