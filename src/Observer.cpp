#include "../include/Observer.h"

using namespace Observers;

Observer::Observer() :
    pEventos(pEventos->getGerEvent())
{
}

Observer::~Observer()
{
    pEventos = nullptr;
}