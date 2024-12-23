#include "../include/Observer.h"


Observers::Observer::Observer(Gerenciadores::GerenciadorEventos* event) :
    pEventos(event->getGerEvent())
{
    pEventos->attach(this);
}

Observers::Observer::~Observer()
{
    pEventos = nullptr;
}