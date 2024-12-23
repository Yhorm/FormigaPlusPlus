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
	fase.LerArquivo();
	fase.CriarPlataforma();
	fase.CriarObstaculo();
	fase.CriarInimigosF();
    while (pGerGraf->getOpen())
    {
        EventManager->executar();
        pGerGraf->clean();
		    fase.executar();
		    fase.Gerenciar_colisoes();
        pGerGraf->display();
    }
}
