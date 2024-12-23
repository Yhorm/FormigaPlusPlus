#include "../include/Observer.h"
#include "../include/GerenciadorEventos.h"


GerenciadorEventos* Gerenciadores::GerenciadorEventos::pGerEvent(nullptr);

Gerenciadores::GerenciadorEventos::GerenciadorEventos() :
	pGerGraf(pGerGraf->getGerGraf()),
	//pPlayer1(nullptr),
	//pPlayer2(nullptr),
	//pMenu(nullptr),
	pWindow(pGerGraf->getWindow())
{
		keyMap[sf::Keyboard::A] = "A";
        keyMap[sf::Keyboard::B] = "B";
        keyMap[sf::Keyboard::C] = "C";
        keyMap[sf::Keyboard::D] = "D";
        keyMap[sf::Keyboard::E] = "E";
        keyMap[sf::Keyboard::F] = "F";
        keyMap[sf::Keyboard::G] = "G";
        keyMap[sf::Keyboard::H] = "H";
        keyMap[sf::Keyboard::I] = "I";
        keyMap[sf::Keyboard::J] = "J";
        keyMap[sf::Keyboard::K] = "K";
        keyMap[sf::Keyboard::L] = "L";
        keyMap[sf::Keyboard::M] = "M";
        keyMap[sf::Keyboard::N] = "N";
        keyMap[sf::Keyboard::O] = "O";
        keyMap[sf::Keyboard::P] = "P";
        keyMap[sf::Keyboard::Q] = "Q";
        keyMap[sf::Keyboard::R] = "R";
        keyMap[sf::Keyboard::S] = "S";
        keyMap[sf::Keyboard::T] = "T";
        keyMap[sf::Keyboard::U] = "U";
        keyMap[sf::Keyboard::V] = "V";
        keyMap[sf::Keyboard::W] = "W";
        keyMap[sf::Keyboard::X] = "X";
        keyMap[sf::Keyboard::Y] = "Y";
        keyMap[sf::Keyboard::Z] = "Z";
        keyMap[sf::Keyboard::Num1] = "1";
        keyMap[sf::Keyboard::Num2] = "2";
        keyMap[sf::Keyboard::Num3] = "3";
        keyMap[sf::Keyboard::Num4] = "4";
        keyMap[sf::Keyboard::Num5] = "5";
        keyMap[sf::Keyboard::Num6] = "6";
        keyMap[sf::Keyboard::Num7] = "7";
        keyMap[sf::Keyboard::Num8] = "8";
        keyMap[sf::Keyboard::Num9] = "9";
        keyMap[sf::Keyboard::Num0] = "0";
        keyMap[sf::Keyboard::Numpad0] = "0";
        keyMap[sf::Keyboard::Numpad1] = "1";
        keyMap[sf::Keyboard::Numpad2] = "2";
        keyMap[sf::Keyboard::Numpad3] = "3";
        keyMap[sf::Keyboard::Numpad4] = "4";
        keyMap[sf::Keyboard::Numpad5] = "5";
        keyMap[sf::Keyboard::Numpad6] = "6";
        keyMap[sf::Keyboard::Numpad7] = "7";
        keyMap[sf::Keyboard::Numpad8] = "8";
        keyMap[sf::Keyboard::Numpad9] = "9";
        keyMap[sf::Keyboard::Space] = "Space";
        keyMap[sf::Keyboard::Enter] = "Enter";
        keyMap[sf::Keyboard::Escape] = "Escape";
        keyMap[sf::Keyboard::BackSpace] = "BackSpace";
        keyMap[sf::Keyboard::Right] = "Right";
        keyMap[sf::Keyboard::Left] = "Left";
        keyMap[sf::Keyboard::Up] = "Up";
        keyMap[sf::Keyboard::Down] = "Down";
        keyMap[sf::Keyboard::LShift] = "Shift";
        keyMap[sf::Keyboard::Tab] = "Tab";
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
	/*
	if(pPlayer1){
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
		default:
			break;
		}
	}
	if(pPlayer2){
		switch(key) 
		{
		case (sf::Keyboard::Left) :
			pPlayer2->setDirection(left);
			pPlayer2->move();
			break;
		case (sf::Keyboard::Right) :
			pPlayer2->setDirection(right);
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
	*/
	for(iterador = observadores.begin(); iterador != observadores.end(); ++iterador)
	{
		(*iterador)->notifyKeyPress(getKeyAsString(key));
	}
}

void Gerenciadores::GerenciadorEventos::checaTeclaSolta(sf::Keyboard::Key key)
{
	/*
	if(pPlayer1){
		if (key == sf::Keyboard::A || key == sf::Keyboard::D) 
		{
			pPlayer1->stopMoving();
		}
	}
	if(pPlayer2){
		if (key == sf::Keyboard::Left || key == sf::Keyboard::Right)
			{
				pPlayer2->stopMoving();
			}
	}
	*/

	for(iterador = observadores.begin(); iterador != observadores.end(); ++iterador)
	{
		(*iterador)->notifyKeyReleased(getKeyAsString(key));
	}
}

void Gerenciadores::GerenciadorEventos::executar() {
    sf::Event evento;

    while (pWindow->pollEvent(evento)) {
        switch (evento.type) 
		{
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
