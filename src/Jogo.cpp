#include "../include/Jogo.h"


Jogo::Jogo() :
        pGerGraf(pGerGraf->getGerGraf()),
        EventManager(EventManager->getGerEvent()),
        listaPersonagens(),
        listaObstaculos(),
        listaInimigos(),
        ColMngr(&listaPersonagens, &listaInimigos, &listaObstaculos),
		menu()
        {
			executar();
        }

Jogo::~Jogo()
{
}

void Jogo::instanceEntities()
{
    player1 = new Entidades::Personagens::Jogador(sf::Vector2f(500.0f, 100.0f),
                                                                                   sf::Vector2f(Constants::SIZE_PLYR_W, Constants::SIZE_PLYR_H),
                                                                                   1, Identifier::ID::player);

    enemy = new Entidades::Personagens::Inimigo::Inimigo(sf::Vector2f(800.0f, 700.0f),
            sf::Vector2f(Constants::SIZE_ENEMY_W, Constants::SIZE_ENEMY_H),
            player1);
    Entidades::Obstaculos::Plataforma* p1 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(320.0f, 600.0f),
                                                                                  sf::Vector2f(Constants::SIZE_PLTFORM_W, Constants::SIZE_PLTFORM_H));
    Entidades::Obstaculos::Plataforma* p2 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(640.0f, 600.0f),
                                                                                  sf::Vector2f(Constants::SIZE_PLTFORM_W, Constants::SIZE_PLTFORM_H));
    Entidades::Obstaculos::Plataforma* p3 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(960.0f, 600.0f),
                                                                                  sf::Vector2f(Constants::SIZE_PLTFORM_W, Constants::SIZE_PLTFORM_H));
    Entidades::Obstaculos::Plataforma* p4 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(1280.0f, 600.0f),
                                                                                  sf::Vector2f(Constants::SIZE_PLTFORM_W, Constants::SIZE_PLTFORM_H));

    Entidades::Entidade* e1 = static_cast<Entidades::Entidade*>(player1);
    Entidades::Entidade* e2 = static_cast<Entidades::Entidade*>(enemy);
    Entidades::Entidade* e3 = static_cast<Entidades::Entidade*>(p1);
    /*
    Entidades::Entidade* e4 = static_cast<Entidades::Entidade*>(p2);
    Entidades::Entidade* e5 = static_cast<Entidades::Entidade*>(p3);
    Entidades::Entidade* e6 = static_cast<Entidades::Entidade*>(p4);
    */

    listaPersonagens.addEntity(e1);
    listaInimigos.addEntity(e2);

    listaObstaculos.addEntity(e3);
    /*
    listaObstaculos.addEntity(e4);
    listaObstaculos.addEntity(e5);
    listaObstaculos.addEntity(e6);
    */
    EventManager->setPlayer1(player1);

}
void Jogo::executar()
{
    instanceEntities();
    while (pGerGraf->getOpen())
    {
        EventManager->executar();

        pGerGraf->clean();
		menu.draw();
        pGerGraf->display();
    }
}
