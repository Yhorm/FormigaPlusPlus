#include "../include/StageSelection.h"

namespace Menus
{
    StageSelection::StageSelection(States::StateMachine* pSM) :
    Menu(),
    States::State(pSM, States::StateType::STATE_STAGE_SELECTION),
    Cabecalho()
    {
        ElemGraf::Botao* aux = NULL;

        aux = new ElemGraf::Botao(sf::Vector2f(Constants::RES_X/2.0, Constants::RES_Y/2.0), "FASE 1");
        botoes.push_back(aux);
        
        aux = new ElemGraf::Botao(sf::Vector2f(Constants::RES_X/2.0, Constants::RES_Y/2.0 + 200), "FASE 2");
        botoes.push_back(aux);

        aux = new ElemGraf::Botao(sf::Vector2f(Constants::RES_X/2.0, Constants::RES_Y/2.0 + 400), "VOLTAR");
        botoes.push_back(aux);

        Cabecalho.setInfo("SELECIONE UMA FASE");
        
        Cabecalho.setFontSize(Constants::FONT_SIZE*3);

        Cabecalho.setTextPosition(sf::Vector2f(Constants::RES_X - Cabecalho.getSize().x + 400, 0.0f - Cabecalho.getSize().y));
        
        Cabecalho.setStyle(ElemGraf::StyleType::Bold);

        max = 2;   
    }

    StageSelection::~StageSelection() {}

    void StageSelection::executar()
    {
        if(active)
        {
            active = false;
            switch(selected)
            {
                case(0) :
                    changeState(States::StateType::STATE_FASE_1);
                    break;
                case(1) :
                    changeState(States::StateType::STATE_FASE_1);
                    break;
                case(2) :
                    changeState(States::StateType::STATE_MAIN_MENU);
                    break;
                default :
                    break;
            }
        }
    }

    void StageSelection::update() { active = true; }
    void StageSelection::draw() 
    { 

        m_pGerGraf->draw(body);
        Cabecalho.draw();

        for(iterator = botoes.begin(); iterator != botoes.end(); iterator++)
        {
            (*iterator)->draw();
        } 


    }

    void StageSelection::resetState()
    {
        botoes[selected]->select(false);
        selected = 0;
        botoes[selected]->select(true);
    }


}