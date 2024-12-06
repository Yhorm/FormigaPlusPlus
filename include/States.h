#include <iostream>

namespace States
{
    enum Game_State
    {
        STATE_INGAME,
        STATE_PAUSED,
        STATE_MAIN_MENU,
        STATE_OPTIONS_MENU,
        STATE_SAVE_MENU,
        STATE_STAGE_SELECTION
    };

    enum Player_State
    {
        PLAYER_IN_MOVEMENT,
        PLAYER_IDLE,
        PLAYER_JUMPING,
        PLAYER_DOUBLE_JUMPING,
        PLAYER_DASHING
    };
    
}