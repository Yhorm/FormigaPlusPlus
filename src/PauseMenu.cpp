#include "../include/PauseMenu.h"

namespace Menus
{
    PauseMenu::PauseMenu(States::StateMachine* pSM, Fases::Fase* fase1, Fases::Fase* fase2, Fases::Fase* save) :
        Menu(),
        States::State(pSM,States::StateType::STATE_PAUSED),
        pFase1(fase1),
        pFase2(fase2),
		pSave(save)
    {          
        ElemGraf::Botao* aux = NULL;

        aux = new ElemGraf::Botao(sf::Vector2f(Constants::RES_X/2.0, Constants::RES_Y/2.0), "CONTINUAR");
        botoes.push_back(aux);
        
        aux = new ElemGraf::Botao(sf::Vector2f(Constants::RES_X/2.0, Constants::RES_Y/2.0 + 200), "SALVAR O JOGO");
        botoes.push_back(aux);

        aux = new ElemGraf::Botao(sf::Vector2f(Constants::RES_X/2.0, Constants::RES_Y/2.0 + 400), "SAIR DO JOGO");
        botoes.push_back(aux);

        Cabecalho.setInfo("JOGO PAUSADO");
        
        Cabecalho.setFontSize(Constants::FONT_SIZE*3);

        Cabecalho.setTextPosition(sf::Vector2f(Constants::RES_X - Cabecalho.getSize().x + 400, 0.0f - Cabecalho.getSize().y));
        
        Cabecalho.setStyle(ElemGraf::StyleType::Bold);

        max = 2;  
        
    }
    PauseMenu::~PauseMenu() {}

    void PauseMenu::executar() 
    {
        if(active)
        {
            active = false;
            switch(selected)
            {
                case(0) :
                    changeState(pSM->getLastState());
                    break;
                case(1) :
                    if(pSM->getLastState() == States::StateType::STATE_FASE_1)
                    {
                        pFase1->salvar();
                    }
                    else if(pSM->getLastState() == States::StateType::STATE_FASE_2)
                    {
                        pFase2->salvar();
					}else{
						pSave->salvar();	
					}
					changeState(pSM->getLastState());
                    break;
                case(2) :
                    changeState(States::StateType::STATE_MAIN_MENU);
                    break;
                default :
                    break;
            }
        }
    }
    void PauseMenu::update() 
    {
    }
    void PauseMenu::draw() 
    {
		m_pGerGraf->centralize(Vector2f(m_pGerGraf->getWinSize().x/2,m_pGerGraf->getWinSize().y/2));
        m_pGerGraf->draw(body);
        Cabecalho.draw();

        for(iterator = botoes.begin(); iterator != botoes.end(); iterator++)
        {
            (*iterator)->draw();
        } 
    }

    void PauseMenu::resetState() 
    {
        botoes[selected]->select(false);
        selected = 0;
        botoes[selected]->select(true);
        active = true;
    } 

    void PauseMenu::TriggerMenu()
    {
        if(pSM->getCurState() == States::StateType::STATE_FASE_1 || pSM->getCurState() == States::StateType::STATE_FASE_2 || pSM->getCurState() == States::StateType::STATE_SAVE_FASE)
        {
            changeState(States::StateType::STATE_PAUSED);
        }
    }
}
