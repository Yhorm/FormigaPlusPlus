#include "../include/playerObserver.h"

using namespace Observers;

playerObserver::playerObserver(Entidades::Personagens::Jogador* pP1, Entidades::Personagens::Jogador* pP2) :
    Observer(),
    pPlayer1(pP1),
    pPlayer2(pP2),
    jump1("W"),
    left1("A"),
    right1("D"),
    jump2("Up"),
    left2("Left"),
    right2("Right"),
    keysPressed()
{
    keysPressed.insert(std::pair<std::string, bool>(jump1, false));
    keysPressed.insert(std::pair<std::string, bool>(right1, false));
    keysPressed.insert(std::pair<std::string, bool>(left1, false));
    keysPressed.insert(std::pair<std::string, bool>(jump1, false));
    keysPressed.insert(std::pair<std::string, bool>(right1, false));
    keysPressed.insert(std::pair<std::string, bool>(left1, false));
}

playerObserver::~playerObserver()
{
    pPlayer1 = nullptr;
    pPlayer2 = nullptr;
}


void playerObserver::notifyKeyPress(std::string key)
{
    if(pPlayer1 == nullptr)
    {
        std:: cout << "Erro: Pplayer1 é nulo em playerObserver." << endl;
        exit(1);
    }

    if(pPlayer2 == nullptr)
    {
        std:: cout << "Erro: Pplayer2 é nulo em playerObserver." << endl;
        exit(1);
    }

    if(pPlayer1)
    {

        if(key == jump1)
        {
            keysPressed[jump1] = true;
            pPlayer1->jump();
        }


        if(key == left1)
        {
            keysPressed[left1] = true;
            pPlayer1->move();
            pPlayer1->setDirection(1);
        }
        if(key == right1)
        {
            keysPressed[right1] = true;
            pPlayer1->move();
            pPlayer1->setDirection(2);
        }

    }

    if(pPlayer2)
    {
        if(key == jump2)
        {
            keysPressed[jump2] = true;
            pPlayer2->jump();
        }


        if(key == left2)
        {
            keysPressed[left2] = true;
            pPlayer2->move();
            pPlayer2->setDirection(1);
        }
        if(key == right2)
        {
            keysPressed[right2] = true;
            pPlayer2->move();
            pPlayer2->setDirection(2);
        }
    }

    
}

void playerObserver::notifyKeyReleased(std::string key)
{
    if(pPlayer1 == nullptr || pPlayer2 == nullptr)
    {
        std:: cout << "Erro: pPlayer1 ou pPlayer2 é nulo em playerObserver." << endl;
        exit(1);
    }

    if(pPlayer1)
    {
        if(key == jump1)
        {
            keysPressed[jump1] = false;
            
        }
        if(key == left1)
        {
            keysPressed[left1] = false;
            pPlayer1->stopMoving();
        }
        if(key == right1)
        {
            keysPressed[right1] = false;
            pPlayer1->stopMoving();
        }
    }

    if(pPlayer2)
    {
        if(key == jump2)
        {
            keysPressed[jump2] = false;
            
        }
        if(key == left2)
        {
            keysPressed[left2] = false;
            pPlayer2->stopMoving();
        }
        if(key == right2)
        {
            keysPressed[right2] = false;
            pPlayer2->stopMoving();
        }
    }
}

void playerObserver::setKeysP1(std::string jmp, std::string l, std::string r)
{
    this->jump1 = jmp;
    this->left1 = l;
    this->right1 = r;
}

void playerObserver::setKeysP2(std::string jmp, std::string l, std::string r)
{
    this->jump2 = jmp;
    this->left2 = l;
    this->right2 = r;
}