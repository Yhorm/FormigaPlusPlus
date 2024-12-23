#include "../include/playerObserver.h"
#include "../include/Jogador.h"

Observers::playerObserver::playerObserver(Gerenciadores::GerenciadorEventos* pGm, Entidades::Personagens::Jogador* pP) :
    Observer(pGm),
    pPlayer(pP),
    jump("W"),
    left("A"),
    right("D"),
    keysPressed()
{
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

void Observers::playerObserver::setKeys(std::string jmp, std::string l, std::string r)
{
    this->jump = jmp;
    this->left = l;
    this->right = r;
}
