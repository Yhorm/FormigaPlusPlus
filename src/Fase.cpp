#include "../include/Fase.h"
#include <vector>
using namespace Fases;
Fase::Fase(){
}
Fase::~Fase(){
}
void Fase::executar(){
}
void Fase::CriarInimigos(){
}
void Fase::CriarObstaculo(){
}
bool Fase::LerArquivo(){
	FILE *T;
	T=fopen("fase.txt","r");
	if(T!=nullptr){
		TratarArquivo(T);
		fclose(T);
		return true;
	}
	std::cerr<<"ERRO AO INCIALIZAR FASE"<<std::endl;
	fclose(T);
	return false;
};
void Fase::TratarArquivo(FILE *T){
		char buffer[1024];
		std::vector<pair<int,std::string>> fase;
		int i=0;
		while(fgets(buffer,sizeof(buffer),T)){
			std::string linha(buffer);
			fase.push_back(make_pair(i++,linha));	
		}
		for(auto x : fase)
			std::cout<<x.first<<" "<<x.second;
		CriarPlataforma(fase);
}
void Fase::CriarPlataforma(std::vector<std::pair<int,std::string>> Num_Fase){
		int cont=0;
		int aux=0;
		int tamanho=Num_Fase[Num_Fase.size()-1].first;
		int comeco=0;
		int finalz=0;
		int coluna=0;
		int linha=0;
		vector<Vector3i> variaveis;
		while(aux<=tamanho){
				std::string stingAuxLinha= Num_Fase[aux].second;
				for(int i=0;i<stingAuxLinha.length();i++){
						if(stingAuxLinha[i]=='1'){
								if(stingAuxLinha[i+1]=='1'){
										comeco=i;
										for(int j=i+1;j<stingAuxLinha.length();j++){
												if(stingAuxLinha[j]!='1'){
														i=j;
														finalz=j;
														coluna=aux;
														variaveis.push_back(Vector3i(coluna,comeco,finalz));
												}
										}
								}
						}
						if(stingAuxLinha[i]=='1'){
								if(Num_Fase[aux+1].second[i]=='1'){
										comeco=aux;
										for(int j=aux+1;j<tamanho;j++){
												if(Num_Fase[j].second[i]!='1'){
														finalz=j;
														linha=i;
														variaveis.push_back(Vector3i(linha,comeco,finalz));
												}
										}
								}
						}
				}
								aux++;
		}
		for(auto x : variaveis){
				cout<<x.x<<" "<<x.y<<" "<<x.z<<endl;
		}
}
