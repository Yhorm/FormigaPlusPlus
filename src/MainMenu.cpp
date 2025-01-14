#include "../include/MainMenu.h"
#include "../include/Jogo.h"

namespace Menus
{
    MainMenuState::MainMenuState(States::Jogo* pJ) :
    Menu(),
    States::State(static_cast<States::StateMachine*>(pJ), States::StateType::STATE_MAIN_MENU),
    pJogo(pJ),
    Titulo()
    {
        ElemGraf::Botao* aux = NULL;

        aux = new ElemGraf::Botao(sf::Vector2f(Constants::RES_X/2.0, Constants::RES_Y/2.0), "PLAY");
        botoes.push_back(aux);
        
        aux = new ElemGraf::Botao(sf::Vector2f(Constants::RES_X/2.0, Constants::RES_Y/2.0 + 200), "EXIT GAME");
        botoes.push_back(aux);

        Titulo.setInfo("Formiga++");
        
        Titulo.setFontSize(Constants::FONT_SIZE*3);

        Titulo.setTextPosition(sf::Vector2f(Constants::RES_X - Titulo.getSize().x, 0.0f - Titulo.getSize().y));

        
        Titulo.setStyle(ElemGraf::StyleType::Bold);

        max = 1;   
    }

    MainMenuState::~MainMenuState() {}

    void MainMenuState::executar() 
    {
        if(active)
        {
            active = false;
            switch(selected)
            {
                case(0) :
                    changeState(States::StateType::STATE_STAGE_SELECTION);
                    break;
                case(1) :
                    pJogo->endGame();
                    break;
                default :
                    break;
            }
        }
    }

    void MainMenuState::update() 
    {
        active = true;
    }

    void MainMenuState::draw() 
    {
        updateView();

        m_pGerGraf->draw(body);
        Titulo.draw();

        for(iterator = botoes.begin(); iterator != botoes.end(); iterator++)
        {
            (*iterator)->draw();
        }
    }

    void MainMenuState::resetState() 
    {
        botoes[selected]->select(false);
        selected = 0;
        botoes[selected]->select(true);
    }
}