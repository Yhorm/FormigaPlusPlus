#include "../include/botao.h"
#include "botao.h"

namespace ElemGraf
{
    Gerenciadores::GerenciadorGrafico* Text::m_pGerGraf = Gerenciadores::GerenciadorGrafico::getGerGraf();

    Botao::Botao(sf::Vector2f pos, std::string info) :
    m_texto(pos, info),
    m_selected(false)
    {
        corpo.setSize(sf::Vector2f(Constants::BUTTON_X, Constants::BUTTON_Y));
        corpo.setOrigin(sf::Vector2f(Constants::BUTTON_X/2, Constants::BUTTON_Y/2));
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
        m_texto.draw();
    }

}