#include "../include/Entidade.h"

Entidades::Entidade::Entidade(Vector2f pos, Vector2f size, const Identifier::ID i) :
	entity(RectangleShape(size)),
    ID(i),
    curPos(pos),
 	previous(0),
	animation(0),
    timer(),
   entitySize(size)
{
    setPosition(pos);
}

Entidades::Entidade::~Entidade()
{
}
