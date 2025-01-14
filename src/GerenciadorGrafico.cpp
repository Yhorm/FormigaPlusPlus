#include "../include/GerenciadorGrafico.h"
#include "../include/Constants.h"

GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGerGraf(nullptr);

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() :
    window(new RenderWindow(VideoMode(Constants::RES_X, Constants::RES_Y), "Formiga++", Style::Close)),
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

sf::Texture* Gerenciadores::GerenciadorGrafico::getTexture(const char* path)
{
    std::map<const char*, sf::Texture*>::iterator iterator = m_textureMap.begin();
    for(iterator; iterator != m_textureMap.end(); ++iterator)
    {
        if(!strcmp(iterator->first, path))
        {
            return iterator->second;
        }
    }

    sf::Texture* newTexture = new sf::Texture();

    if(!newTexture->loadFromFile(path))
    {
        std::cout << "ERRO EM CARREGAR A TEXTURA." << endl;
        exit(1);
    }

    m_textureMap.insert(std::pair<const char*, sf::Texture*>(path, newTexture));

    return newTexture;
}

sf::Font* Gerenciadores::GerenciadorGrafico::getFont(const char* path)
{
    std::map<const char*, sf::Font*>::iterator iterator = m_fontMap.begin();

    for(iterator; iterator != m_fontMap.end(); ++iterator)
    {
        if(!strcmp(iterator->first, path))
        {
            return iterator->second;
        }
    }

    sf::Font* newFont = new sf::Font();

    if(!newFont->loadFromFile(path))
    {
        std::cout << "ERRO EM CARREGAR A FONTE." << endl;
        exit(1);
    }

    m_fontMap.insert(std::pair<const char*, sf::Font*>(path, newFont));
    
    return newFont;
}