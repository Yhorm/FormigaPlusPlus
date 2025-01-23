#include "../include/LoadGameState.h"
#include "../include/Fase.h"
#include "../include/PrimeiraFase.h"
#include "../include/SegundaFase.h"

namespace States
{

    LoadGame::LoadGame(StateMachine* pSM, Fases::PrimeiraFase* p1, Fases::SegundaFase* p2) :
        State(pSM, States::StateType::STATE_LOAD_GAME),
        pFase1(p1),
        pFase2(p2)
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
        /*
        FILE* arquivo = fopen("faseSalvada.txt", "r");
        if(arquivo == NULL)
        {
            std::cerr << "Falha em ler arquivo de salvamento." << endl;
        }
        
        int fase;
        fase = fscanf(arquivo, "%d");

        fclose(arquivo);
        pFase = NULL;
        */

       if(pFase1->recuperar())
       {
        changeState(pFase1->getState());
       }
        else
            std::cout << "NÃO CARREGOU A CARALHA DO SAVE" << std::endl;;
            
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