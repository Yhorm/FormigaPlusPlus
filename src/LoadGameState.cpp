#include "../include/LoadGameState.h"

namespace States
{

    LoadGame::LoadGame(StateMachine* pSM, Fases::SaveFase* p1) :
        State(pSM, States::StateType::STATE_LOAD_GAME),
        pSave(p1)
    {
        /*
        Texto.setInfo("CARREGANDO SAVE");
        
        Texto.setFontSize(Constants::FONT_SIZE*3);

        Texto.setTextPosition(sf::Vector2f(Constants::RES_X - Texto.getSize().x, Constants::RES_Y/2));

        
        Texto.setStyle(ElemGraf::StyleType::Bold);
        */
    }

    LoadGame::~LoadGame()
    {
    }

    void LoadGame::executar() 
    {   
       if(pSave->recuperar())
       {
        changeState(pSave->getState());
       }
       else
            std::cout << "NÃO CARREGOU O SAVE" << std::endl;;
            
    }
    void LoadGame::update() 
    {
    }

    void LoadGame::draw() 
    {
        //Texto.draw();
    }

    void LoadGame::resetState() { this->executar(); }

}
