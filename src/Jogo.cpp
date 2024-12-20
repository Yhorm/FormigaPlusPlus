#include "../include/Jogo.h"
Jogo::Jogo() :
        pGerGraf(pGerGraf->getGerGraf()),
        EventManager(EventManager->getGerEvent())
        {
			executar();
        }

Jogo::~Jogo()
{
		pGerGraf=nullptr;
		EventManager=nullptr;
}

void Jogo::instanceEntities()
{
}
void Jogo::executar()
{

  	EventManager->setPlayer1(fase.getPlayer());
	fase.LerArquivo();
	fase.CriarPlataforma();
	fase.CriarObstaculo();
    while (pGerGraf->getOpen())
    {

        EventManager->executar();
        pGerGraf->clean();
		fase.executar();
		fase.Gerenciar_colisoes();
        pGerGraf->display();
    }
}
