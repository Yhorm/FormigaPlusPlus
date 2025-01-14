#pragma once 
#include "GerenciadorColisoes.h"
#include "Projetil.h"
#include "Jogador.h"
#include "listEntidade.h"
#include "Aranhas.h"
#include "GerenciadorGrafico.h"
#include "Plataforma.h"
#include "Pulgas.h"
#include "Teia.h"
#include "Joaninha.h"
#include "Espinhos.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
namespace Fases{
		class Fase{
				protected:
				Entidades::Personagens::Jogador *player1;
				Gerenciadores::GerenciadorColisoes ColMngr; 
				Listas::listEntidade lista;

				Entidades::Projetil::Projetil *proje;
				vector <pair<int,string>> fase;
				public:
					Fase();
					virtual ~Fase();
					virtual void executar();
					void Gerenciar_colisoes();
					void CriarInimigosF();
					void CriarInimigosD();
					void CriarPlataforma();
					virtual void CriarInimigos()=0;
					virtual void CriarObstaculo()=0;
					void CriarCenario();
					virtual bool LerArquivo()=0;
					void TratarArquivo(FILE *T);
					Entidades::Personagens::Jogador* getPlayer(){return player1;};
		};
}
