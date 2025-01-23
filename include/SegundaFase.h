#pragma once 
#include "Fase.h"
namespace Fases{
		class SegundaFase : public Fase
		{
			public:
			SegundaFase(States::StateMachine* pSm);
			~SegundaFase();
			void CriarProjetil();
			void CriarInimigosD();
			void CriarObstDificeis();
			void CriarObstaculo();
			void CriarInimigos();
			bool LerArquivo();
		};
}
