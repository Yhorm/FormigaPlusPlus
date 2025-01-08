#pragma once

#include "GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Constants.h"


namespace ElemGraf
{
    class Text
    {
        private:
            sf::Vector2f m_pos;

            std::string m_info;

            sf::Text m_texto;

            static Gerenciadores::GerenciadorGrafico *m_pGerGraf;

        public:
            Text(sf::Vector2f startPos,std::string info = "");
            ~Text();

            void setInfo(std::string i) {m_info = i; m_texto.setString(i);};
            std::string getInfo() { return m_info; };

            void setFontSize(const float fSize) {m_texto.setCharacterSize(fSize); };
            void setFontColor(unsigned int R, unsigned int G, unsigned int B) { m_texto.setFillColor(sf::Color(R, G, B)); };

            void setTextPosition(sf::Vector2f position) {m_pos = position; m_texto.setPosition(m_pos);};
            sf::Vector2f getPosition() { return m_pos; }
            void draw();

    };
}