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
        Gerenciadores::GerenciadorGrafico* pGG = pGG->getGerGraf();
        ElemGraf::Botao* aux = NULL;

        aux = new ElemGraf::Botao(sf::Vector2f(pGG->getWinSize().x/2.0, pGG->getWinSize().y/2.0), "PLAY");
        botoes.push_back(aux);
        aux = new ElemGraf::Botao(sf::Vector2f(pGG->getWinSize().x/2.0, pGG->getWinSize().y/2.0 + 100), "EXIT GAME");
        botoes.push_back(aux);

        Titulo.setInfo("JOGASSO");
        Titulo.setFontSize(Constants::FONT_SIZE*3);
        Titulo.setTextPosition(sf::Vector2f(pGG->getWinSize().x/2.0, 0.0f - pGG->getWinSize().y/2.0));

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
                    changeState(States::StateType::STATE_IN_GAME);
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
        for(iterator = botoes.begin(); iterator != botoes.end(); ++iterator)
        {
            (*iterator)->draw();
        }
    }

    void MainMenuState::resetState() {}
}