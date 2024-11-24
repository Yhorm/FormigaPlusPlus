#pragma once
#include "Elemento.h"
template<class T>
class Lista {
private: 
    Elemento<T>* pPrimeiro;
    Elemento<T>* pUltimo;
public: 
	Lista():pPrimeiro(nullptr),
		pUltimo(nullptr){
		}
	~Lista(){
			T* aux=pPrimeiro;
			T* aux1=aux;
			while(aux!=nullptr){
					aux1=aux->getFrente();
					delete aux;
					aux=aux1;
			}
	}
	void Adicionar(T* tipo){
			if(tipo){
					Elemento<T> *pElemento=nullptr;
					pElemento= new Elemento<T>;
					pElemento->setElemento(tipo);
					if(pPrimeiro==nullptr){
							pPrimeiro=pElemento;
							pUltimo=pElemento;
					}
					else{
							pUltimo->setFrente(pElemento);
							pElemento->setTras(pUltimo);
							pUltimo=pElemento;
					}
			}

			else std::cerr<<"Erro ponteiro";
	}
	void Remover(T* tipo){
			if(tipo){
					Elemento<T> *pElemento=nullptr;
					pElemento->setElemento(tipo);
			}
	}
	Elemento <T> getPrim()const {return pPrimeiro;}
	Elemento <T> getUltm()const {return pUltimo;}
};

