#pragma once

#include "text.h"

namespace ElemGraf
{
    class Botao
    {
        protected:
            Text m_texto;
            Text m_selected_Text;
            bool m_selected;

            static Gerenciadores::GerenciadorGrafico* m_pGerGraf;

        public:
            Botao(sf::Vector2f pos, std::string info = "");
            ~Botao();

            void select(const bool isSelected);

            void draw();
    };
}