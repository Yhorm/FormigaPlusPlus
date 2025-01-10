#include "../include/GerenciadorGrafico.h"

GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGerGraf(nullptr);

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() :
    window(new RenderWindow(VideoMode(1280, 720), "Jogasso", Style::Default)),
	cam(sf::Vector2f(((float)window->getSize().x)*2,((float)window->getSize().y)*2),Vector2f(window->getSize().x*3,window->getSize().y*3))

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

sf::Texture Gerenciadores::GerenciadorGrafico::getTexture(const char* path)
{
    std::map<const char*, sf::Texture>::iterator it;
}

sf::Font Gerenciadores::GerenciadorGrafico::getFont(const char* path)
{
    std::map<const char*, sf::Font>::iterator it;
}