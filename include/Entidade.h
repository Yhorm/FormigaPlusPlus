#pragma once
#include <iostream>
#include "Ente.h"
#include "ID.h"

using namespace std;

namespace Entidades
{
	class Entidade : public Ente
	{
	protected:
        const Identifier::ID ID;
		sf::RectangleShape entity;
        sf::Vector2f curPos;
        sf::Vector2f entitySize;


	public:
		Entidade(Vector2f pos, Vector2f size, const Identifier::ID i = Identifier::ID::none);
		virtual ~Entidade();

		void setPosition(Vector2f pos) { entity.setPosition(pos); this->curPos = pos; }
		void setSize(Vector2f size) { entity.setSize(size); this->entitySize = size; }

		const Vector2f getPosition() const { return curPos; }
		const Vector2f getEntSize() const { return entitySize; }


		void draw() { pGerGraf->draw(entity); }
		virtual void refresh() = 0;
        virtual void colision(Entidades::Entidade* entity, sf::Vector2f distance) = 0;
        const Identifier::ID getId() const {return ID;}
	};
}
using namespace Entidades;
