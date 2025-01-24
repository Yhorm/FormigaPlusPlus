#pragma once
#include "list.h"
#include "Entidade.h"
#include "Personagem.h"
#include "Projetil.h"
namespace Listas
{
    class listEntidade
    {
    private:
        List<Entidades::Entidade> EntityObjList;
		unsigned int nKilled;
    public:
        listEntidade();
        ~listEntidade();

        //Adicionar na lista:
        void addEntity(Entidades::Entidade* pEntity) {EntityObjList.push(pEntity);
		}

        //retorna seu tamanho
        const int getSize() const {return EntityObjList.getTamanho();};

        //num de entidades mortas
        const unsigned int getNumKilled();

        //executar chama o draw de cada entidade, o que faz com que todos se movam e se desenhem.

		const bool CleanAlive(Entidades::Entidade* aux);
		void restart();
        void execute();
		void save();
        Listas::List<Entidades::Entidade>::Iterator <Entidades::Entidade> getPrim() { return EntityObjList.getPrim(); }
		void clear();
    };
}

using namespace Listas;

