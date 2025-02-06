#pragma once 
#include "Fase.h"
namespace Fases{
		class SaveFase: public Fase
		{
			public:
			SaveFase(States::StateMachine* pSm);
			~SaveFase();
			void CriarInimigos(){};
			void CriarObstaculo(){};
			bool LerArquivo(){return true;};
			bool recuperar();
		};
}
