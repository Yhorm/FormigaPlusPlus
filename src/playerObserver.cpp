#include "../include/playerObserver.h"
#include "../include/Jogador.h"

Observers::playerObserver::playerObserver(Entidades::Personagens::Jogador* pP) :
    Observer(),
    pPlayer(pP),
    jump("W"),
    left("A"),
    right("D"),
    keysPressed()
{
    setKeys();
    keysPressed.insert(std::pair<std::string, bool>(jump, false));
    keysPressed.insert(std::pair<std::string, bool>(right, false));
    keysPressed.insert(std::pair<std::string, bool>(left, false));
}

Observers::playerObserver::~playerObserver()
{
    pPlayer = nullptr;
}

void Observers::playerObserver::notifyKeyPress(std::string key)
{
    if(pPlayer == nullptr)
    {
        std:: cout << "Erro: Pplayer1 é nulo em playerObserver." << endl;
        exit(1);
    }

    if(key == jump)
    {
       keysPressed[jump] = true;
        pPlayer->jump();
    }


    if(key == left)
    {
        keysPressed[left] = true;
        pPlayer->move();
        pPlayer->setDirection(1);
    }
    if(key == right)
    {
        keysPressed[right] = true;
        pPlayer->move();
        pPlayer->setDirection(2);
    }

}

void Observers::playerObserver::notifyKeyReleased(std::string key)
{
    if(pPlayer == nullptr )
    {
        std:: cout << "Erro: pPlayer é nulo em playerObserver." << endl;
        exit(1);
    }

    if(key == jump)
    {
        keysPressed[jump] = false;
            
    }
    if(key == left)
    {
        keysPressed[left] = false;
        pPlayer->stopMoving();
    }
    if(key == right)
    {
        keysPressed[right] = false;
        pPlayer->stopMoving();
    }
}

void Observers::playerObserver::setKeys()
{
    if(pPlayer->getPlayer2() == true)
    {
        this->jump = "Up";
        this->left = "Left";
        this->right = "Right";
    }

    else

    {
        this->jump = "W";
        this->left = "A";
        this->right = "D";
    }
}
void Observers::playerObserver::setKeys(std::string jmp, std::string l, std::string r)
{
    this->jump = jmp;
    this->left = l;
    this->right = r;
}
