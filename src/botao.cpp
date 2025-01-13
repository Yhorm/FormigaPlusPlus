#include "../include/botao.h"
#include "botao.h"

namespace ElemGraf
{
    Gerenciadores::GerenciadorGrafico* Botao::m_pGerGraf = Gerenciadores::GerenciadorGrafico::getGerGraf();

    Botao::Botao(sf::Vector2f pos, std::string info) :
        m_texto(pos, info),
        m_selected(false),
        m_selectedHighlight(NULL)
    {
        m_selectedHighlight = m_pGerGraf->getTexture(Constants::BUTTON_SELECTED_FILE_PATH);

        highlight.setSize(sf::Vector2f(Constants::BUTTON_HIGHLIGHT_X, Constants::BUTTON_HIGHLIGHT_Y));

        highlight.setOrigin(sf::Vector2f(Constants::BUTTON_HIGHLIGHT_X/2, Constants::BUTTON_HIGHLIGHT_Y/2));
        
        highlight.setPosition(m_texto.getPosition());

        highlight.setTexture(m_selectedHighlight);

        m_texto.setFontSize(Constants::FONT_SIZE);

        m_texto.setTextPosition(pos);

    }

    Botao::~Botao()
    {}


    void Botao::select(bool isSelected)
    {
        m_selected = isSelected;
    }

    void Botao::draw() 
    {
        if(m_selected)
        {
            m_pGerGraf->draw(highlight);
        }
        m_texto.draw();
    }

}