#include "../include/Observer.h"


Observers::Observer::Observer() :
    pEventos(pEventos->getGerEvent())
{
    pEventos->attach(this);
}

Observers::Observer::~Observer()
{
    pEventos->detach(this);
}