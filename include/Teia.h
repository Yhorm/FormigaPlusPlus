#include "Obstaculo.h"
#include "Jogador.h"
namespace Entidades
{
    namespace Obstaculos
    {
        class Teia : public Obstaculo
        {
        protected:
            std::string type;
        public:
            Teia(const sf::Vector2f pos,
                       const sf::Vector2f size, const std::string t = "",
                       const sf::Vector2f scale = sf::Vector2f(Constants::SCALE_PLTFRM, Constants::SCALE_PLTFRM),
                       const Identifier::ID i = Identifier::ID::platform);
            ~Teia();
           	void colision(Entidades::Entidade* entity,
                                  sf::Vector2f distance);
            void colisionObstacle(sf::Vector2f ds, Personagens::Personagem* pChar);
           	void obstacular(Entidades::Personagens::Jogador* j);
            void refresh();

        };
    }
}
