//
// Created by Felipe on 01/11/2023.
//

#pragma once
#include <iostream>

//lista template:
using namespace std;

namespace Listas
{
    template <class TYPE>
    class List
    {
    public:
        //class aninhada
        template<class TE> class Elemento
        {
        private:
            Elemento<TE>* pProx;
            Elemento<TE>* pAnt;
            TE* pInfo;
        public:
            Elemento() :
            pProx(NULL),
            pAnt(NULL),
            pInfo(NULL)
            {}
            ~Elemento() {pProx = NULL; pAnt = NULL; pInfo = NULL;}

            //sets e gets
            Elemento<TE>* getProx() {return pProx;}
            Elemento<TE>* getAnt() {return pAnt;}

            void setProx(Elemento<TE>* pEl)
            {
                if(pEl)
                    pProx = pEl;
            }
            void setAnt(Elemento<TE>* pEl)
            {
                if(pEl)
                    pAnt = pEl;
            }

            TE* getInfo() {return pInfo;}
            void setInfo(TE* pI) {
                if (pI)
                    pInfo = pI;
            }
        };
        template<class TE> class Iterator
        {
        private:
            Elemento<TE>* Atual;
        public:
            Iterator(Elemento<TE>* content = NULL) :
            Atual(content)
            {
            }
            ~Iterator()
            {
            }

            Iterator& operator++()
            {
                Atual = Atual->getProx();
                return *this;
            }

            Iterator& operator++(int)
            {
                Atual = Atual->getProx();
                return *this;
            }

            bool operator==(const Elemento<TE>* outro) const {return Atual == outro;}
            bool operator!=(const Elemento<TE>* outro) const {return Atual != outro;}

            void operator=(const Elemento<TE>* outro) { Atual = outro;}

            TE* operator*()
            {
                return Atual->getInfo();
            }
        };

    private:
        Elemento<TYPE>* pPrim;
        Elemento<TYPE>* pAtual;
        unsigned int tamanho;
    public:
        Iterator<TYPE> getPrim() { return Iterator<TYPE>(pPrim); }
        void clear() // Clear não é usado em nenhum momento
        {
            Elemento<TYPE>* aux = nullptr;

            while(pPrim != NULL)
            {
                aux = pPrim;
                pPrim = pPrim->getProx();
				if(aux){
					delete aux->getInfo();
                    delete aux;
				}
            }
            tamanho = 0;
            pPrim = NULL;
            pAtual = NULL;
        }
        const unsigned int getTamanho() const { return tamanho; }

        void push(TYPE* Element)
        {
            if(Element)
            {
                Elemento<TYPE>* aux = new Elemento<TYPE>();
                if(aux)
                {
                    if(!pPrim && !pAtual)
                    {
                        aux->setInfo(Element);
                        aux->setProx(NULL);
                        aux->setAnt(NULL);

                        pPrim = aux;
                        pAtual = aux;
                    }
                    else
                    {
                        aux->setInfo(Element);
						pAtual->setProx(aux);// FALTAVA DEFINIR LISTA COMO pAtual->setProx
                        aux->setAnt(pAtual);
                        aux->setProx(NULL); 
                        pAtual = aux;
                    }
                }
				tamanho++; //retornar tamanho
            }
        }
		void remove(TYPE* Element) {
		    if (!Element) {
       			 return; // Se o elemento não for válido, não faz nada.
    		}

   		 Elemento<TYPE>* atual = pPrim;
    	 // Percorre a lista para encontrar o elemento a ser removido
   		 while (atual != nullptr && atual->getInfo() != Element) {
        	atual = atual->getProx();
    	 }	

  		  // Se o elemento não foi encontrado, sai da função
   	    if (!atual) {
        	return;
   		 }

	    // Ajusta os ponteiros dos elementos vizinhos
	    if (atual->getAnt()) {
	        atual->getAnt()->setProx(atual->getProx());
	    } else {
	        // Se atual é o primeiro elemento
	        pPrim = atual->getProx();
	    }
	
	    if (atual->getProx()) {
	        atual->getProx()->setAnt(atual->getAnt());
	    } else {
	        // Se atual é o último elemento
	        pAtual = atual->getAnt();
	    }
	    // Deleta o elemento
	    	delete atual->getInfo();
	
	    // Diminui o tamanho da lista
	    tamanho--;
		}

    };
}
