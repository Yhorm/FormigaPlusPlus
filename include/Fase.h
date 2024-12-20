#pragma once 
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "listEntidade.h"
#include "GerenciadorGrafico.h"
#include "Plataforma.h"
#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
namespace Fases{
		class Fase{
				private:
				Entidades::Personagens::Jogador *player1;
				Gerenciadores::GerenciadorColisoes ColMngr; 
				Listas::listEntidade lista;
				vector <pair<int,string>> fase;
				public:
					Fase();
					virtual ~Fase();
					virtual void executar();
					void Gerenciar_colisoes();
					void CriarInimigosF();
					void CriarInimigosM();
					void CriarInimigosD();
					void CriarPlataforma();
					virtual void CriarInimigos();
					virtual void CriarObstaculo();
					void CriarCenario();
					bool LerArquivo();
					void TratarArquivo(FILE *T);
					Entidades::Personagens::Jogador* getPlayer(){return player1;};
		};
}
