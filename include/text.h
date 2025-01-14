#pragma once

#include "GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Constants.h"



namespace ElemGraf
{
    enum StyleType
    {
        DefaultStyle = sf::Text::Regular,
        Bold = sf::Text::Bold 
    };

    class Text
    {
        private:
            sf::Vector2f m_pos;

            std::string m_info;

            sf::Text m_texto;

            static Gerenciadores::GerenciadorGrafico *m_pGerGraf;

        public:
            Text(sf::Vector2f startPos = sf::Vector2f(0.0, 0.0),std::string info = "");
            ~Text();

            void setInfo(std::string i) {m_info = i; m_texto.setString(i);};
            std::string getInfo() { return m_info; };

            void setFontSize(const float fSize) {m_texto.setCharacterSize(fSize); };
            void setFontColor(unsigned int R, unsigned int G, unsigned int B) { m_texto.setFillColor(sf::Color(R, G, B)); };

            sf::Vector2f getSize();

            void setTextPosition(sf::Vector2f position) {m_pos = position; m_texto.setPosition(m_pos);};
            sf::Vector2f getPosition() { return m_pos; }
            
            void setStyle(StyleType t) { m_texto.setStyle(t); }; 

            void draw();

    };
}