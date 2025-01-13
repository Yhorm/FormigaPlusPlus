#include "../include/botao.h"
#include "botao.h"

namespace ElemGraf
{
    Gerenciadores::GerenciadorGrafico* Text::m_pGerGraf = Gerenciadores::GerenciadorGrafico::getGerGraf();

    Botao::Botao(sf::Vector2f pos, std::string info) :
    m_texto(pos, info),
    m_selected(false),
    m_defaultTexture(NULL),
    m_selectedHighlight(NULL)
    {
        corpo.setSize(sf::Vector2f(Constants::BUTTON_X, Constants::BUTTON_Y));
        corpo.setOrigin(sf::Vector2f(Constants::BUTTON_X/2, Constants::BUTTON_Y/2));

        highlight.setSize(sf::Vector2f(Constants::BUTTON_HIGHLIGHT_X, Constants::BUTTON_HIGHLIGHT_Y));
        highlight.setOrigin(sf::Vector2f(Constants::BUTTON_HIGHLIGHT_X/2, Constants::BUTTON_HIGHLIGHT_Y/2));

        m_defaultTexture = m_pGerGraf->getTexture(Constants::BUTTON_DEFAULT_FILE_PATH);
        m_selectedHighlight = m_pGerGraf->getTexture(Constants::BUTTON_SELECTED_FILE_PATH);

        corpo.setTexture(m_defaultTexture);
        highlight.setTexture(m_selectedHighlight);

    }

    Botao::~Botao()
    {}


    void Botao::select(bool isSelected)
    {
        m_selected = isSelected;
    }

    void Botao::draw() 
    {
        m_pGerGraf->draw(corpo);
        if(m_selected)
        {
            m_pGerGraf->draw(highlight);
        }
        m_texto.draw();
    }

}