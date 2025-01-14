#include "../include/PrimeiraFase.h"
using namespace Fases;
PrimeiraFase::PrimeiraFase(States::StateMachine* pSm) :
	Fase(pSm)
{
		LerArquivo();
    	CriarObstaculo();
    	CriarInimigos();
}
PrimeiraFase::~PrimeiraFase(){

}
void PrimeiraFase::CriarInimigosM(){
	int aux=0;
		int tamanho=fase[fase.size()-1].first;
		int comeco=0;
		int coluna=0;
		int numeromin=0;
		vector<Vector2i> variaveis;
		while(aux<=tamanho){
				std::string stingAuxLinha= fase[aux].second;
				for(int i=0;i<stingAuxLinha.length();i++){
						if(stingAuxLinha[i]=='7'){
										comeco=i;
										coluna=aux;
										variaveis.push_back(Vector2i(coluna,comeco));
									}
							}
						aux++;
			}
		for(auto x : variaveis){
				if(rand()%10<3 || numeromin<3){
					lista.addEntity(new Entidades::Personagens::Inimigo::Aranhas(Vector2f(x.y*10,x.x*35),player1));
					numeromin++;
				}
		}
}
void PrimeiraFase::CriarObstMedios(){
		int aux=0;
		int tamanho=fase[fase.size()-1].first;
		int comeco=0;
		int finalz=0;
		int coluna=0;
		int numeromin=0;
		vector<Vector3i> variaveis;
		while(aux<=tamanho){
				std::string stingAuxLinha= fase[aux].second;
				for(int i=0;i<stingAuxLinha.length();i++){
						if(stingAuxLinha[i]=='2' && stingAuxLinha[i+1]=='2'){
										comeco=i;
										for(int j=i+1;j<stingAuxLinha.length();j++){
												if(stingAuxLinha[j]!='2'){
														i=j;
														finalz=j;
														coluna=aux;
														variaveis.push_back(Vector3i(coluna,comeco,finalz));
														break;
												}
										}
						}
				}
								aux++;
		}
		for(auto x : variaveis){
				if(rand()%10<3 || numeromin<3){
					lista.addEntity(new Entidades::Obstaculos::Teia(Vector2f(x.y*10,x.x*35),Vector2f((x.z-x.y)*10,50)));
					numeromin++;
				}
		}

}
void PrimeiraFase::CriarObstaculo(){
		CriarPlataforma();
		CriarObstMedios();
}
void PrimeiraFase::CriarInimigos(){
		CriarInimigosF();
		CriarInimigosM();
}
bool PrimeiraFase::LerArquivo(){
	FILE *T;
	T=fopen("fase1.txt","r");
	try {
    if (T == nullptr) {
        	throw std::runtime_error("Erro ao inicializar fase: arquivo é nulo.");
    }
    TratarArquivo(T);
    fclose(T);
    return true;
	} catch (const std::exception& e) {
    std::cerr << "Exceção capturada: " << e.what() << std::endl;
    if (T != nullptr) {
        fclose(T); // Fecha o arquivo caso tenha sido aberto.
    }
    return false;
	}
}
