#include "../include/SegundaFase.h"
using namespace Fases;
SegundaFase::SegundaFase(States::StateMachine* pSm) :
	Fase(pSm, States::StateType::STATE_FASE_2)
{
		CriarCenario();
		LerArquivo();
		CriarProjetil();
    	CriarObstaculo();
    	CriarInimigos();
}
SegundaFase::~SegundaFase(){

}
void SegundaFase::CriarProjetil(){
		proje=new Entidades::Projetil::Projetil(Vector2f(0,0),player1);
		lista.addEntity(proje);
}
void SegundaFase::CriarInimigosD(){
		int aux=0;
		int tamanho=fase[fase.size()-1].first;
		int comeco=0;
		int coluna=0;
		int numeromin=0;
		vector<Vector2i> variaveis;
		while(aux<=tamanho){
				std::string stingAuxLinha= fase[aux].second;
				for(int i=0;i<stingAuxLinha.length();i++){
						if(stingAuxLinha[i]=='8'){
										comeco=i;
										coluna=aux;
										variaveis.push_back(Vector2i(coluna,comeco));
									}
							}
						aux++;
			}
		for(auto x : variaveis){
				if(rand()%10<3 || numeromin<3){
					lista.addEntity(new Entidades::Personagens::Inimigo::Joaninha(Vector2f(x.y*10,x.x*35),Vector2f(100,100),player1,proje));
					numeromin++;
				}
		}
}
void SegundaFase::CriarObstDificeis(){
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
						if(stingAuxLinha[i]=='3' && stingAuxLinha[i+1]=='3'){
										comeco=i;
										for(int j=i+1;j<stingAuxLinha.length();j++){
												if(stingAuxLinha[j]!='3'){
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
					lista.addEntity(new Entidades::Obstaculos::Espinhos(Vector2f(x.y*10,x.x*35),Vector2f((x.z-x.y)*10,50)));
					numeromin++;
				}
		}
}
void SegundaFase::CriarObstaculo(){
		CriarPlataforma();
		CriarObstDificeis();
}
void SegundaFase::CriarInimigos(){
		CriarInimigosF();
		CriarInimigosD();
}
bool SegundaFase::LerArquivo(){
	FILE *T;
	T=fopen("fase2.txt","r");
	try {
    if (T == nullptr) {
        	throw std::runtime_error("Erro ao inicializar fase: arquivo é nulo.");
			return false;
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
