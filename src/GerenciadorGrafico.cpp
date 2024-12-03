#include "../include/GerenciadorGrafico.h"

GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGerGraf(nullptr);

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() :
    window(new RenderWindow(VideoMode(1280, 720), "Jogasso", Style::Default)),
	cam(sf::Vector2f(window->getSize().x/2,window->getSize().y/2),sf::Vector2f(window->getSize()))
{
    if (window == nullptr)
    {
        cerr << "ERRO AO INICIALIZAR A JANELA." << endl;
        exit(1);
    }
    else
    {
		window->setView(cam);
        window->setFramerateLimit(60);
    }
}

 Gerenciadores::GerenciadorGrafico::~GerenciadorGrafico()
 {
     if (window != nullptr)
     {
         delete(window);
         window = nullptr;
     }
 }
 GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::getGerGraf()
{
     if (pGerGraf == nullptr)
         pGerGraf = new GerenciadorGrafico;
     return pGerGraf;
}
void Gerenciadores::GerenciadorGrafico::centralize(const Vector2f pos){
	cam.setCenter(sf::Vector2f(pos.x,pos.y));
	window->setView(cam);
}
void Gerenciadores::GerenciadorGrafico::size(const Vector2f tam){
		cam.setSize(sf::Vector2f(tam.x,tam.y));
		window->setView(cam);
}
