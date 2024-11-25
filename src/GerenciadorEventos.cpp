#include "../include/GerenciadorEventos.h"

GerenciadorEventos* Gerenciadores::GerenciadorEventos::pGerEvent(nullptr);

Gerenciadores::GerenciadorEventos::GerenciadorEventos() :
	pGerGraf(pGerGraf->getGerGraf()),
	pPlayer1(nullptr),
	pPlayer2(nullptr),
	pWindow(pGerGraf->getWindow())
{
}

Gerenciadores::GerenciadorEventos::~GerenciadorEventos()
{
}

GerenciadorEventos* Gerenciadores::GerenciadorEventos::getGerEvent()
{
	if (pGerEvent == NULL)
	{
		pGerEvent = new GerenciadorEventos();
	}
	return pGerEvent;
}

void Gerenciadores::GerenciadorEventos::checaTeclaApertada(sf::Keyboard::Key key)
{
	switch(key) 
	{
	case (sf::Keyboard::A) :
        pPlayer1->setDirection(left);
		pPlayer1->move();
		break;
	case (sf::Keyboard::D) :
        pPlayer1->setDirection(right);
		pPlayer1->move();
		break;
	case (sf::Keyboard::W) :
		pPlayer1->jump();
		break;
	case (sf::Keyboard::Left) :
		pPlayer2->move();
		break;
	case (sf::Keyboard::Right) :
		pPlayer2->move();
		break;
	case (sf::Keyboard::Up) :
		pPlayer2->jump();
		break;
	case (sf::Keyboard::Escape) :
		close();
		break;
	default:
		break;
	}

}

void Gerenciadores::GerenciadorEventos::checaTeclaSolta(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::A || key == sf::Keyboard::D) 
	{
		pPlayer1->stopMoving();
	}
	else if (key == sf::Keyboard::Left || key == sf::Keyboard::Right)
	{
		pPlayer2->stopMoving();
	}
}

void Gerenciadores::GerenciadorEventos::executar() {
    sf::Event evento;

    while (pWindow->pollEvent(evento)) {
        switch (evento.type) {
            case (sf::Event::Closed) :
                close();
                break;
            case (sf::Event::KeyPressed) :
                checaTeclaApertada(evento.key.code);
                break;
            case (sf::Event::KeyReleased) :
                checaTeclaSolta(evento.key.code);
                break;
			default:
				continue;
        }

    }
}