#include "Ente.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
class Menu : public Ente {
	private:
			sf::Text opc[4];
			sf::Font fonte;
			sf::CircleShape circulo;
	public:
			Menu(sf::Vector2f pos=sf::Vector2f(pGerGraf->getWindow()->getSize().x/2.0,pGerGraf->getWindow()->getSize().y/2.0), int scale=1);
			~Menu();
			void move();
			void selected();
			void draw();
			void refresh();
};
