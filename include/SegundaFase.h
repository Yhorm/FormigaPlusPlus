#pragma once 
#include "Fase.h"
namespace Fases{
		class SegundaFase : public Fase
		{
			private:
			Entidades::Projetil::Projetil *proje;
			public:
			SegundaFase();
			~SegundaFase();
			void CriarProjetil();
			void CriarInimigosD();
			void CriarObstDificeis();
			void CriarObstaculo();
			void CriarInimigos();
			bool LerArquivo();
		};
}
