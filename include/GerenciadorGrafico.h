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
		View cam;
		GerenciadorGrafico();
		static GerenciadorGrafico* pGerGraf;
	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerGraf();
		RenderWindow* getWindow() const { return window; }
		const bool getOpen() const { return window->isOpen(); }
		void draw(Drawable &entity) { window->draw(entity); } // não é uma boa ideia deixar como RectangleShape, usar Drawble &entity 
		void close() { window->close(); }
		void display() { window->display(); }
		void clean() { window->clear(); }
		void centralize(const Vector2f pos);
		void size(const Vector2f tam);
	};


}
using namespace Gerenciadores;
