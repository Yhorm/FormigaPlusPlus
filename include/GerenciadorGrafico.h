#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string.h>

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

		std::map<const char*, sf::Texture*> m_textureMap;
		std::map<const char*, sf::Font*> m_fontMap;

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerGraf();
		RenderWindow* getWindow() const { return window; }
		const bool getOpen() const { return window->isOpen(); }
		void draw(Drawable &entity) { window->draw(entity); } // não é uma boa ideia deixar como RectangleShape, usar Drawble &entity obs: funciona p/ texto
		void close() { window->close(); }
		void display() { window->display(); }
		void clean() { window->clear(); }
		void centralize(const Vector2f pos);
		void size(const Vector2f tam);
		sf::Vector2f getWinSize() { return static_cast<sf::Vector2f>(window->getSize()); };
		

		sf::Texture* getTexture(const char* path);
		sf::Font* getFont(const char* path);
	};


}
using namespace Gerenciadores;
