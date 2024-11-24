#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
namespace Gerenciador{
	class Janela{
			private:
					sf::RenderWindow window; //criação do objeto window
					sf::Vector2u tamanho; //vetor para o tamnaho da tela
					std::string nome; //nome da tela 
					bool fullscreen; //modo fullscrean, nao e importante
					bool acabou; //verificacao se foi fechada
					const int fps_limited; //limite de fps
					std::vector<std::pair<int,sf::Drawable*>> figuras; //faz um vector de figuras 
			public:
					Janela(const std::string &titulo,const sf::Vector2u &tam); //Criação da tela com o nome e string *REFERENCIA ESCONDIDA*
					~Janela(); //destrutor
					void Limpa(); // tela preta 
					void Desenha(); // display
					void Desenha_Objt(); //draw
					void Adiciona_Objt(sf::Drawable *algo,const int camada);//Adiciona por camadas o que vai aparecer 
					void Update(); // verifica se F5 foi clicado e se foi clicado pra fechar
					void TrocaFullscreen(); // inverte o valor de fullscreeni (bool) 
					bool IsFullscreen(){return fullscreen;}
					bool Acabou(){return acabou;}
					sf::Vector2u GetJanela(){return tamanho;}; 
					void setNome(const std::string &titulo); // Mudar de nome
					void setTamnho(sf::Vector2u *tam); //Mudar tamanho
	};
}
