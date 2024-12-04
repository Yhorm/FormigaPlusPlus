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
	static Gerenciadores::GerenciadorGrafico* pGerGraf;

public:
	Ente();
	~Ente();

	virtual void draw() = 0;
	virtual void refresh() = 0;
};

