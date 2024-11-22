#pragma once 
#include <iostream>
template<class T>
class Elemento {
	private: 
		Elemento<T> *frente;
		Elemento<T> *tras;
    	T* pTipo;
	public:
		Elemento():
				frente(nullptr),
				tras(nullptr),
				pTipo(nullptr){}
		~Elemento(){
				frente=nullptr;
				tras=nullptr;
				pTipo=nullptr;
		}
		void setElemento(T *tipo){
				if(tipo!=nullptr)
						pTipo=tipo;
				else
						std::cout<<"Ponteiro nulo";
		}
		void setFrente(Elemento<T> *frente){
				if(frente)
						this->frente=frente;
		}
		void setTras(Elemento<T> *tras){
				if(tras)
						this->tras=tras;
		}
		T* getElemento(){return pTipo;}
		Elemento<T>* getFrente(){return frente;}
		Elemento<T>* getTras(){return tras;}
};

