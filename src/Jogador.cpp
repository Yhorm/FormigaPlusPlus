#include "../include/Jogador.h"
#include "../include/GerenciadorEventos.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

Entidades::Personagens::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size, const int hp, Identifier::ID i) :
        EventManager(EventManager->getGerEvent()),
        Personagem(pos, size, sf::Vector2f(Constants::VEL_PLAYER_X, Constants::VEL_PLAYER_Y), hp, i),
		canJump(true),
        damage(true)
        {
		sf::Texture* textura = new sf::Texture();

		if (!textura->loadFromFile("../sprites/Group5.png")) {
			std::cout << "Falha ao carregar textura!" << std::endl;
		}
		entity.setTexture(textura);
        }

Entidades::Personagens::Jogador::~Jogador()
{
}


void Entidades::Personagens::Jogador::move() {
    inMovement = true;
}

void Entidades::Personagens::Jogador::jump() {
    if(canJump)
    {
		inAir=true;
		canJump=false;
		damage=true;
        velFinal.y = -sqrt((2.0f * Constants::GRAVITY * Constants::JMP_HEIGHT));
    }
}

void Personagens::Jogador::colision(Entidades::Entidade *entity, sf::Vector2f distance)
{
    Identifier::ID id = entity->getId();
    switch(id)
    {
        case(Identifier::ID::enemy) :
        {
				if(!canJump && damage){
				Personagem *aux = static_cast<Personagem*>(entity);
				aux->operator--();
				damage=false;
				}
            break;
        }
        case(Identifier::ID::platform) :
        {
            break;
        }
        case(Identifier::ID::projectile) :
        {
        }
        default:
            break;
    }
}

void Personagens::Jogador::refresh()
{	
	
	const sf::Texture *texture = entity.getTexture();
	sf::Vector2f deltaSpeed(0.0f, 0.0f);
    if(inMovement)
    {

        deltaSpeed.x = velFinal.x * Constants::DELTATIME;
        if(direction == 1)//left
        {
    entity.setTextureRect(sf::IntRect(
        texture->getSize().x,  // Posição inicial X: final da textura (direita)
        0,                   // Posição inicial Y: topo da textura
        -static_cast<int>(texture->getSize().x), // Largura negativa para inverter horizontalmente
        static_cast<int>(texture->getSize().y)  // Altura positiva (não inverte verticalmente)
    ));
            deltaSpeed.x *= -1;
        }	else{
		entity.setTextureRect(sf::IntRect(
    	    0,                                    // Posição inicial X: começo da textura
       	 0,                                    // Posição inicial Y: topo da textura
       	 static_cast<int>(texture->getSize().x), // Largura positiva
       	static_cast<int>(texture->getSize().y)  // Altura positiva
   		 ));
		}
	
    }
    const float velY = velFinal.y;
    velFinal.y = velFinal.y + Constants::GRAVITY * Constants::DELTATIME;
   	deltaSpeed.y = velY * Constants::DELTATIME + (Constants::GRAVITY * Constants::DELTATIME * Constants::DELTATIME) / 2.0f;
	if(deltaSpeed.y>30){
			deltaSpeed.y=30;
	}
    setPosition(sf::Vector2f(getPosition().x + deltaSpeed.x, getPosition().y + deltaSpeed.y));

    velFinal.x = Constants::VEL_PLAYER_X;

	pGerGraf->centralize(Vector2f(getPosition()));
	showlife();
	if(hitpoints==0 && getAlive())
			setAlive(false);

}
void Personagens::Jogador::showlife(){
	sf::RectangleShape t;
	t.setFillColor(sf::Color::Yellow);
	t.setSize(Vector2f(15,15));
	for(int i=0;i<getHP();i++)
	{
			t.setPosition(Vector2f(getPosition().x+entity.getSize().x*0.3*i,getPosition().y-entity.getSize().y));
			pGerGraf->draw(t);
	}
}
unsigned int Entidades::Personagens::Jogador::score(0);
unsigned int Entidades::Personagens::Jogador::death_C(0);
