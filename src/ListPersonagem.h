#pragma once
#include "list.h"
#include "Personagem.h"
 
namespace Listas
{
    class listEntidade
    {   
    private:
        List<Personagens::Personagem> EntityObjList;
    public:
        listEntidade();
        ~listEntidade();
 
        //Adicionar na lista:
        void addEntity(Entidades::Personagens::Personagem* pEntity) {EntityObjList.push(pEntity);}
 
        //retorna seu tamanho
        const int getSize() const {return EntityObjList.getTamanho();};
 
        //num de entidades mortas
        const unsigned int getNumKilled();
 
        //executar chama o draw de cada entidade, o que faz com que todos se movam e se desenhem.
 
        void execute(sf::Event event);
        Listas::List<Personagens::Personagem>::Iterator <Personagens::Personagem> getPrim() { return EntityObjList.getPrim(); }
    };  
}
 
using namespace Listas;
