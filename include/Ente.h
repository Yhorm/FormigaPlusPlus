#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GerenciadorGrafico.h"
#include "ID.h"


using namespace std;
using namespace sf;

class Ente
{
protected:
	int8_t id;
	static Gerenciadores::GerenciadorGrafico* pGerGraf;
	sf::Texture* textura; 
public:
	Ente();
	~Ente();

	virtual void draw() = 0;
	virtual void refresh() = 0;
	int8_t getIdS(){return id;}
};

