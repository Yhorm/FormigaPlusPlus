#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "States.h"


namespace Menus
{
    class Menu : public Ente
    {
        private:
            Gerenciadores::GerenciadorEventos* EventManager;

            sf::RenderWindow* pWindow;
        
            States::State curMenu;
        
            //sf::Font fonte;
            //sf::Texture* bg;
            sf::Vector2i mousePos;
            sf::Vector2f mouseCord;

            bool selected;

            std::vector<std::string> options;
            std::vector<sf::Vector2f> optionsCord;
            std::vector<sf::Text> Text;

        public:
            //Menu(sf::Font fPath, sf::Texture* bgPath, sf::Vector2i mPos, sf::Vector2f mCord, const bool s = false);
            
            Menu(sf::Vector2i mPos = {0, 0}, sf::Vector2f mCord = {0, 0}, const bool s = false);
            ~Menu();

            void draw();
            void refresh();
    };
}
