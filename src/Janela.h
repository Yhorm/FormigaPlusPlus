#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
class Janela{
		private:
				sf::RenderWindow window;
				sf::Vector2u tamanho;
				std::string nome;
				bool fullscreen;
				bool acabou;
				const int fps_limited;
		public:
				Janela(const std::string& titulo,const sf::Vector2u &tam);
				~Janela();
				void Limpa();
				void Desenha();
				void Desenha_Objt(sf::Drawable& algo);
				void Update();
				void TrocaFullscreen(); 
				bool IsFullscreen(){return fullscreen;}
				bool Acabou(){return acabou;}
				sf::Vector2u GetJanela(){return tamanho;}; 
};
