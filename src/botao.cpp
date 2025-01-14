#include "../include/botao.h"
#include "botao.h"

namespace ElemGraf
{
    Gerenciadores::GerenciadorGrafico* Botao::m_pGerGraf = Gerenciadores::GerenciadorGrafico::getGerGraf();

    Botao::Botao(sf::Vector2f pos, std::string info) :
        m_texto(pos, info),
        m_selected(false),
        m_selected_Text(pos, info)
    {
        m_texto.setFontSize(Constants::FONT_SIZE);

        m_texto.setTextPosition(pos);
    }

    Botao::~Botao()
    {}


    void Botao::select(bool isSelected)
    {
        m_selected = isSelected;
        if(m_selected)
            m_texto.setStyle(ElemGraf::Bold);
        else
            m_texto.setStyle(ElemGraf::DefaultStyle);
    }

    void Botao::draw() 
    {
        m_texto.draw();
    }

}