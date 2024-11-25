#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "Janela.h"
class Ente {
protected: 
   	const int id;
	static int cont;
	static Gerenciador::Janela *window; //criação do ponteiro janela 
public: 
	Ente();
    virtual ~Ente();
	void desenhar(sf::Drawable *algo,const int camada);
	virtual void executar() = 0;
};
