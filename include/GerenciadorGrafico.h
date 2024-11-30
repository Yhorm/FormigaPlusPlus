#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//Feito utilizando singleton:

using namespace std;
using namespace sf;

namespace Gerenciadores
{
	class GerenciadorGrafico
	{
	private:
		RenderWindow* window;
		static GerenciadorGrafico* pGerGraf;
		GerenciadorGrafico();
	public:
		static GerenciadorGrafico* getGerGraf();
		~GerenciadorGrafico();
		RenderWindow* getWindow() { return window; }
		
		const bool getOpen() const { return window->isOpen(); }

		void draw(Drawable &entity) { window->draw(entity); } // não é uma boa ideia deixar como RectangleShape, usar Drawble &entity 
		void close() { window->close(); }
		void display() { window->display(); }
		void clean() { window->clear(); }
	};


}
using namespace Gerenciadores;
