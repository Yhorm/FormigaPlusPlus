#pragma once 
#include "Fase.h"
namespace Fases{
		class PrimeiraFase : public Fase
		{
			public:
			PrimeiraFase(States::StateMachine* pSm);
			~PrimeiraFase();
			void CriarInimigosM();
			void CriarObstMedios();
			void CriarObstaculo();
			void CriarInimigos();
			bool LerArquivo();
		};
}
