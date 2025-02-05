#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include "Constants.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidades::Entidade
        {
        protected:
			bool danoso;
            sf::Vector2f size;
            sf::Vector2f position;
            sf::Vector2f scale;
        public:
            Obstaculo(sf::Vector2f position,
                      sf::Vector2f tam = sf::Vector2f(Constants::SIZE_PLTFORM_W, Constants::SIZE_PLTFORM_H),
                      sf::Vector2f s = sf::Vector2f(Constants::SCALE_PLTFRM, Constants::SCALE_PLTFRM),
                      const Identifier::ID i = Identifier::ID::platform);
            virtual ~Obstaculo();

            virtual void colision(Entidades::Entidade* entity,
                                  sf::Vector2f distance) = 0;
            virtual void colisionObstacle(sf::Vector2f ds, Personagens::Personagem* pChar)=0;
            virtual void refresh() = 0;
            virtual void obstacular(Entidades::Personagens::Jogador* j) = 0;
			const bool getDanoso(){return danoso;}
            void setScale(const sf::Vector2f s) {scale = s;}
            const sf::Vector2f getScale() const { return scale; }
			string salvar();
        };
    }
}

using namespace Obstaculos;

