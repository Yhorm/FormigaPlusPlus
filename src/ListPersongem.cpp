#include "ListPersonagem.h"
#include <SFML/Window/Event.hpp>
 
listEntidade::listEntidade() :
        EntityObjList()
{
}
 
listEntidade::~listEntidade()
{
        EntityObjList.clear();//mudei 
}
 
 
void listEntidade::execute(sf::Event event)
{
    auto aux = EntityObjList.getPrim();//auto 
    while(aux != NULL)
    {   
        (*aux)->desenhar();
        (*aux)->atualizar(event);
        aux++;
    }   
}
 

