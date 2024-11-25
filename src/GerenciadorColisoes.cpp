//
// Created by Felipe on 04/11/2023.
//

#include "../include/GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(Listas::listEntidade *listaPersonagens, Listas::listEntidade* listEne, Listas::listEntidade *listaObstac) :
    listPers(listaPersonagens),
    listEnemies(listEne),
    listObstaculo(listaObstac)
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
    if(listObstaculo)
        delete listObstaculo;
    if (listPers)
        delete listPers;
    if (listEnemies)
        delete listEnemies;
}

const sf::Vector2f GerenciadorColisoes::calcColission(Entidades::Entidade *char1, Entidades::Entidade *char2)
{
   sf::Vector2f position1 = char1->getPosition();
   sf::Vector2f position2 = char2->getPosition();

   sf::Vector2f size1 = char1->getEntSize();
   sf::Vector2f size2 = char2->getEntSize();

   sf::Vector2f distanceCenter(
           fabs(((position1.x + size1.x/2.0f) - (position2.x + size2.x/2.0f))),
           fabs(((position1.y + size1.y/2.0f) - (position2.y + size2.y/2.0f)))
           );
    sf::Vector2f somaDasMetades((size1.x/2.0f) + (size2.x/2.0f), (size1.y/2.0f) + (size2.y/2.0f));
    return sf::Vector2f((distanceCenter.x - somaDasMetades.x), (distanceCenter.y - somaDasMetades.y));
}

void GerenciadorColisoes::execute()
{
    Listas::List<Entidades::Entidade> aux;
    Listas::List<Entidades::Entidade>::Iterator<Entidades::Entidade> obs = listObstaculo->getPrim();
    Listas::List<Entidades::Entidade>::Iterator<Entidades::Entidade> enemy = listEnemies->getPrim();
    Listas::List<Entidades::Entidade>::Iterator<Entidades::Entidade> player;
    sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f);

    for(player = listPers->getPrim(); player != nullptr; player++)
    {
        if((*player)->getAlive())
        {
            while(enemy != nullptr)
            {
                if((*enemy)->getAlive())
                {
                    ds = calcColission(*player, *enemy);
                    if(ds.x < 0.0f && ds.y < 0.0f)
                        (*player)->colision(*enemy, ds);
                }
                enemy++;
            }

            while(obs != nullptr)
            {
                if((*obs)->getAlive())
                {
                    ds = calcColission(*player, *obs);
                    if(ds.x < 0.0f && ds.y < 0.0f)
                        (*obs)->colision(*player, ds);
                }
                obs++;
            }
        }
    }

    while(enemy != nullptr)
    {
        if((*enemy)->getAlive())
        {
            while(obs != nullptr)
            {
                if((*obs)->getAlive())
                {
                    ds = calcColission(*enemy, *obs);
                    if(ds.x < 0.0f && ds.y < 0.0f)
                        (*obs)->colision(*enemy, ds);
                }
                obs++;
            }
        }
        enemy++;
    }
}
