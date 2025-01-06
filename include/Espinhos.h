#include "Obstaculo.h"
#include "Jogador.h"
namespace Entidades
{
    namespace Obstaculos
    {
        class Espinhos: public Obstaculo
        {
		private:
				bool danoso;
        public:
            Espinhos(const sf::Vector2f pos,
                       const sf::Vector2f size,
                       const sf::Vector2f scale = sf::Vector2f(Constants::SCALE_PLTFRM, Constants::SCALE_PLTFRM),
                       const Identifier::ID i = Identifier::ID::platform);
            ~Espinhos();
           	void colision(Entidades::Entidade* entity,
                                  sf::Vector2f distance);
            void colisionObstacle(sf::Vector2f ds, Personagens::Personagem* pChar);
            void refresh();
        };
    }
}
