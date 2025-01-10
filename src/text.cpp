#include "../include/text.h"

namespace ElemGraf
{
    Gerenciadores::GerenciadorGrafico* Text::m_pGerGraf = Gerenciadores::GerenciadorGrafico::getGerGraf();

    Text::Text(sf::Vector2f startPos,std::string info) :
    m_pos(startPos),
    m_info(info)
    {   
        m_texto.setString(info);
        m_texto.setPosition(startPos);
        m_texto.setFillColor(sf::Color::White);
        m_texto.setOrigin(0, 0);

        setFontSize(Constants::FONT_SIZE);
    }

    Text::~Text()
    {
    }

    void Text::draw()
    {
        m_pGerGraf->draw(m_texto);
    }
}
