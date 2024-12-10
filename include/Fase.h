#pragma once 
#include "GerenciadorColisoes.h"
#include "listEntidade.h"
#include "Plataforma.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
namespace Fases{
		class Fase{
				private:
				//	Gerenciadores::GerenciadorColisoes ColMngr; 
				public:
					Fase();
					virtual ~Fase();
					virtual void executar();
					void Gerenciar_colisoes();
					void CriarInimigosF();
					void CriarInimigosM();
					void CriarInimigosD();
					void CriarPlataforma(std::vector<std::pair<int,std::string>> Num_Fase);
					virtual void CriarInimigos();
					virtual void CriarObstaculo();
					void CriarCenario();
					bool LerArquivo();
					void TratarArquivo(FILE *T);
		};
}
