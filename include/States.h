#include <iostream>
#pragma once

namespace States
{
    class StateMachine; 

    enum States
    {
        NULL_STATE,
        STATE_IN_GAME,
        STATE_PAUSED,
        STATE_IN_MENU,
    
        STATE_MAIN_MENU,
        STATE_SCORE_MENU,
        STATE_SAVE_MENU,
        STATE_STAGE_SELECTION,

        PLAYER_IN_MOVEMENT,
        PLAYER_IDLE,
        PLAYER_JUMPING,
        PLAYER_DOUBLE_JUMPING,
        PLAYER_DASHING,
    
        ENEMY_IDLE,
        ENEMY_CHASING,
        ENEMY_SHOOTING
    };
    
    class State 
    {
        private: 
            StateMachine* pSM;
            States curState;
        public:
            State(StateMachine* SM = nullptr, States stt = NULL_STATE);
            virtual ~State();

            const States getState() const { return curState; };
            void setState(const States stt) { curState = stt; };

            
    };
}