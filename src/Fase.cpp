#include "../include/Fase.h"
using namespace Fases;

Fase::Fase(States::StateMachine* pSm, States::StateType faseAtual):
		States::State(pSm, faseAtual),
		player1(new Entidades::Personagens::Jogador(sf::Vector2f(2200.0f, 100.0f))),
		lista(),
		ColMngr(&lista,player1)
		{
				textura = pGerGraf->getTexture(Constants::SCENERY_TEXTURE_FILE_PATH);
				textura->setRepeated(true);
				textura->setSmooth(false);
  				sprite.setTexture(*textura);
				sprite.setTextureRect(sf::IntRect(0, 0, 3000000, 3000000));
				sprite.setPosition(-900,-900);
				fase.clear();
				lista.addEntity(player1);
			
		}
		
Fase::~Fase()
{
		fase.clear();
		player1=nullptr;
}
void Fase::executar()
{
		lista.execute();
}
void Fase::Gerenciar_colisoes()
{
		ColMngr.execute();
}


void Fase::TratarArquivo(FILE *T)
{
		char buffer[1024];
		int i=0;
		while(fgets(buffer,sizeof(buffer),T))
		{
			std::string linha(buffer);
			fase.push_back(make_pair(i++,linha));	
		}
}
void Fase::CriarCenario(){
	pGerGraf->draw(sprite);
}
void Fase::CriarPlataforma()
{
		int aux=0;
		int tamanho=fase[fase.size()-1].first;
		int comeco=0;
		int finalz=0;
		int coluna=0;
		vector<Vector3i> variaveis;
		while(aux<=tamanho)
		{
				std::string stingAuxLinha= fase[aux].second;
				for(int i=0;i<stingAuxLinha.length();i++)
				{
						if(stingAuxLinha[i]=='1' && stingAuxLinha[i+1]=='1')
						{
										comeco=i;
										for(int j=i+1;j<stingAuxLinha.length();j++)
										{
												if(stingAuxLinha[j]!='1')
												{
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
		for(auto x : variaveis)
		{
				lista.addEntity(new Entidades::Obstaculos::Plataforma(Vector2f(x.y*10,x.x*35),Vector2f((x.z-x.y)*10,50)));
		}
}

void Fase::CriarInimigosF()
{
		int aux=0;
		int tamanho=fase[fase.size()-1].first;
		int comeco=0;
		int coluna=0;
		int numeromin=0;
		vector<Vector2i> variaveis;
		while(aux<=tamanho)
		{
			std::string stingAuxLinha= fase[aux].second;
			for(int i=0;i<stingAuxLinha.length();i++)
			{
					if(stingAuxLinha[i]=='6')
					{
						comeco=i;
						coluna=aux;
						variaveis.push_back(Vector2i(coluna,comeco));
					}
			}
			aux++;
		}
		for(auto x : variaveis)
		{
				if(rand()%10<3 || numeromin<3)
				{
					lista.addEntity(new Entidades::Personagens::Inimigo::Pulgas(Vector2f(x.y*10,x.x*35),player1));
					numeromin++;
				}
		}

}

void Fase::draw() 
{
	CriarCenario();
	executar();
	Gerenciar_colisoes();
}
void Fase::refresh(){

}
void Fase::update() {}

void Fase::resetState() {}
