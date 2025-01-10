#pragma once

#include "text.h"

namespace ElemGraf
{
    class Botao
    {
        protected:
            Text m_texto;
            bool m_selected;
            
            sf::RectangleShape corpo;
            static Gerenciadores::GerenciadorGrafico* m_pGerGraf;
            //sf::Texture *m_defaultTexture;
            //sf::Texture *m_selectedTexture;

        public:
            Botao(sf::Vector2f pos, std::string info = "");
            ~Botao();

            void select(const bool isSelected);

            void draw();
    };
}