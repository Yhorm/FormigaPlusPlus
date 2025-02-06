#include "../include/SaveFase.h"
using namespace Fases;
SaveFase::SaveFase(States::StateMachine* pSm) :
	Fase(pSm, States::StateType::STATE_SAVE_FASE)
{
			CriarCenario();	
}
bool SaveFase::recuperar(){
		if(fopen("save.txt","r")){
			ifstream input("save.txt");
			string linha;
			while(getline(input,linha)){
					std::stringstream ss(linha);
					string s;
					vector<float> valores;
					Personagens::Inimigo::Pulgas *pulgaAux=nullptr;
					Personagens::Inimigo::Aranhas *aranhaAux=nullptr;
					Personagens::Inimigo::Joaninha *JoaninhaAux=nullptr;
					while(getline(ss,s,',')){
							valores.push_back(stof(s));
					}
					switch((int)valores[0]){
							case 0:
				player1->setPosition(Vector2f(valores[5],valores[6]));
				player1->setHP(valores[7]);
				lista.addEntity(player1);
									break;
							case 1:
				lista.addEntity(new Entidades::Obstaculos::Plataforma(Vector2f(valores[1],valores[2]),Vector2f(valores[3],valores[4])));
									break;
							case 2:
				lista.addEntity(new Entidades::Obstaculos::Teia(Vector2f(valores[1],valores[2]),Vector2f(valores[3],valores[4])));
									break;
							case 3:
				lista.addEntity(new Entidades::Obstaculos::Espinhos(Vector2f(valores[1],valores[2]),Vector2f(valores[3],valores[4])));
									break;
							case 4:
				proje=new Entidades::Projetil::Projetil(Vector2f(0,0),player1);
				if(valores[3])
						proje->fire(Vector2f(valores[1],valores[2]));
				lista.addEntity(proje);
									break;
							case 6:
				pulgaAux= new Personagens::Inimigo::Pulgas(Vector2f(valores[1],valores[2]),player1);
				pulgaAux->setPosition(Vector2f(valores[5],valores[6]));
				pulgaAux->setHP(valores[7]);
				lista.addEntity(pulgaAux);
									break;
							case 7:
				aranhaAux= new Personagens::Inimigo::Aranhas(Vector2f(valores[1],valores[2]),player1);
				aranhaAux->setPosition(Vector2f(valores[5],valores[6]));
				aranhaAux->setHP(valores[7]);
				lista.addEntity(aranhaAux);
									break;
							case 8:
				JoaninhaAux= new Personagens::Inimigo::Joaninha(Vector2f(valores[1],valores[2]),Vector2f(valores[3],valores[4]),player1,proje);
				JoaninhaAux->setPosition(Vector2f(valores[5],valores[6]));
				JoaninhaAux->setHP(valores[7]);
				lista.addEntity(JoaninhaAux);
									break;
							default:
									cerr<<"error carregar";
					}
			}		
		return true;
	}
return false;
}

SaveFase::~SaveFase(){

}
